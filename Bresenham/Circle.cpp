#include <cmath>
#include "Circle.h"

// 局部辅助函数的声明
int max(int a, int b);



// 构造一个圆形
Circle::Circle(Point<int> center, int radius) 
    : mCenter(center), mRadius(radius) {
    mNumOfPoints = 0;
    // 设置为未初始化
    mIsInit = false;
    mProgram = 0;
}

Circle::~Circle() {
}

// 初始化待绘制的圆形，必须在draw函数调用前调用
void Circle::init() {
    if (!mIsInit) {
        ShaderInfo shaders[] {
            { GL_VERTEX_SHADER, "circle.vert" },
            { GL_FRAGMENT_SHADER, "circle.frag" },
            { GL_NONE, NULL }
        };

        mProgram = LoadShaders(shaders);
        glUseProgram(mProgram);

        initCenter();
        initPoints();
        // 设置为已初始化
        mIsInit = true;
    }
}

// 绘制出和这个圆形，如果init函数未被调用，则调用
void Circle::draw() {
    if (!mIsInit) {
        init();
    }
    drawCenter();
    drawPoints();
}


// 辅助函数
void Circle::initCenter() {
    glGenVertexArrays(1, &mVAOID[GraphicName::CIRCLE_CENTER]);
    glBindVertexArray(mVAOID[GraphicName::CIRCLE_CENTER]);

    glGenBuffers(1, &mBufferID[GraphicName::CIRCLE_CENTER]);
    glBindBuffer(GL_ARRAY_BUFFER, mBufferID[GraphicName::CIRCLE_CENTER]);

    glBufferData(GL_ARRAY_BUFFER, 1 * 3 * sizeof(GLint), &mCenter, GL_STATIC_DRAW);

    glUniform1f(glGetUniformLocation(mProgram, "maxCoorAbs"), mRadius + max(abs(mCenter.x), abs(mCenter.y)));

    glVertexAttribPointer(layout_vPosition, 3, GL_INT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(layout_vPosition);

    // 获取片元着色器中为圆心着色的子例程
    mSubRoutine[GraphicName::CIRCLE_CENTER] =
        glGetSubroutineIndex(mProgram, GL_FRAGMENT_SHADER, "processCenter");
}

void Circle::initPoints() {
    glGenVertexArrays(1, &mVAOID[GraphicName::CIRCLE_POINTS]);
    glBindVertexArray(mVAOID[GraphicName::CIRCLE_POINTS]);

    mNumOfPoints = 0;
    Point<GLint> *circlePoints = drawCircleBresenham(mCenter.x, mCenter.y, mRadius, mNumOfPoints);

    glGenBuffers(1, &mBufferID[GraphicName::CIRCLE_POINTS]);
    glBindBuffer(GL_ARRAY_BUFFER, mBufferID[GraphicName::CIRCLE_POINTS]);

    glBufferData(GL_ARRAY_BUFFER, mNumOfPoints * 3 * sizeof(GLint), circlePoints, GL_STATIC_DRAW);

    delete[] circlePoints;

    glVertexAttribPointer(layout_vPosition, 3, GL_INT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(layout_vPosition);

    // 获取片元着色器中为圆上的点着色的子例程
    mSubRoutine[GraphicName::CIRCLE_POINTS] =
        glGetSubroutineIndex(mProgram, GL_FRAGMENT_SHADER, "processPoints");
}

void Circle::drawCenter() {
    glBindVertexArray(mVAOID[GraphicName::CIRCLE_CENTER]);
    glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, 1, &mSubRoutine[GraphicName::CIRCLE_CENTER]);
    glDrawArrays(GL_POINTS, 0, 1);
}

void Circle::drawPoints() {
    glBindVertexArray(mVAOID[GraphicName::CIRCLE_POINTS]);
    glUniformSubroutinesuiv(GL_FRAGMENT_SHADER, 1, &mSubRoutine[GraphicName::CIRCLE_POINTS]);
    glDrawArrays(GL_POINTS, 0, mNumOfPoints);
}

// 求两个值中的最大值
int max(int a, int b) {
    return a > b ? a : b;
}
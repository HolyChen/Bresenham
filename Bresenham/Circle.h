#pragma once

#include "IDrawable.h"
#include "Point.h"
#include "DrawCircleAlg.h"
#include "glUtil.h"

class Circle : public IDrawable
{
private:
    // 圆心
    Point<int> mCenter;
    // 半径
    int mRadius;
    // 圆上点的个数
    int mNumOfPoints;
    // -------------- OpenGL 变量 --------------
    static const GLuint NUM_OF_VAO = 2;
    // 顶点数组ID
    GLuint mVAOID[NUM_OF_VAO];
    // 缓冲区ID
    GLuint mBufferID[NUM_OF_VAO];
    // 着色器程序
    GLuint mProgram;
    // 片元着色器子例程ID
    GLuint mSubRoutine[2];


    const GLuint layout_vPosition = 1;
    const GLuint layout_iMaxCoorAbs = 2;

    // 状态控制变量
    bool mIsInit;
    
// 辅助函数
private :
    void initCenter();
    void initPoints();
    void drawCenter();
    void drawPoints();

public:
    // 构造一个圆形
    Circle(Point<int> center, int radius);
    // 初始化待绘制的圆形，必须在draw函数调用前调用
    void init();
    // 绘制出和这个圆形，如果init未被调用，则调用
    void draw();
    ~Circle();

    static enum GraphicName
    {
        CIRCLE_POINTS = 0,
        CIRCLE_CENTER = 1
    };
};


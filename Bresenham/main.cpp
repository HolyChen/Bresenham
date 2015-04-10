#include <iostream>
#include <vector>

#include "IDrawable.h"
#include "DrawCircleAlg.h"
#include "Circle.h"
#include "glUtil.h"

using namespace std;

// 唯一的全局变量，待绘制图形
vector<IDrawable*> graphics;

void init() {
    //设置点的大小，显示更为明显
    glPointSize(2.0f);

    // 初始化每一个图形
    for (auto iter = graphics.begin(); iter != graphics.end(); iter++) {
        (*iter)->init();
    }   
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 设置视口
    glViewport(10, 10, 512, 512);

    //  依次绘制每一个图形
    for (auto iter = graphics.begin(); iter != graphics.end(); iter++) {
        (*iter)->draw();
    }

    glFlush();
}

void initGlut(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitContextVersion(4, 5);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutInitContextFlags(GLUT_DEBUG);
    glutCreateWindow(argv[0]);

    glewExperimental = GL_TRUE;
    if (glewInit()) {
        cerr << "Unable to initialize GLEW ... exiting" << endl;
        exit(EXIT_FAILURE);
    }
}

Circle input() {
    cout << "依此输入圆心横坐标x、纵坐标y，半径r，均要求小于1000，且为整数。" << endl;
    int x, y, r;
    cin >> x >> y >> r;
    return Circle(Point<int>(x, y), r);
}

int main(int argc, char** argv) {
    initGlut(argc, argv);

    Circle circle = input();

    graphics.push_back(&circle);

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}



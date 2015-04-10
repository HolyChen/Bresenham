#include <iostream>
#include <vector>

#include "IDrawable.h"
#include "DrawCircleAlg.h"
#include "Circle.h"
#include "glUtil.h"

using namespace std;

// Ψһ��ȫ�ֱ�����������ͼ��
vector<IDrawable*> graphics;

void init() {
    //���õ�Ĵ�С����ʾ��Ϊ����
    glPointSize(2.0f);

    // ��ʼ��ÿһ��ͼ��
    for (auto iter = graphics.begin(); iter != graphics.end(); iter++) {
        (*iter)->init();
    }   
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // �����ӿ�
    glViewport(10, 10, 512, 512);

    //  ���λ���ÿһ��ͼ��
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
    cout << "��������Բ�ĺ�����x��������y���뾶r����Ҫ��С��1000����Ϊ������" << endl;
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



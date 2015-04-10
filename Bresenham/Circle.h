#pragma once

#include "IDrawable.h"
#include "Point.h"
#include "DrawCircleAlg.h"
#include "glUtil.h"

class Circle : public IDrawable
{
private:
    // Բ��
    Point<int> mCenter;
    // �뾶
    int mRadius;
    // Բ�ϵ�ĸ���
    int mNumOfPoints;
    // -------------- OpenGL ���� --------------
    static const GLuint NUM_OF_VAO = 2;
    // ��������ID
    GLuint mVAOID[NUM_OF_VAO];
    // ������ID
    GLuint mBufferID[NUM_OF_VAO];
    // ��ɫ������
    GLuint mProgram;
    // ƬԪ��ɫ��������ID
    GLuint mSubRoutine[2];


    const GLuint layout_vPosition = 1;
    const GLuint layout_iMaxCoorAbs = 2;

    // ״̬���Ʊ���
    bool mIsInit;
    
// ��������
private :
    void initCenter();
    void initPoints();
    void drawCenter();
    void drawPoints();

public:
    // ����һ��Բ��
    Circle(Point<int> center, int radius);
    // ��ʼ�������Ƶ�Բ�Σ�������draw��������ǰ����
    void init();
    // ���Ƴ������Բ�Σ����initδ�����ã������
    void draw();
    ~Circle();

    static enum GraphicName
    {
        CIRCLE_POINTS = 0,
        CIRCLE_CENTER = 1
    };
};


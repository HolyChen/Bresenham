#pragma once

#include "Point.h"

/*
* ��Բ�㷨�����⡣
*/

// ���뾶ֵ
const int MAX_RADIUS = 1000;

/*
* ʹ��Bresenham�㷨��Բ��
* @param centerX Բ��X����
* @param centerY Բ��Y����
* @param R �뾶���������ֵΪMAX_RADIUS
* @param numOfPoints Բ�ϰ�����ĸ�����ͨ����������ó����������
*
* @return Բ�����еĵ�����꣬����˳��Ϊx0, y0, x1, y1 ... , xn, yn��
*         �������쳣ʱ������nullptr. ��ע�������delete[].
*/
Point<int>* drawCircleBresenham(int centerX, int centerY, int R, int& numOfPoints);
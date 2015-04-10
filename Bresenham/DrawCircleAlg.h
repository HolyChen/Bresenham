#pragma once

#include "Point.h"

/*
* 画圆算法函数库。
*/

// 最大半径值
const int MAX_RADIUS = 1000;

/*
* 使用Bresenham算法画圆。
* @param centerX 圆心X坐标
* @param centerY 圆心Y坐标
* @param R 半径，限制最大值为MAX_RADIUS
* @param numOfPoints 圆上包含点的个数，通过函数计算得出，用于输出
*
* @return 圆上所有的点的坐标，储存顺序为x0, y0, x1, y1 ... , xn, yn。
*         当参数异常时，返回nullptr. 请注意用完后delete[].
*/
Point<int>* drawCircleBresenham(int centerX, int centerY, int R, int& numOfPoints);
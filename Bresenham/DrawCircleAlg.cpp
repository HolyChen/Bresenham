#include "DrawCircleAlg.h"

/*
 * 画圆算法函数库。
 */

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
Point<int>* drawCircleBresenham(int centerX, int centerY, int R, int& numOfPoints) {
    // 半径值过大或过小，非法
    if (R <= 0 || R > MAX_RADIUS) {
        return nullptr;
    }

    // 将圆心放在原点进行计算，最后加偏移量，这里先构造出圆心坐标
    Point<int> center = Point<int>(centerX, centerY);

    // 将圆等分为八份，每一份要画的点为不会超过R
    Point<int>* pointsInAPart = new Point<int>[R];
    int numOfPointsInAPart = 0;

    /* delta为像素中点带入圆函数 f(x, y) = x^2 + y^2 - R^2 的函数值
     * 它表示了点的与圆的关系，大于0则在圆外，小于0则在圆内，等于0则在圆上.
     * 根据两个光栅竖直方向中点坐标与圆的关系（d值），可以判断出在哪里描点。
     * 记di为要描的第i + 1个点时，y_(i)和y_(i-1)的中点的detal值。
     * 当di > 0时，中点在圆外，说明圆弧与下侧点较接近，描点中点下侧；反之中点上侧。
     * 为了避免浮点数运算，将delta乘以4.
     */
    // 这里定义d0，以后的di通过后面的增量算法给出。
    int d = 5 - 4 * R;

    int x = 0, y = R;

    // 设置第一个点的坐标, (0, R)
    pointsInAPart[numOfPointsInAPart++].setXY(x, y);

    // 仅画圆的第一象限的45度上侧部分，即圆的1/8。这里的x增量小于y增量
    for (; x < R && x <= y; x++) {
        if (d < 0) {
            // 中点在圆内，则上侧点离得近
            pointsInAPart[numOfPointsInAPart].setXY(x + 1, y);
            // 加上delta_d * 4, 变为d(i+1)
            d = d + 8 * x + 12;
        } else {
            // 中点在圆外，则下侧点离得近
            pointsInAPart[numOfPointsInAPart].setXY(x + 1, y - 1);
            // 加上delta_d * 4, 变为d(i+1)
            d = d + 8 * x - 8 * y + 20;
            y--;
        }
        numOfPointsInAPart++;
    }

    // 画完了1/8的点，根据对称性画其余部分
    // 首先申请数组容纳所有的点
    numOfPoints = 8 * numOfPointsInAPart;
    Point<int> *points = new Point<int>[numOfPoints];
    int count = 0;

    for (int i = 0; i < numOfPointsInAPart; i++) {
        // I象限
        // 逆时针-1/8
        points[count++].setXY(pointsInAPart[i].y, pointsInAPart[i].x);
        // 设置本身
        points[count++].setXY(pointsInAPart[i].x, pointsInAPart[i].y);

        // II象限
        // 逆时针+1/8
        points[count++].setXY(-(pointsInAPart[i].x), pointsInAPart[i].y);
        // 逆时针+1/8
        points[count++].setXY(-(pointsInAPart[i].y), pointsInAPart[i].x);

        // III象限
        // 逆时针+1/8
        points[count++].setXY(-(pointsInAPart[i].y), -(pointsInAPart[i].x));
        // 逆时针+1/8
        points[count++].setXY(-(pointsInAPart[i].x), -(pointsInAPart[i].y));

        // IV象限
        // 逆时针+1/8
        points[count++].setXY(pointsInAPart[i].x, -(pointsInAPart[i].y));
        // 逆时针+1/8
        points[count++].setXY(pointsInAPart[i].y, -(pointsInAPart[i].x));
    }
    delete[] pointsInAPart;

    // 最后为每一个加上偏移量圆心
    for (int i = 0; i < numOfPoints; i++) {
        points[i] += center;
    }

    return points;
}

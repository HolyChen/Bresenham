#include "DrawCircleAlg.h"

/*
 * ��Բ�㷨�����⡣
 */

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
Point<int>* drawCircleBresenham(int centerX, int centerY, int R, int& numOfPoints) {
    // �뾶ֵ������С���Ƿ�
    if (R <= 0 || R > MAX_RADIUS) {
        return nullptr;
    }

    // ��Բ�ķ���ԭ����м��㣬����ƫ�����������ȹ����Բ������
    Point<int> center = Point<int>(centerX, centerY);

    // ��Բ�ȷ�Ϊ�˷ݣ�ÿһ��Ҫ���ĵ�Ϊ���ᳬ��R
    Point<int>* pointsInAPart = new Point<int>[R];
    int numOfPointsInAPart = 0;

    /* deltaΪ�����е����Բ���� f(x, y) = x^2 + y^2 - R^2 �ĺ���ֵ
     * ����ʾ�˵����Բ�Ĺ�ϵ������0����Բ�⣬С��0����Բ�ڣ�����0����Բ��.
     * ����������դ��ֱ�����е�������Բ�Ĺ�ϵ��dֵ���������жϳ���������㡣
     * ��diΪҪ��ĵ�i + 1����ʱ��y_(i)��y_(i-1)���е��detalֵ��
     * ��di > 0ʱ���е���Բ�⣬˵��Բ�����²��Ͻӽ�������е��²ࣻ��֮�е��ϲࡣ
     * Ϊ�˱��⸡�������㣬��delta����4.
     */
    // ���ﶨ��d0���Ժ��diͨ������������㷨������
    int d = 5 - 4 * R;

    int x = 0, y = R;

    // ���õ�һ���������, (0, R)
    pointsInAPart[numOfPointsInAPart++].setXY(x, y);

    // ����Բ�ĵ�һ���޵�45���ϲಿ�֣���Բ��1/8�������x����С��y����
    for (; x < R && x <= y; x++) {
        if (d < 0) {
            // �е���Բ�ڣ����ϲ����ý�
            pointsInAPart[numOfPointsInAPart].setXY(x + 1, y);
            // ����delta_d * 4, ��Ϊd(i+1)
            d = d + 8 * x + 12;
        } else {
            // �е���Բ�⣬���²����ý�
            pointsInAPart[numOfPointsInAPart].setXY(x + 1, y - 1);
            // ����delta_d * 4, ��Ϊd(i+1)
            d = d + 8 * x - 8 * y + 20;
            y--;
        }
        numOfPointsInAPart++;
    }

    // ������1/8�ĵ㣬���ݶԳ��Ի����ಿ��
    // �������������������еĵ�
    numOfPoints = 8 * numOfPointsInAPart;
    Point<int> *points = new Point<int>[numOfPoints];
    int count = 0;

    for (int i = 0; i < numOfPointsInAPart; i++) {
        // I����
        // ��ʱ��-1/8
        points[count++].setXY(pointsInAPart[i].y, pointsInAPart[i].x);
        // ���ñ���
        points[count++].setXY(pointsInAPart[i].x, pointsInAPart[i].y);

        // II����
        // ��ʱ��+1/8
        points[count++].setXY(-(pointsInAPart[i].x), pointsInAPart[i].y);
        // ��ʱ��+1/8
        points[count++].setXY(-(pointsInAPart[i].y), pointsInAPart[i].x);

        // III����
        // ��ʱ��+1/8
        points[count++].setXY(-(pointsInAPart[i].y), -(pointsInAPart[i].x));
        // ��ʱ��+1/8
        points[count++].setXY(-(pointsInAPart[i].x), -(pointsInAPart[i].y));

        // IV����
        // ��ʱ��+1/8
        points[count++].setXY(pointsInAPart[i].x, -(pointsInAPart[i].y));
        // ��ʱ��+1/8
        points[count++].setXY(pointsInAPart[i].y, -(pointsInAPart[i].x));
    }
    delete[] pointsInAPart;

    // ���Ϊÿһ������ƫ����Բ��
    for (int i = 0; i < numOfPoints; i++) {
        points[i] += center;
    }

    return points;
}

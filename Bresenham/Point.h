#pragma once

// ������ķ�ʽ��ʾһ����
// Type������ı�������
template<class Type>
class Point {
public:
    // ������
    Type x;
    // ������
    Type y;
    // ������
    Type z;

    Point(Type x = 0, Type y = 0, Type z = 0) : x(x), y(y), z(z) {
    }

    // ����x��y��z��������
   inline void setAll(Type x, Type y, Type z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // ����x��y����
    inline void setXY(Type x, Type y) {
        this->x = x;
        this->y = y;
    }

    // ���������
    inline Point operator+(Point& ano) {
        return Point(this->x + ano.x, this->y + ano.y, this->z + ano.z);
    }

    // +=
    inline Point operator+=(Point& ano) {
        this->x += ano.x;
        this->y += ano.y;
        this->z += ano.z;
        return *this;
    }

};
#pragma once

// 用坐标的方式表示一个点
// Type是坐标的变量类型
template<class Type>
class Point {
public:
    // 横坐标
    Type x;
    // 纵坐标
    Type y;
    // 竖坐标
    Type z;

    Point(Type x = 0, Type y = 0, Type z = 0) : x(x), y(y), z(z) {
    }

    // 设置x，y，z所有坐标
   inline void setAll(Type x, Type y, Type z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // 设置x，y坐标
    inline void setXY(Type x, Type y) {
        this->x = x;
        this->y = y;
    }

    // 两个点相加
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
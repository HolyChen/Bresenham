#version 450 core

out vec4 fColor;

// 子例程，用于圆不同部分的处理
subroutine void process();
layout(location = 0) subroutine uniform process processType;


// 用于处理圆上的点
void processPoints();

// 处理圆心
void processCenter();

void main() {
	processType();
}

// 用于处理圆上的点
subroutine(process)
void processPoints() {
	fColor = vec4(1.0, 1.0, 1.0, 1.0);
}


// 处理圆心
subroutine(process)
void processCenter() {
	fColor = vec4(1.0, 1.0, 0, 1.0);
}

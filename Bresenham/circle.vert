#version 450 core

layout(location = 1) in vec4 vPosition;

// ��������ֵ�ľ���ֵ
uniform float maxCoorAbs;

mat4 scalar(float mul);


void main() {
	gl_Position = scalar(1.0f / maxCoorAbs) * vPosition;
}


mat4 scalar(float mul) {
	return mat4(
		mul, 0, 0, 0,
		0, mul, 0, 0,
		0, 0, mul, 0,
		0, 0, 0, 1
	);
}
#version 450 core

out vec4 fColor;

// �����̣�����Բ��ͬ���ֵĴ���
subroutine void process();
layout(location = 0) subroutine uniform process processType;


// ���ڴ���Բ�ϵĵ�
void processPoints();

// ����Բ��
void processCenter();

void main() {
	processType();
}

// ���ڴ���Բ�ϵĵ�
subroutine(process)
void processPoints() {
	fColor = vec4(1.0, 1.0, 1.0, 1.0);
}


// ����Բ��
subroutine(process)
void processCenter() {
	fColor = vec4(1.0, 1.0, 0, 1.0);
}

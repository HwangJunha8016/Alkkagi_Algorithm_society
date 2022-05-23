#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

int main() {

	float x, y, c;
	cin >> x >> y >> c;

	float Left = 0;
	float Right = x;

	for (int i = 0; i < 1000; i++) { // 10^-3�� 1000�� �϶�� ��??

		float k = (Left + Right) / 2; // ����������� ���� ��������
		float X = sqrt(x * x - k * k);
		float Y = sqrt(y * y - k * k);

		if (-(X * c / Y) + X > c) Left = k; // f(�� ������ x ��ǥ) = -(Xc)/Y+x = c , f(x)�� ���� x�� ���� ������
		else Right = k;
	}

	printf("%.3f", Left);
	return 0;
}
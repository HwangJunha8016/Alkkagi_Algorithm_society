#include <iostream>
#include <math.h>

using namespace std;

double x, y, c, h1, h2;
double low, high, res;

double cal(double w) {				// c�� ���ϴ� ��. (��ʽ��� ����ؼ� ������)
	h1 = sqrt(x * x - w * w);		
	h2 = sqrt(y * y - w * w);		// ��Ÿ��� ������ ���� ����

	return (h1 * h2) / (h1 + h2);	// guess_c
}



int main() {

	cin >> x >> y >> c;

	low = 0;
	high = min(x, y);		// high, low ==> �̺� Ž�� ����.
	res = 0;

	while (high - low > 0.001) {			// 0.001�� �������� ���.
		double w = (low + high) / 2.0;		
		double guess_c = cal(w);

		if (guess_c >= c) {		// �Է¹��� c���� ����� ���� �� ũ�Ƿ� w�� �̺��� Ŀ�� ��.
			res = w;
			low = w;
		}
		else			// �Է¹��� c���� ����� ���� �� �����Ƿ� w�� �̺��� �۾ƾ� ��.
			high = w;
	}
	
	printf("%.3f \n", res);

	return 0;

}
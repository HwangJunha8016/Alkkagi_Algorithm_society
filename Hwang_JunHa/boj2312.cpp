# include <iostream>
# include <algorithm>
# include <cmath>

using namespace std;

int main() {
	int a;
	int N[10000];
	int sosu[10000]; sosu[0] = 2;
	int flag = 0;
	int maxnum = -1;
	int cnt = 1;

	cin >> a;

	for (int i = 0; i < a; i++) {  // �Է� �߿��� ���� ū ���� ã��, �� �������� �Ҽ��� ���� ������ ���� ����.
		cin >> N[i];
		maxnum = max(maxnum, N[i]);
	}

	for (int i = 3; i <= maxnum; i+=2) {  // �Ҽ� ���ϱ� - �Է��� �ִ񰪱����� �Ҽ��� ���Ѵ�.
		for (int j = 3; j < int(sqrt(i)); j++) {
			if (i % j == 0) {  // �Ҽ��� �ƴ�
				flag = 1;
				break;
			}
		}
		if (flag == 0) // �Ҽ��� ��� �迭�� �����Ѵ�.
			sosu[cnt++] = i;
		flag = 0;
	}

	for (int i = 0; i < a; i++) {  // �Է¹��� ���� ���μ� �����ϱ�
		for (int j = 0; N[i] != 1; j++) {  // �Է¹��� ���� 1�� �� ������ ��� �Ҽ��� ������ �ش�.
			int count = 0;
			while(N[i] % sosu[j] == 0) {  // �Ҽ��� �Է¹��� ���� ���� �� ������ ������ �ش�.
				N[i] /= sosu[j];
				count++;  // ���� Ƚ�� üũ
			}
			if(count !=0)  // �ش� �Ҽ��� ������ �ʾ��� ��� (count�� 0�̸�) ������� �ʴ´�.
				cout << sosu[j] <<" " << count << endl;
		}
	}


	return 0;
}
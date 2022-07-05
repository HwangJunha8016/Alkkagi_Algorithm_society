# include <iostream>

using namespace std;

int N;
int arr[1003][10];	// dp ���̺�(1003: �ڸ���, 10: �� �ڸ������� 0~9���� ���� �� ����)
int ans = 0;

int main() {					

	cin >> N;

	for (int i = 0; i < 10; i++)		// 1�� �ڸ� ���� ������ ���� ���� 1���� ���´�.
		arr[1][i] = 1;

	if (N == 1) {
		cout << 10 << endl;
		return 0;
	}

	for (int i = 2; i <= N; i++) {		// N �ڸ��������� ������ ��
		for (int j = 0; j < 10; j++) {	// N �ڸ������� 0~9�� ���� ���� ������ �� ���� ���
			for(int z=j; z<10; z++)		// ������ �� �̹Ƿ� ����, 2�� ���´ٸ� �� ���� �ڸ����� 2�� ���ų� ū ���� �;���.
				arr[i][j] += arr[i - 1][z];
			arr[i][j] %= 10007;
		}
	}

	for (int i = 0; i < 10; i++) {
		ans += arr[N][i];
		ans %= 10007;
	}

	cout << ans << endl;

	return 0;
}
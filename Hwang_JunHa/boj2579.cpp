#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt = 0;
int stair[300];
int d[300];  // indexĭ������ �ִ��� �����ϴ� �迭(dp ���̺�)

int main() {
	int res = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}

	d[0] = stair[0];
	d[1] = stair[0] + stair[1];
	d[2] = max(stair[1]+stair[2], stair[0] + stair[2]);  // ������ ����� �� ��ƾ� �Կ� ����!
	
	for (int i = 3; i < N; i++) {
		d[i] = max(d[i - 3] + stair[i] + stair[i - 1], d[i - 2] + stair[i]);  // ������ ����� �� ��ƾ� �ϹǷ� <������ ����> ����� ��� ���, �� ��� ��츦 �����ؾ� �Ѵ�.
	}

	cout << d[N - 1];

	return 0;
}
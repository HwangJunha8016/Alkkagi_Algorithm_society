#include<iostream>
using namespace std;

int max(int a, int b) { //ũ�� ���ϴ� ����� ���� �Լ�
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	int n;
	int arr[301];
	int dp[301];

	cin >> n;

	for (int i = 1; i <= n; i++) { //dp�� �ε����� ���߱� ���� 1���� ����
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];


	return 0;
}
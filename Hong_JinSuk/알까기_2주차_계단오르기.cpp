#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main() {

	vector<int> arr;
	int dp[300];
	int n; // ��� ����
	int score; // ��� ��
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> score;
		arr.push_back(score);
	}

	dp[0] = arr[0]; //n=1
	dp[1] = max(arr[0], arr[0] + arr[1]); //n=2
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]); //n=3

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]); //n=4����
	}
	// �ε����� 1,2,3,4,5,6,7,8,9�� ���� ��, dp[6]+8+9 or dp[7]+9�� ���ۿ� ����.(dp[i]�� i��° �ε����� �ݵ�� ����.)

	cout << dp[n - 1];
	return 0;
}
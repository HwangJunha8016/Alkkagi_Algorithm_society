#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	//int n;
	//cin >> n;

	//vector<vector<int>> v(2, vector<int>(n, 0));

	//int a, b;
	//for (int i = 0; i < n; i++) {
	//	cin >> a >> b;
	//	v[0][i] = a;
	//	v[1][i] = b;
	//}
	////�Է�

	//int cnt = 0;
	//int Min;
	//Min = max(v[1][0], v[1][n - 1]);
	//
	//for (int i = 0; i < n; i++) {
	//	Min = max(v[1][0], v[1][n - 1]);
	//	//Min �ʱ�ȭ �Ź� 14

	//	for (int j = 0; j < n; j++) {
	//		if (v[0][j] > -1 && v[1][j] <= Min) {
	//			Min = v[1][j];
	//		}
	//		//Min ����
	//	}

	//	cout << "time : " << i+1 << " min : " << Min << endl;

	//	for (int j = 0; j < n; j++) {
	//		if (v[0][j] < Min) {
	//			v[0][j] = -10;
	//		}
	//		if (v[0][j] == Min) {
	//			v[0][j] = -10;
	//			cnt++;
	//			cout << "Min==Min" << endl;
	//		}
	//		//ȸ�� ���۽ð� < ȸ�� �����ð� = ����
	//	}

	//	cout << "max : " << max(v[0][0], v[0][n - 1]) << endl;

	//	cnt++;

	//	if (max(v[0][0], v[0][n - 1]) == -10) break;
	//	
	//}

	//cout << cnt;

	// ������ �� �ȵǴ��� �𸣰���...

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end());

	int Min = v[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (Min <= v[i].second) {
			cnt++;
			Min = v[i].first;
		}
	}
	cout << cnt;

	return 0;
}
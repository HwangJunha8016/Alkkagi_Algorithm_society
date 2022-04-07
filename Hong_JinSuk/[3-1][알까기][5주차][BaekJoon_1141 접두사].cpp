#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 0;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second > b.second) {
		return a.second < b.second;
	}
	if (a.second == b.second) {
		return false;
	}
}

int main() {

	cin >> n;

	string a;
	int b;
	vector<pair<string,int>> str; // ���� + ���ڱ���

	for (int i = 0; i < n; i++) {
		cin >> a;
		b = a.size();
		str.push_back({ a,b });
	} // ����� �ȴ�.

	sort(str.begin(), str.end(), compare); // ���̰� ª�� �������� ����ok

	for (int i = 0; i < str.size(); i++)
		cout << str[i].first << ' ' << str[i].second << endl;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//cout << "i : " << i << endl;
		if (str[i].second != -1) { // �̹� �ٸ� ���տ� �� ���Ҵ� ����
			str[i].second = -1; // ���տ� ��. 1:a.second=-1
			string L_str = str[i].first; // 1:L_str=a,
			int len = str[i].first.size(); 
			for (int j = 0; j < n; j++) { // i�� �ش��ϴ� ���ҿ� ���� ������ ��� ���� ��
				if (L_str == str[j].first) str[j].second = -1; // �ߺ��Ǵ� ���Ҵ� ���� j=2: ab -1
				if (str[j].second != -1 && L_str == str[j].first.substr(0, len)) {
					L_str = str[j].first; // str.first�� L_str�� �����ϹǷ� ��ü
					len = L_str.size();
					str[j].second = -1; // ���� ���տ� �������Ƿ� ����
				}
			}
			cnt++; //������ ���� ����
		}
	}

	cout << cnt;

	return 0;
}
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

bool sorting(pair<int, int> p, pair<int, int>p2) {  // sort�� ����� compare �Լ� - �������� sorting
	if (p.second == p2.second)  // ȸ�� ���� �ð��� ������ ȸ�� ���� �ð��� �������� sorting
		return p.first < p2.first;
	
	return p.second < p2.second;  // �⺻������ ȸ�� ���� �ð��� �������� �������� sorting
	
}


int main() {
	int N, cnt = 1;
	int a, b;
	vector <pair<int, int>> v;
	int maxt;
	
	cin >> N;

	for (int i = 0; i < N; i++) {  // Input
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), sorting);  // ȸ�� ���� �ð� ���� ����
	 
	maxt = v[0].second;  // ȸ�� ���� �ð��� ���� ���� �ð��� �;� �ִ밡 �ǹǷ� vector�� ù ��°�� ������ ����.

	for (int i = 1; i < N; i++) {
		if (v[i].first < maxt) {  // ������ ȸ�ǿ� ��ġ�� ���� ���͸� ���ش�.
			continue;                                // ������ ȸ���� ����ð����� ������ �����ϴ� ���� �ɷ��ָ� �ȴ�.
		}
		maxt = v[i].second;  // ������ �ɷ����� ���� ��쿡�� �ش� ȸ�Ǹ� �����ϰ� �ǹǷ� max ȸ�� ���� �ð��� �������ش�.
		cnt++;
	}
	
	cout << cnt << endl;

	return 0;
}
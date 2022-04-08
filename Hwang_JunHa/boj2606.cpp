# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {
	int N, num;  // ��ǻ�� ��, �� ����
	int pair[1000][2];  // ��ǻ�� �� ����
	int flag = 1;
	vector <int> virus;  // virus�� �ɸ� ��ǻ�� ��ȣ ����
	
	
	cin >> N >> num;

	for (int i = 0; i < num; i++) {  // ����� �Է�
		cin >> pair[i][0] >> pair[i][1];
	}

	for (int i = 0; i < num; i++) {  // 1�� ��ǻ�Ͱ� ���̷����� �����̹Ƿ� 1�� ��ǻ�Ϳ� ����� ��ǻ�� ��� �˻� �� ����
		if (pair[i][0] == 1 && find(virus.begin(), virus.end(), pair[i][1]) == virus.end())
			virus.push_back(pair[i][1]);

		else if (pair[i][1] == 1 && find(virus.begin(), virus.end(), pair[i][0]) == virus.end())
			virus.push_back(pair[i][0]);
	}

	if (virus.begin() == virus.end()) {  // 1�� ��ǻ�Ͱ� �ȳ����� ���̷����� �Ȱɸ��Ƿ� 0��
		cout << 0 << endl;
		return 0;
	}

	while (flag) {  // ���̷����� �ɸ� ��ǻ�͸� ã���� �ݺ�, �� ã���� ��. (flag�� ����)
		flag = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < virus.size(); j++) {  // ���̷����� �ɸ� ��ǻ�͸� ����� ���� ���Ϳ� �ش�ǰ�, ����� �ȵǾ� �ִٸ� ����Ѵ�.
				if (pair[i][0] == virus[j] && find(virus.begin(), virus.end(), pair[i][1]) == virus.end()) {  
					virus.push_back(pair[i][1]);
					flag = 1;
				}

				else if (pair[i][1] == virus[j] && find(virus.begin(), virus.end(), pair[i][0]) == virus.end()) {
					virus.push_back(pair[i][0]);
					flag = 1;
				}
			}
		}
	}

		cout << virus.size() - 1 << endl;  // ���̷����� �ɸ� ��ǻ���� ����, 1�� ��ǻ�͸� ���� �ɸ� ��ǻ���� �����̹Ƿ� 1�� ���ش�.

	return 0;
}
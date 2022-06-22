# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

int N, K;
int visit[100001];  // ���� �ڵ忡�� calc ������ ��ġ index�� ����ϹǷ� 1�� �÷��־�� ��.
int check= 0;
int pre_cnt = 0;	// Ʈ���� �� ����
int cnt = 0;		// ���� answer
int calc;			// ����(1�� ��) ��ġ ���
int arr[3] = { -1, 1, 2 };	// �������� �� �� �ִ� ��ġ
queue <pair<int,int>>q;

int main() {					

	cin >> N >> K;

	q.push({ N,0 });

	while (!q.empty()) {
		check = q.front().first;		// ť�� ����� ���� ����.
		pre_cnt = q.front().second;		// ť�� ���� ��ġ�� �־��� �� + 1 ���ֱ� ���� ������.

		q.pop();

		if (check == K) {
			cnt = pre_cnt;
			break;
		}

		for (int i = 0; i < 3; i++) {
			if (arr[i] == 2) {
				calc = check * arr[i];

				if (calc < 0 || calc > 100000 || visit[calc] == 1)	// �̵� �Ұ����� ��ġ�̰ų� �̹� ����� ��ġ�� ��� pass
					;
				else {		// �� �� �ִ� ��ġ��� ť�� ����.
					q.push({ calc, pre_cnt + 1 });
					visit[calc] = 1;
				}
			}
			else {
				calc = check + arr[i];
				if (calc < 0 || calc > 100000 || visit[calc] == 1)
					;
				else {
					q.push({ calc, pre_cnt + 1 });
					visit[calc] = 1;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
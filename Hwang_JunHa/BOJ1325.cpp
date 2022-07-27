#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N, M;
int a, b;
int node;
int len = 0;
int maxlen = -1;
int cnt = 0;

int arr[10001];
int res[10001];
int visit[10001];

vector <pair<int, int>> v1[10001];
queue <int> q1;

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		
		v1[b].push_back(make_pair(a, 0));
	}

	for (int i = 1; i <= N; i++) {		// ��庰�� BFS �۵���Ű��
		if (v1[i].empty()) continue;	// �ش� ����� ���� ������ ������ continue

		q1.push(i);
		len++;
		visit[i]++;


		while (!q1.empty()) {		// �ش� ����� ���� ������ ����� ������ ť�� �̿��� BFS ����
			node = q1.front();
			q1.pop();

			for (int j = 0; j < v1[node].size(); j++) {
				int next = v1[node][j].first;

				if (visit[next] == 0) {		// ��忡 �湮�� �� �ִٸ� ��ŷ�� �� �ִ� ��ǻ�� ��� + 1
					q1.push(next);
					len++;
				}

				visit[next]++;
			}
		}

		for (int x = 1; x <= N; x++)		// ��� ��忡�� BFS�� ��� �������� visit �ʱ�ȭ
			visit[x] = 0;

		arr[i] = len;			// �湮�� ����� ���� ����. ��� ��� i
;
		len = 0;
	}

	for (int i = 1; i <= N; i++) {		// �� ��庰 ���� �� ���� �� ���̸� ã�´�.
		maxlen = max(maxlen, arr[i]);
	}

	for (int i = 1; i <= N; i++) {		// ���� �� ���̸� ���� ������ ã�´�.
		if (arr[i] == maxlen)
			res[cnt++] = i;
	}

	sort(res, res + cnt);		// ã�� ������ ����

	for (int i = 0; i<cnt; i++)
		cout << res[i] << endl;




	return 0;
}
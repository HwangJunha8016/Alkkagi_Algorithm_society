# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# define INF 1e9

using namespace std;

vector <pair<int, int>> city[1001];  // ����
priority_queue<pair<int, int>> qu;

int N, M;					// ������ ��� ����
int from, to, val;
int start, fin;

int dist[1001];		// �ִܰŸ� ������ �迭, ��������� Ư�� ����(index)������ �ִ� �Ÿ� ��.

bool compare(pair<int, int>a, pair<int, int>b) {	// �Ȱ��� ����(A->B)�� ��, ����� �� ���� ���� ������ �տ� ���� ����
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {					// �ּ� ��� ���ϱ�

	cin >> N >> M;

	fill(dist, dist + N + 1, INF);  // dist ä���

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> val;
		city[from].push_back({to,val});
	}

	for (int i = 0; i < N; i++) {
		if (city[i].empty()) continue;

		sort(city[i].begin(), city[i].end(), compare);
	}

	cin >> start >> fin;

	qu.push({ 0, start });	// ������ Cost, ������ Vertex
	dist[start] = 0;		// ������ �ִܰŸ�

	while (!qu.empty()) {
		int cost = -qu.top().first;		// �湮�� Cost
		int here = qu.top().second;		// �湮�� Vertex

		qu.pop();

		for (int i = 0; i < city[here].size(); i++) {
			int next = city[here][i].first;			// ���� �湮�� ��
			int nextcost = city[here][i].second;	// ���� �湮�� ���

			if (dist[next] > dist[here] + nextcost) {
				// ����� dist[next]����  ���� ���� ���ļ� �� ��찡 �Ÿ��� �� ª���� ���� �� ť�� ����
				dist[next] = dist[here] + nextcost;
				qu.push({ -dist[next], next });  // �켱 ���� ť�� Max Heap �����̹Ƿ� 
				// ���� ���� ���� ���� ū ���� �ǰ� "-"�� ���ؼ� ť�� �ְ� ����.
			}
		}
	}
	
	cout << dist[fin] << endl;

	return 0;
}
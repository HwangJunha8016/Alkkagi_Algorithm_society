# include <iostream>
# include <queue>
# include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int c, I, s_x, s_y, e_x, e_y;
int board[300][300];
int visit[300][300];
int mov[8][2] = {{-2,1}, {-1,2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void BFS() {
	q.push(make_pair(s_x, s_y));

	while (!q.empty()) {  // ť�� �� ������
		pair<int, int> p = make_pair(q.front().first, q.front().second);
		q.pop();

		if (visit[p.first][p.second] >= 1)		// �̹� �湮�� ���̸� �� �ʿ� ����.
			continue;

		visit[p.first][p.second] = 1;			// �湮���� ���� ���̸� �湮�� ���� ���
		
		if (p.first == e_x && p.second == e_y) {	// ���� ������ �����ϸ� ����.
			cout << board[e_x][e_y] << endl;
			return;
		}


		for (int i = 0; i < 8; i++) {  
			if ((p.first - mov[i][0]) >= I || (p.first - mov[i][0]) < 0 || (p.second - mov[i][1]) < 0 || (p.second - mov[i][1]) >= I)	// ü������ ��� �� ����.
				continue;
			pair<int, int> tmp = make_pair(p.first - mov[i][0], p.second - mov[i][1]);		// ����Ʈ�� ������ �� �ִٸ� �ش� ĭ�� ť�� �ִ´�.
			q.push(tmp);
			board[tmp.first][tmp.second] = board[p.first][p.second] + 1;		// �ش� ĭ���� ������ Ƚ�� ���.  (���� �̵��ߴ� Ƚ�� + 1�� ����)
		}
	}
	if(q.empty())			// �ش� ĭ���� �̵� ���ϸ�
		cout << 0 << endl;
}

int main() {					// ����Ʈ�� �̵�
	
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> I;

		cin >> s_x >> s_y;    // ��� ��ǥ
		board[s_x][s_y] = 0;  // start
		
		cin >> e_x >> e_y;    // ���� ��ǥ
		if (s_x == e_x && s_y == e_y) {  // ���� ��ġ�� ���
			cout << '0' << endl;
			continue;
		}

		BFS();
		for (int i = 0; i < 300; i++) {			// �� ���� ���̽��� ������ �ʱ�ȭ
			for (int j = 0; j < 300; j++) {
				visit[i][j] = 0;
				board[i][j] = 0;
			}
		}

		while (!q.empty()) q.pop();		// �� ���� ���̽��� ������ �ʱ�ȭ
	}


	return 0;
}
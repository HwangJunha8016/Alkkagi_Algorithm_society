#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {

	int n;
	cin >> n;

	int Size;
	int start_x, start_y, end_x, end_y;

	int mx[8] = { 1,1,-1,-1,2,2,-2,-2 };
	int my[8] = { -2,2,-2,2,-1,1,-1,1 };
	// ����Ʈ�� �̵��� �� �ִ� ��� ����� ��

	for (int i = 0; i < n; i++) {

		cin >> Size >> start_x >> start_y >> end_x >> end_y;

		deque<pair<int, pair<int, int>>> v;
		v.push_back(make_pair(0, make_pair(start_x, start_y)));
		// count�� ��ǥ ����, ������ 0

		int visited[300][300] = { 0, }; // ���� Size�� �ȵ���..?
		visited[start_x][start_y]++;

		int cnt, x, y;
		while (1) { // ������� �ٰ������� ����
			x = v.front().second.first;
			y = v.front().second.second;
			cnt = v.front().first;
			v.pop_front();


			for (int i = 0; i < 8; i++) {
				int next_x = x + mx[i];
				int next_y = y + my[i];
				//���������� ����+�̵��ѰŸ�

				if (next_x<0 || next_y<0 || next_x>Size - 1 || next_y>Size - 1)
					continue;
				// ĭ�� ����� �Ѿ

				if (visited[next_x][next_y])
					continue;
				// �̹� ������ �����̸� �Ѿ

				visited[next_x][next_y]++;
				v.push_back(make_pair(cnt + 1, make_pair(next_x, next_y)));
				//���ο�� �����ϸ� count++, �װ� �־���
			}

			if (x == end_x && y == end_y) {
				cout << cnt << endl;
				break;
			}
		}
	}

	return 0;
}
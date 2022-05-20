#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1001  //�ִ밪 (���� ����)
#define INF 9876543210  //���Ѵ� ����

vector<pair<int, int>>bus[MAX];  //next, cost
priority_queue<pair<int, int>>pq;  //cost,next
vector<int>res(MAX, INF);  //��� ���� �迭(����ġ ���) - ���Ѵ�� �ʱ�ȭ
int x1, x2;  //�����, ������

void dijkstra() {
	pq.push({ 0, x1 });
	res[x1] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		//�켱���� ť�� pair�� first ������ �켱������ ���ϹǷ�
		//cost�� ������ ���� - �ּ� ����� ���ؾ��ϱ� ����
		pq.pop();

		if (res[cur] < cost)  //�ߺ��� �������� Ȯ��
			continue;

		for (int i = 0; i < bus[cur].size(); i++) {
			int next = bus[cur][i].first;
			int next_cost = bus[cur][i].second + cost;
			if (res[next] > next_cost) {
				res[next] = next_cost;
				pq.push({ -next_cost,next });
			}
		}
	}
}

int main(void) {
	int city, bus_n;
	int a, b, c;  //start, end, cost

	cin >> city >> bus_n;

	for (int i = 0; i < bus_n; i++) {
		cin >> a >> b >> c;
		bus[a].push_back(make_pair(b, c));
	}

	cin >> x1 >> x2;

	dijkstra();

	cout << res[x2];

	return 0;
}
 
/* dfs ���̰� ������� ���ø޸� �ʰ� 
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int bus_n, x2;
static int idx = 0;

void dfs(int shift, vector<tuple<int, int, int>> bus, int res[], int now) {
	for (int j = 0; j < bus_n; j++) {
		if (get<0>(bus[j]) == shift) {
			if (get<1>(bus[j]) == x2) {
				now += get<2>(bus[j]);
				res[idx] = now;
				idx++;
				now -= get<2>(bus[j]);
				break;
			}
			else {
				now += get<2>(bus[j]);
				dfs(get<1>(bus[j]), bus, res, now);
				now -= get<2>(bus[j]);
			}
		}
	}
}

int main() {
	int city, a, b, c, x1, shift;
	int res[100] = { 0, };
	
	int now = 0;
	vector<tuple<int, int, int>> bus;

	cin >> city;
	cin >> bus_n;
	for (int i = 0; i < bus_n; i++) {
		cin >> a >> b >> c;
		bus.push_back(make_tuple(a, b, c));
	}
	cin >> x1 >> x2;

	for (int i = 0; i < bus_n; i++) {
		if (get<0>(bus[i]) == x1) {
			if (get<1>(bus[i]) == x2) {
				res[idx] = get<2>(bus[i]);
				idx++;
			}
			else {
				now += get<2>(bus[i]);
				dfs(get<1>(bus[i]), bus, res, now);
			}
		}
		now = 0;
	}
	
	int min = res[0];
	for (int i = 0; i < idx; i++) {
		if (min > res[i]) {
			min = res[i];
		}
	}
	cout << min;

	//cout << endl << endl;
	//for (int i = 0; i < idx; i++) {
	//	cout << endl << res[i];
	//}
	
	return 0;
}
*/

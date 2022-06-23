#include<iostream>
#include<deque>

using namespace std;

int visited[100001] = { 0, };
deque<int> q;

int main() {

	int Subin, Sister;
    cin >> Subin >> Sister;

	q.push_back(Subin);

	int check;
	int cnt = 0;

	while (1) {

		check = q.front();
		q.pop_front(); //deque

		if (check == Sister) {
			cout << visited[check] << endl;
			cout << "check : " << check << endl;
			break;
		} // ã���� return �ϰ� ����
		
		if (check - 1 >= 0 && visited[check - 1] == 0) {
			q.push_back(check - 1);
			visited[check - 1] = visited[check] + 1; // enque
		} // �ѹ��� �� �� �ְ�, �ű⸦ �湮���� �ʾ����� �湮��.

		if (check + 1 <= 100000 && visited[check + 1] == 0) {
			q.push_back(check + 1);
			visited[check + 1] = visited[check] + 1; // enque
		} // �ѹ��� ���� �� �ְ�, �ű⸦ �湮���� �ʾ����� �湮��.

		if (check * 2 <= 100000 && visited[check * 2] == 0) {
			q.push_back(check * 2);
			visited[check * 2] = visited[check] + 1; // enque
		} // 2�� ���� �� �ְ�, �ű⸦ �湮���� �ʾ����� �湮��.

	}
	
	return 0;
}
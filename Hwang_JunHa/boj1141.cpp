# include <iostream>
# include <string>
# include <algorithm>

using namespace std;

int main() {
	int N, cnt = 0;  
	string words[50];  // 50���� �ܾ� ������ ����
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> words[i];

	sort(words,words+N);  // ���ĺ������� ����(�ð����⵵�� ���̴� �뵵)
	                      // ���� ���,  hi, h, hello�� ���� �� h, hi, hello�� �ǹǷ� h�� �ٷ� ���͸� �� �� �ִ�.

	for (int i = 0; i < N; i++) {  // ����Ž��
		for (int j = i+1; j < N; j++) {
			if (words[j].find(words[i]) == 0) {  // ���λ��� ���� Ȯ�εǸ�
				words[i].clear();  // ���λ��� �ܾ �����.
				break;  // �񱳴���� ���������Ƿ� �� �̻��� �ݺ��� ���ǹ��ϴ�.
			}
		}
	}

	for (int i = 0; i < N; i++) {  // ������ �ܾ ���� ī��Ʈ�Ѵ�.
		if (words[i].empty())
			continue;
		else
			cnt++;
	}

	cout << cnt;
		

	return 0;
}
# include <iostream>

using namespace std;

int N;
int check = 2;
int cntw = 0;
int cntb = 0;
int wcheck = 0;
int bcheck = 0;
int arr[128][128];
int visit[128][128];


int main() {					

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	check = N;


	// check�� ��� 2�� ������ �ָ鼭 ������ �����ٰ� �����ϸ� ��.

	while (check != 0) {		
		for (int z = N-1; z >= 0; z -= check) {			// 29,30��° ���� ������ �Ѿ�� ���ִ� window size�� �����ϴ� �κ�.		[ sliding window ]
			for (int x = N-1; x >= 0; x -= check) {
				for (int i = z; i > z - check; i--) {  // 31, 32��° ���� ���簢�� ������ Ȯ���ϴ� �κ�.
					for (int j = x; j > x - check; j--) {
						if (visit[i][j] == 1)
							break;

						//cout << i << " \t" << j << endl;
						if (arr[i][j] == 1)		// �ش� ĭ�� � ������ ä�������� count �ϴ� �κ�
							bcheck++;
						else
							wcheck++;
					}
				}
				//cout << cntw << endl << cntb << endl;
				if (bcheck == (check * check)) {			// ������ ��� Ư�� ����� ä�����ִٸ�, �ش� ������ Ȯ������ �ʾƵ� �ǹǷ� visit�� �̿��� break�ǰ� �Ѵ�.
					cntb++;
					for (int i = z; i > z - check; i--)
						for (int j = x; j > x - check; j--)
							visit[i][j] = 1;
				}
				else if (wcheck == (check * check)) {
					for (int i = z; i > z - check; i--)
						for (int j = x; j > x - check; j--)
							visit[i][j] = 1;
					cntw++;
				}
				bcheck = 0;
				wcheck = 0;
			}
		}
		check /= 2;
	}

		cout << cntw << endl << cntb << endl;

	return 0;
}
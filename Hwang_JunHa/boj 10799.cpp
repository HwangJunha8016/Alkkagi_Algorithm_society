# include <iostream>
# include <string>

using namespace std;

char bar[100000];
int top = 0;
string b;
int res = 0;


// bar �κ��� �ʿ������ �����ϱ� ���� �������� ����.

int main() {					
	cin >> b;

	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '(' && b[i+1] == ')') {		// �������� ���� �� ���� ���� ����Ⱑ �߸��Ƿ� ���ÿ� �����ص� ����� ���� ����.
			res += top;
			i++;
		}

		else if(b[i]=='(')		// ������� ��� ���ÿ� ����
			bar[top++] = '(';

		else {					// ������� �߷������� ������ ���κ��� ++ ���־�� ��.
			bar[top - 1] = ' ';
			top--;
			res++;
		}
	}
	
	cout << res << endl;

	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	
	int n;
	cin >> n; //case

	vector<int> arr; // case�� �ִ� �迭
	vector<int> sosu; // �Ҽ��� �ִ� �迭
	vector<int> count; // �μ��� ������ ���� �迭
	vector<int> divsosu; // �μ��� ���� �迭
	vector<int> sosu_copy; // sosu ���Ϳ� �ֱ����� �����佺�׳׽��� ü�� �Ҽ����ϱ�
	int a;

	for (int i = 0; i < n; i++) {
		cin >> a;
		arr.push_back(a); // arr�� case�� �־���
	}

	int MAX = *max_element(arr.begin(), arr.end()); //�迭���� �ִ�ã��. + �߉�

	for (int i = 0; i <= MAX; i++) {
		sosu_copy.push_back(i);
	}//MAX ������ ���� �־��ش�. + �߉�

	for (int i = 2; i <= MAX; i++) { // �����佺�׳׽�ü + �߉�
		if (sosu_copy[i] == 0) continue;
		for (int j = i + i; j <= MAX; j += i) {
			sosu_copy[j] = 0;
		}
	}

	for (int i = 0; i <= MAX; i++) {
		if (sosu_copy[i] != 0 && sosu_copy[i] != 1) sosu.push_back(sosu_copy[i]); //sosu�� Max���� �Ҽ� �־���+�߉�
	}



	for (int i = 0; i < n; i++) { // ��� case�˻�
		for (int j = 0; j < sosu.size(); j++) { // MAX ������ ��� �Ҽ��� ������
			int cnt = 0; // �μ����� üũ
			if (arr[i] == 1) break; // ���μ����ذ� ������ break;
			while (arr[i] % sosu[j] == 0) { //�Ҽ��� �������� �� �Ҽ��� �μ�
				arr[i] = arr[i] / sosu[j];
				cnt++; // �������� �μ����� ++
			}
			if (cnt > 0) { // �μ��� �־��ش�.
				divsosu.push_back(sosu[j]); // 50�ΰ�� sosu[0]=2, sosu[1]=5
				count.push_back(cnt); // 50�� ��� count[0]=1,count[1]=2�� �ȴ�.
			}
		}
	}
	for (int j = 0; j < divsosu.size(); j++) { //�μ� ������ŭ ���
		cout << divsosu[j] << " " << count[j] << endl;
	}

	return 0;
}
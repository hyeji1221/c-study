#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int n, m; //n�� ���� ��, m�� ������ ��
int arr[100][100];
int INF = 999999999;
void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j || arr[i][j] == INF) // �ڱ� �ڽſ��� ���� ���� 0
				cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int start, finish, cost;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = INF; // ���Ѵ�� �ʱ�ȭ
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> finish >> cost;
		// �Է¹��� �� start�� finish�� �������� �� �Է¹޴� ��찡 �ֱ� ����
		if (arr[start - 1][finish - 1] > cost) 
			arr[start - 1][finish - 1] = cost;
	}
	floyd();
	return 0;
}
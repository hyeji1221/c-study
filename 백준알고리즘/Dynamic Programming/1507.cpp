// �÷��̵� - �ͼ� �˰����� ���Ͽ� ��� �������� ��� �������� �ּ� ��θ� ���ϴµ� ���ļ� ���� ��찡 �ٷ� ���� ��캸�� ū ��쿡�� ���� ó�����ְ� 
// ���ļ� ���� ���� �ٷ� ���� ��찡 ���� ������  �ٷ� ���� ��츦 ���������μ� ������ ������ �ּڰ��� ���ϱ�

#include <iostream>
#define MAX 20
using namespace std;
int n, check;
int arr[MAX][MAX];
bool road[MAX][MAX] = { 1, };

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || j == k || i==j)
					continue;
				else if (arr[i][j] > arr[i][k] + arr[k][j]) { // �ּ� ��ΰ� �������� �ʴ� ��� ����
					check = -1;
					return;
				}
				else if (arr[i][j] == arr[i][k] + arr[k][j]) // �ٷ� ���� ��� �����ֱ�
					road[i][j] = false;
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			road[i][j] = true;
		}
	}

	floyd();

	if (check == -1)
		cout << -1 << "\n";

	else {
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (road[i][j])
					total += arr[i][j];
			}
		} // road[i][j]�� road [j][i]��� ����Ͽ����Ƿ� 2 ������
		cout << total / 2 << "\n";
	}
		
	return 0;
}
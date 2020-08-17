#include <iostream>
#include <climits>
using namespace std;
int arr[11][11];
int visit[11];
int n;
int m = INT_MAX;
// cnt�� �湮�� ������ ��, y�� ���� ��� ��ġ
void dfs(int start, int y, int sum, int cnt)
{
	if (cnt == n && y == start) { //��ȯ������
		if (m > sum)
			m = sum; 
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!arr[y][i]) continue;
		// ��� y�� �湮���� �ʾҰ� ������ �Ǿ� ������
		if (!visit[y] && arr[y][i] > 0) {
			visit[y] = true;
			sum += arr [y][i];
			if (sum <= m) { // �ȳ����� �ð��� �����ɸ�
				dfs(start, i, sum, cnt + 1);
			}
			visit[y] = false; 
			// �湮�� ��尡 ���� ���� ����� ���� �ƴϸ� �湮���� ���� ������ üũ
			sum -= arr[y][i]; //sum ���󺹱�
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
		}
	}
	for (int i = 0; i < n; i++) { // ��� �������� ����
		dfs(i, i, 0, 0);
	}
	cout << m;
}
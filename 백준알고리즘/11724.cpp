#include <iostream>
#include <vector>
using namespace std;
vector <int> v[1001];
int visit[1001] = { 0, };
int n, m;
int total = 0;
void dfs(int num)
{
	visit[num] = 1;
	for (int i = 0; i <v[num].size(); i++) {
		int n = v[num][i];
			if (!visit[n]) {
				cout << "n��" << n << "\n";
				dfs(n);
			}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) { //i�� 1�� 3, dfs�� ���� 1�� ����� ���� �湮�Ϸ�
			cout << "i��" << i << "\n";
			dfs(i);
			total++;
		}
	}
	cout << total;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int parent[MAX];
int n, m, total;
vector < pair<int, pair<int, int>>> v;

int Find(int x)
{
	if (parent[x] == x) return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);

	if (x != y) parent[y] = x; // �θ� �����Ͽ� ����
}

bool Sameparent(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; // ��ǻ���� ��, ������ �� �ִ� ���� ��
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		if (Sameparent(v[i].second.first, v[i].second.second) == false) { // true�� ���� ��ȯ�� �Ͼ�� ���
			Union(v[i].second.first, v[i].second.second);
			total += v[i].first;
		}
	}
	cout << total << "\n";
}
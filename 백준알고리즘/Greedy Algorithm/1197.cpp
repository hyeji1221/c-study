// �ּ� ����Ʈ���� �����ϰ� ũ�罺Į �˰����� �̿��Ѵ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int V, E; //V�� ������ ��, E�� ������ ��
vector<pair<int, pair<int, int>>> v; // ����, ����, ����ġ
int parent[MAX];
int total = 0;

int Find(int x) // �θ� ã��
{
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y) // ���� ����Ŭ�� �Ͼ�� �ʴ� ����̸�
		parent[y] = x; // x�� y�� �θ� �����Ѵ�.
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
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(v.begin(), v.end()); // ����ġ�� �������� ����

	for (int i = 1; i <= V; i++) {
		parent[i] = i; // �θ� ��  �ڽ����� �ʱ�ȭ
	}
	for (int i = 0; i < E; i++) {
		if (Sameparent(v[i].second.first, v[i].second.second) == false) {
			Union(v[i].second.first, v[i].second.second);
			total += v[i].first; // first�� ����ġ
		}
	}
	cout << total << "\n";
}

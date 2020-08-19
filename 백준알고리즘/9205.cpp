#include <iostream>
#include <cstring> // memset
#include <vector>
#include <algorithm>
using namespace std;
int t, n; //t�� �׽�Ʈ ���̽�, n�� ������ ��
vector <pair<int, int>>v;
int visit[100];
int nowx, nowy, storex, storey, rockx, rocky;
int check;

void dfs(int x, int y)
{
	int n;
	n = abs(rockx - x) + abs(rocky - y); // abs�� ���밪

	if (n <= 1000) { //50m�� 20�� �̹Ƿ� �� ���� �ִ� �Ÿ��� 1000m
		check = 1;
		return;
	}
	for (int i = 0 ; i < v.size(); i++) {
		if (visit[i] == 1) {
			continue;
		}
		n = abs(v[i].first - x) + abs(v[i].second - y);
		if (n > 1000) // i��° ���������� ��������� ��ġ�� 1000���� ũ�� ���� ������
			continue;
		else {
			visit[i] = 1;
			dfs(v[i].first, v[i].second);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> nowx >> nowy;
		v.clear();
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) { // ������ ��ġ �Է¹ޱ�
			cin >> storex >> storey;
			v.push_back(make_pair(storex, storey));
		}
		cin >> rockx >> rocky;
		check = 0;
		dfs(nowx, nowy);
		if (check == 1)
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
	return 0;
	
}
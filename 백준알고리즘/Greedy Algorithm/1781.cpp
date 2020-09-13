#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>>v;
priority_queue<int> pq;
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int answer = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; // �������, �Ŷ�� ��
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end()); 
	for (int i = 0; i < n; i++) {
		int a = v[i].first;
		pq.push(-v[i].second); // ��������� ���� ���� ó���� �ֱ� ������
		while (a < pq.size()) // ���� ������ο� �Ŷ�� ���� ������ �ִ� ���
			pq.pop(); // ���� �̹Ƿ� ���� ���� ���� ���� pop
	}
	while (!pq.empty()) {
		answer += pq.top();
		pq.pop();
	}
	cout << -answer << "\n";
	
	return 0;
}

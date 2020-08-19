#include <iostream>
using namespace std;
int parent[100001];
int g, p; // g�� ����Ʈ�� ��, p�� ������� ��
int total = 0;

int findParent(int a) // �θ��带 ã�� �Լ�
{
	if (a == parent[a])
		return a;
	else
		return parent[a] = findParent(parent[a]); // ���
}

void unionParent(int a, int b) // �θ��� ��ġ��
{
	a = findParent(a); //a�� �θ� ã��
	b = findParent(b); //b�� �θ� ã��
	if (a < b) parent[b] = a;
	else
		parent[a] = b;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> g >> p;
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= p; i++) {
		int n;
		cin >> n;
		int docking = findParent(n); // n�� �θ��带 ã�Ƽ� docking�� ����
		if (docking) {
			unionParent(docking, docking - 1); 
			//doking�� ����Ʈ ��Ʈ�� doking-1�� �ǰ� �Ѵ�.
			// ���� findParent �� 0�� �Ǹ� ���̻� ��ŷ�� ����Ʈ�� ���ٴ� �ǹ�
			total++;
		}
		else
			break;
		
	}
	cout << total << "\n";
}
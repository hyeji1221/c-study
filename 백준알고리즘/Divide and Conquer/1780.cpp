#include <iostream>
using namespace std;
int paper[2188][2188];
int cnt[3]; // 0�� -1�θ� ä���� ����, 1�� 0���θ�, 2�� 1�θ� ä���� ����
bool same(int x, int y, int n)
{
	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			if (paper[x][y] != paper[i][j])
				return false; // �ٸ�
		}
	}
	return true; // ����
}
void check(int x, int y, int n)
{
	if (same(x, y, n)) {
		cnt[paper[x][y] + 1] += 1;
		return;
	}
	int div = n / 3; // 3������� ������ �� �� ���� ũ��
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			check(x + i * div, y + j * div, div);
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> paper[i][j];
		}
	}
	check(0, 0, size);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << "\n";

}
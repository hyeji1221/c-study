#include <iostream>
#include <algorithm>
using namespace std;

// ���Ϸ��� �ϴ� �ε����� ���ڴ� �ٷ� ������ �ε����� 
// 5��° ������ �ε����� ���� �����ָ� ������ �ȴ�
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int arr[101] = { 1, 1, 1, 1, 2, 2 };
		for (int j = 6; j <= N; j++) {
			arr[j] = arr[j - 1] + arr[j - 5];
		}
		cout << arr[N] << "\n";
	}
	
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000] = { 0, };
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, t;
	int k, s;
	cin >> n >> t; // �ܿ� ����, ������� ������ �� �ִ� �ð�
	for (int i = 0; i < n; i++) {
		cin >> k >> s; // �ܿ� �� ���� ���� �ð�, �� �ܿ� ������ ����
		for (int j = t; j >= k; j--) {
			arr[j] = max(arr[j], arr[j - k] + s); // arr[j - k]�� ����� ���� �ð�
		}
	}
	cout << arr[t] << "\n";
	
	
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int arr[10001] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++) { //i�� 0���� n���� ���ʷ� ����ϱ� ����
				cout << i << "\n";
			}
		}
	}

}
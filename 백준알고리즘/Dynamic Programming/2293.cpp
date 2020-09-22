#include <iostream>
#include <algorithm>
/*ù ��° ������ ����Ͽ� �� k�� ���� ������ ����� ���� ã�´�.
ù ��°~�� ��° ������ ����Ͽ��� ��, ��k �� ���� ������ ����� ���� ã�´�.�� ��, ù ��° ������ ����ؼ� ���ߴ� ����� ���� Ȱ���Ѵ�.
ù ��°~n ��° ������ ����Ͽ��� ������ �ݺ��Ѵ�.*/
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;
	int dp[10001] = { 0, };
	int coin[101] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k ; j++) {
			dp[j] = dp[j] + dp[j - coin[i]]; // dp���� ���ϴ°� ��ü�� coin���� �����ϱ� ����
			cout <<"dp "<<dp[j-coin[i]]<< " coin[i] " << coin[i]<<" ";
		}
	}
	cout << dp[k] << "\n";
	return 0;
}

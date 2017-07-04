/**
ID: Wan Zhong
TASK: subset
LANG: C++
**/ 
#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 45;
long long dp[maxn][maxn * (maxn + 1) / 2];

int main() {
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	
	int n;
	cin >> n;
	if((n % 4 != 3) && (n % 4 != 0)) {
		cout << "0" << endl;
		return 0;
	}
	int half_sum = (1 + n) * n / 4;
	/**
	* dp[i][j] ��ʾ����ǰi������ȡ�ú�Ϊj������� 
	* ���ǱȽϹ��ĵ�i��ȡ�����i-1��ȡ���Ĺ�ϵ��Ҳ����״̬ת�� 
	* dp[i][j] = dp[i-1][j] + dp[i-1][j-i]
	* dp[i-1][j]��ʾ��ȡ��i���� 
	* dp[i-1][j-i]��ʾȡ��i����
	* ��ʱ����������������ǵ��� 
	*/
	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int j = 0; j <= half_sum; j++) {
			if(j >= i) {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
			} else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	
	cout << dp[n][half_sum] / 2 << endl;
} 

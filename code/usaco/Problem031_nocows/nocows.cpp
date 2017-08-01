/**
ID: Wan Zhong
TASK: nocows
LANG: C++
**/ 
#include <stdio.h>
const int maxk = 105;
const int maxn = 205;
const int mod = 9901;
int s[maxk][maxn];
 
int main()
{
	int k, n;
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		s[i][1] = 1;
	}

	for (int j = 1; j <= k; ++j) {
		for (int i = 3; i <= n; i += 2) {
			for (int k = 1; k <= i-2; k += 2) {
				s[j][i] = (s[j][i] + s[j-1][k] * s[j-1][i-k-1]) % mod;
			}
		}
	}
 
	printf("%d\n", (s[k][n] - s[k-1][n] + mod) % mod);
}

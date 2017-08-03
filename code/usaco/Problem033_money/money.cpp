/**
ID: Wan Zhong
TASK: money
LANG: C++11
**/ 
#include <stdio.h>
#include <cstring>

const int maxn = 10005;

using namespace std;
 
int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
 
    int v, n, p;
    long long dp[maxn];
 
    scanf("%d%d", &v, &n);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i = 1;i <= v; i++) {
        scanf("%d", &p);
        for(int j = p; j <= n; j++) {
        	dp[j] += dp[j-p];
		}
    }
    printf("%lld\n", dp[n]);
    return 0;
}

/**
ID: Wan Zhong
TASK: humble
LANG: C++11
**/ 
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll N=1e5+5,K=105,INF=1e10;
ll n,k,ans[N],a[K],s[N];
int main(){
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout); 
    cin >> k >> n;
    for(ll i = 1; i <= k; i++) {
    	scanf("%d",&a[i]);
	}
    ans[0] = 1;
    for(ll i = 1;i <= n; i++) {
        ll now = INF;
        for(ll j = 1; j <= k; j++) {
            while(a[j]*ans[s[j]] <= ans[i-1]) {
            	 s[j]++;//Î¬»¤s[j]
            }
            now = min(now, a[j] * ans[s[j]]);//¸üÐÂf[i]
        }
        ans[i] = now;
    }
    cout << ans[n] << endl;
}

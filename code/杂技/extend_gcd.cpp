#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void exgcd(ll a,ll b,ll& d,ll& x,ll& y) {
    if(!b) { d = a; x = 1; y = 0; }
    else{ exgcd(b, a%b, d, y, x); y -= x*(a/b); }
}

ll inv(ll a, ll p) {
    ll d, x, y;
    exgcd(a, p, d, x, y);
    return d == 1 ? (x+p)%p : -1;
}

int main() {
    ll a,p;
    while(1) {
        scanf("%lld %lld",&a,&p);
        printf("%lld\n",inv(a,p));
    }
}

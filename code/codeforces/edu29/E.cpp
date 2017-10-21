#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 2e5 +10;
typedef struct Node{
    int l, r;
    int pos;
    bool operator < (const Node & R) const {
        if(l != R.l) return l < R.l;
        return r < R.r;
    }
}Node;
Node s[maxn];
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int l, r;
        cin >> s[i].l >> s[i].r;
        s[i].pos = i + 1;
    }
    sort(s, s + t);
    int ans = -1;
    for(int i = 1; i < t; i++) {
        if(s[i - 1].r >= s[i].r) {
            ans = s[i].pos;
            break;
        } else if(s[i - 1].l >= s[i].l) {
            ans = s[i - 1].pos;
            break;
        }
        s[i].l = max(s[i].l, s[i - 1].r + 1);
    }
    cout << ans << endl;
    return 0;
}

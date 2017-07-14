#include<iostream>

using namespace std;

int main() {
    int n, a, b, c;
    int an = 0, bn = 0, cn = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        an += a;
        bn += b;
        cn += c;
    }
    if(an == 0 && bn == 0 && cn ==0) {
        cout << "YES" << endl;
    
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

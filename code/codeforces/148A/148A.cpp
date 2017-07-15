#include <iostream>
#include <set>

using namespace std;

int main() {
    int a[4], d;
    set<int> s;
    for(int i = 0;i < 4; i++) {
        cin >> a[i];
    }
    cin >> d;
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= d / a[i]; j++) {
            s.insert(j * a[i]);
        }
    }
    cout << s.size() << endl;
    return 0;
}

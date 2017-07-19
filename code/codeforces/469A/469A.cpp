#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 105;

int main() {
	int n;
	cin >> n;
	bool ok[maxn];
	memset(ok, 0, sizeof ok);
	int x, y, t;
	cin >> x;
	for(int i = 0; i < x; i++) {
		cin >> t;
		ok[t] = true;
	}
	cin >> y;
	for(int i = 0; i < y; i++) {
		cin >> t;
		ok[t] = true;
	}
	bool possible = true;
	for(int i = 1; i <= n; i++) {
		if(!ok[i]) {
			possible = false;
			break;
		}
	}
	if(possible) {
		cout << "I become the guy." << endl;
	} else {
		cout << "Oh, my keyboard!" << endl;
	}
	return 0;
}

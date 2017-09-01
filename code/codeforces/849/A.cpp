#include <iostream>

using namespace std;
int n;
const int maxn = 105;
int a[maxn];
int cnt[2];
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(n % 2 == 0) {
		cout << "No" << endl;
		return 0;
	} 
	if(a[1] % 2 == 0 || a[n] % 2 == 0) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}

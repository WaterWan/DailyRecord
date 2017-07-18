#include <iostream>

using namespace std;

const int maxn = 105;

int main() {
	int n;
	cin >> n;
	int a[maxn];
	int pi;
	for(int i = 1; i <= n; i++) {
		cin >> pi;
		a[pi] = i;
	}
	cout << a[1];
	for(int i = 2; i <= n; i++) {
		cout << " " << a[i];
	}
	cout << endl;
}

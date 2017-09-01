#include <iostream>
#include <string>
using namespace std;
int n;

const string base = "abcdefghijklmnopqrstuvwxyz";
int a[1005];
int main() {
	a[1] = 0;
	for(int i = 2; i < 1005; i++) {
		a[i] = a[i-1] + i-1;
	}
	cin >> n;
	int cnt = 0;
	int ptr = 1004;
	if(n == 0) {
		cout << "a" << endl;
	}
	while(n > 0) {
		if(n >= a[ptr]) {
			n -= a[ptr];
			for(int i = 0; i < ptr; i++) {
				cout << base[cnt];
			}
			cnt++;
		} else {
			ptr--;
		}
		if(n == 0) {
			break;
		}
	}
	return 0;
}

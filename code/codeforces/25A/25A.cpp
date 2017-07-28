#include <iostream>

using namespace std;

const int maxn = 105;
int a[maxn];

int main() {
	int n;
	cin >> n;
	int even = 0;
	int odd = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}
	int index = -1;
	if(even == 1) {
		for(int i = n; i > 0; i--) {
			if(a[i] % 2 == 0) {
				index = i;
				break;
			}
		}
	} else {
		for(int i = n; i > 0; i--) {
			if(a[i] % 2 == 1) {
				index = i;
				break;
			}
		}
	}
	cout << index << endl;
} 

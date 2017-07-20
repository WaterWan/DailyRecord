#include <iostream>

using namespace std;

const int maxn = 105;

int main() {
	int n;
	int a[maxn];
	int b[maxn] = {0};
	int count[3] = {0, 0, 0};
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		b[i] = a[i+1] - a[i];
		if(b[i] > 0) {
			count[0]++;
		} else if(b[i] == 0) {
			count[1]++;
		} else {
			count[2]++;
		}
	}

	bool unimodal = true;
	for(int i = 0; i < count[0]; i++) {
		if(b[i] <= 0) {
			unimodal = false;
			break;
		}
	}
	for(int i = count[0]; i < count[0] + count[1]; i++) {
		if(b[i] != 0) {
			unimodal = false;
			break;
		}
	}
	for(int i = count[0] + count[1]; i < n - 1; i++) {
		if(b[i] >= 0) {
			unimodal = false;
			break;
		}
	}
	if(unimodal) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
}

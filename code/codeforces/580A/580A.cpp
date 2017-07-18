#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a;
	int last = 0;
	int count = 0;
	int max = 0;
	for(int i = 0; i < n; i++) {
		cin >> a;
		if(a >= last) {
			count++;
		} else {
			count = 1;
		}
		last = a;
		if(count > max) {
			max = count;
		}
	}
	cout << max << endl;
} 

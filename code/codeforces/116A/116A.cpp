#include <iostream>

using namespace std;

int main() {
	int max = 0;
	int n;
	int a, b;
	int count = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		count -= a;
		count += b;
		if(count > max) {
			max = count;
		}
	}
	cout << max << endl;
} 

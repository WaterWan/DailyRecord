#include <iostream>
#include <cmath>

using namespace std;

bool isLucky(int n) {
	int count = 0;
	while(n > 0) {
		if(n % 10) {
			count++;
		}
		n /= 10;
	}
	if(count > 1) {
		return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int len = (int)log10(n);
	int result = 1;
	for(int i = 0; i < len; i++) {
		result *= 10;
	}
	cout << (result - n % result) << endl;
}

#include <iostream>

using namespace std;

bool is_lucky(long long n);

int main() {
	long long n;
	cin >> n;
	int count = 0;
	while(n > 0) {
		if(n % 10 == 4 || n % 10 == 7) {
			count++;
		}
		n /= 10;
	}
	if(is_lucky(count)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

bool is_lucky(long long n) {
	if(!n) {
		return false;
	}
	while(n > 0) {
		if(!(n % 10 == 4 || n % 10 == 7)) {
			return false;
		}
		n /= 10;
	}
	return true;
}

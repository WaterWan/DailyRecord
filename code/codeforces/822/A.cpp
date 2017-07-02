#include <iostream>
using namespace std;

long long fact(long long x);

int main() {
	long long a, b;
	cin >> a >> b;
	if(a >= b) {
		cout << fact(b) << endl;
	} else {
		cout << fact(a) << endl;
	}
	return 0;
}

long long fact(long long x) {
	if(x == 1) {
		return 1;
	}
	return fact(x-1) * x;
}


#include <iostream>

using namespace std;

int main() {
	long long n, k;
	cin >> n >> k;
	long long result;
	if(k <= n - n / 2) {
		result = 2 * k - 1;
	} else {
		result = 2 * (k - n + n / 2);
	}
	cout << result << endl;
}

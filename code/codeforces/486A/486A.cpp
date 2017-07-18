#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	cout << (n % 2 == 1 ? "-" : "") << (n + 1) / 2<< endl;
}

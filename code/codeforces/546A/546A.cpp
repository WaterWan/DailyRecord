#include <iostream>

using namespace std;

int main() {
	int k, n, w;
	cin >> k >> n >> w;
	/**
	* (k+kw)*w/2 = 
	*
	**/
	int money = k * (w + 1) * w / 2 - n;
	cout << (money > 0 ? money : 0) << endl;
} 

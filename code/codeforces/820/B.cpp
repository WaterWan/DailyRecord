#include <iostream>

using namespace std;

int main() {
	int n, a;
	cin >> n >> a;
	/**
	* angle = 180 * (v3 - 2) / n = a
	* 180 * (v3 - 2) = n * a
	* v3 - 2 = n * a / 180
	* v3 = 2 + n * a / 180
	**/
	cout << "2 1 " << max(3, min(n, 2 + (n * a + 90) / 180)) << endl;
	return 0;
}

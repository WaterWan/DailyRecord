#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n % 2) {
		cout << "9 " << n - 9 << endl;
	} else {
		cout << "4 " << n - 4 << endl;
	}
	return 0;
} 

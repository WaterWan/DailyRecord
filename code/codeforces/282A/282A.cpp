#include <iostream>

using namespace std;

int main() {
	int n;
	char a, b, c;
	int x = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if(b == '+') {
			x++;
		} else {
			x--;
		}
	}
	cout << x << endl;
} 

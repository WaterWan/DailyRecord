#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int m[5];
	cin >> a >> b >> c;
	m[0] = a + b * c;
	m[1] = a * (b + c);
	m[2] = a * b * c;
	m[3] = (a + b) * c;
	m[4] = a + b + c;
	int max = 0;
	for(int i = 0; i < 5; i++) {
		if(m[i] > max) {
			max = m[i];
		}
	}
	cout << max << endl;
}

#include <iostream>

using namespace std;

int main() {
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int days = 0;
	int v = v0;
	while(true) {
		days++;
		c -= v;
		if(c <= 0) {
			break;
		}
		v += a;
		if(v > v1) {
			v = v1;
		}
		c += l;
	}
	cout << days << endl;
}

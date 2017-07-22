#include <iostream>

using namespace std;

int main() {
	int k, m;
	cin >> k >> m;
	int count = 0;
	while(k > 0) {
		k--;
		count++;
		if(count % m == 0) {
			k++;
		}
	}
	cout << count << endl;
}

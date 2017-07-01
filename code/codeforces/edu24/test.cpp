#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	freopen("test.txt", "r", stdin);
	int a[55];
	for(int i = 0; i < 51; i++) {
		cin >> a[i];
	}
	sort(a, a + 51);
	for(int i = 0; i < 51; i++) {
		if(i % 10 == 0) {
			cout << endl;
		}
		cout << a[i] << "\t";
	}
} 

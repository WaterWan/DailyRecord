#include <iostream>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long t = 5;
	string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
	int type;
	while(n > t) {
		n -= t;
		t *= 2;
	}
	long long re = t / 5;
	for(int i = 0; i < 5; i++) {
		if(1 + i * re <= n && n <= (i + 1) * re) {
			type = i;
		}
	}
	cout << names[type] << endl;
	
}

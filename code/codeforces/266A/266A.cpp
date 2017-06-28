#include <iostream>

using namespace std;

const int maxn = 55;

int main() {
	int n;
	char stone[maxn];
	cin >> n;
	int count = 0;
	char left = ' ';
	for(int i = 0; i < n; i++) {
		cin >> stone[i];
		if(stone[i] == left) {
			count++;
		} else {
			left = stone[i];
		}
	}
	cout << count << endl;
}

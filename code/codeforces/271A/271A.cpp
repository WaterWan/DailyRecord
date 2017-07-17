#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int exist[10];
	int n;
	cin >> n;
	for(int i = n + 1; ;i++) {
		int temp = i;
		bool flag = true;
		memset(exist, 0, sizeof exist);
		while(temp > 0) {
			if(exist[temp % 10]) {
				flag = false;
			}
			exist[temp % 10] = 1;
			temp /= 10;
		}
		if(flag) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
} 

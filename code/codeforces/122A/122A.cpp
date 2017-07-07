#include <iostream>

using namespace std;

int main() {
	int lucky_number[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
	int n;
	cin >> n;
	int temp = n;
	bool lucky = false;
	int len = sizeof(lucky_number)  / sizeof(lucky_number[0]);
	for(int i = 0; i < len; i++) {
		if(n == lucky_number[i]) {
			lucky = true;
			break;
		}
	}
	
	if(lucky) {
		cout << "YES" << endl;
		return 0;
	}
	
	bool almost_lucky = false;
	
	for(int i = 0; i < len; i++) {
		if(n < lucky_number[i]) {
			break;
		}
		if(n % lucky_number[i] == 0) {
			almost_lucky = true;
			break;
		}
	}
	if(almost_lucky) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
} 

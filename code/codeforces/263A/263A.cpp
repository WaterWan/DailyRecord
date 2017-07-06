#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int input[5][5];
	int result;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> input[i][j];
			if(input[i][j]) {
				result = abs(i - 2) + abs(j - 2);
			}
		}
	}
	cout << result << endl;
	return 0;
}

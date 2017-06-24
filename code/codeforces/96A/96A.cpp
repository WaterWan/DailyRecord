#include <iostream>
#include <string>

using namespace std;

int main() {
	string team;
	cin >> team;
	int len = team.length();
	char last = ' ';
	char now;
	int count = 0;
	for(int i = 0; i < len; i++) {
		now = team[i];
		if(now == last) {
			count++;
		} else {
			count = 1;
		}
		if(count >= 7) {
			cout << "YES" << endl;
			return 0;
		}
		last = now;
	}
	cout << "NO" << endl;
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	char input[] = "HQ9";
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < 3; j++) {
			if(s[i] == input[j]) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
}

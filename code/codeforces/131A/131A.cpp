#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	bool caps = true;
	for(int i = 1; i < s.length(); i++) {
		if('a' <= s[i] && s[i] <= 'z') {
			caps = false;
			break;
		}
	}
	if(caps) {
		for(int i = 0; i < s.length(); i++) {
			if('a' <= s[i] && s[i] <= 'z') {
				s[i] += 'A' - 'a';
			} else {
				s[i] += 'a' - 'A';
			}
		}
	}
	cout << s << endl;
} 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(const char c);

int main() {
	string input;
	cin >> input;
	int len = input.size();
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	for(int i = 0; i < len; i++) {
		if(isVowel(input[i])) {
			continue;
		}
		cout << "." << input[i];
	}
	cout << endl;
}

bool isVowel(const char c) {
	string s = "aoyeui";
	int len = s.size();
	for(int i = 0; i < len; i++) {
		if(c == s[i]) {
			return true;
		}
	}
	return false;
}

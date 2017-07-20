#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int cap = 'A' - 'a';
	map<char, char> letter_map;
	string s1;
	string s2;
	string s3;
	cin >> s1 >> s2 >> s3;
	for(int i = 0; i < 26; i++) {
		letter_map[s1[i]] = s2[i];
	}
	for(int i = 0; i < s3.size(); i++) {
		if('a' <= s3[i] && s3[i] <= 'z') {
			cout << letter_map[s3[i]];
		} else if('A' <= s3[i] && s3[i] <= 'Z') {
			cout << (char)(letter_map[s3[i] - cap] + cap);
		} else {
			cout << s3[i];
		}
	}
	cout << endl;
}

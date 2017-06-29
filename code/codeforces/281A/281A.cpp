#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	if(s[0] >= 'a' && s[0] <= 'z') {
		// x - s[0] = 'A' - 'a'
		// x = s[0] + 'A' - 'a'
		s[0] += 'A' - 'a';
	}
	cout << s << endl;
} 

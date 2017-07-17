#include <iostream>
#include <string>

using namespace std;

string reverse(string s);

int main() {
	string s, t;
	cin >> s >> t;
	cout << (reverse(s) == t ? "YES" : "NO") << endl;
}

string reverse(string s) {
	string result = "";
	for(int i = s.size() - 1; i >= 0; i--) {
		result += s[i];
	}
	return result;
}

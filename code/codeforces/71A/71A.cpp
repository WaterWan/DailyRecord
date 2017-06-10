#include <iostream>
#include <string>
#include <sstream>

#define MAXN 100

using namespace std;

string trans(string s);

int main() {
	int n;
	cin >> n;
	string s[MAXN];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
//		cout << s[i] << endl;
		cout << trans(s[i]) << endl;
	}
} 

string trans(string s) {
	if(s.size() <= 10) {
		return s;
	}
	stringstream ss;
	ss << s[0] << s.size() - 2 << s[s.size() - 1];
	return ss.str();
}

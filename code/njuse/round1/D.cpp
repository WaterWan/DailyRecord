#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int count = 0;
	for(int i = 0; i < len / 2; i++) {
		if(s[i] != s[len - 1 - i]) {
			count++;
		}
	}
	bool ok = true;
	if(count > 1) {
		ok = false;
	} else if((count == 0) && (len % 2 == 0)) {
		ok = false;
	}
	if(ok) {
		cout << "YES" << endl; 
	} else {
		cout << "NO" << endl;
	}
}

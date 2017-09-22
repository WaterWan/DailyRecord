#include <iostream>
#include <sstream>

using namespace std;

string itos(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}

bool palindromic(string s) {
	int len = s.size();
	for(int i = 0; i <= len / 2; i++) {
		if(s[i] != s[len - 1 - i] ) {
			return false;
		}
	}
	return true;
}

int main() {
	int x;
	cin >> x;
	while(x % 10 == 0) {
		x /= 10;
	}
	if(palindromic(itos(x))) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	
}



#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	string hello = "hello";
	cin >> s;
	int hello_count = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == hello[hello_count]) {
			hello_count++;
		}
	}
	if(hello_count == 5) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

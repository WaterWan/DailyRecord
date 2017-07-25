#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s1, s2;
	s2 = "";
	int count = 0;
	for(int i = 0; i < n; i++) {
		cin >> s1;
		if(s1 != s2) {
			count++;
		}
		s2 = s1;
	}
	cout << count << endl;
}

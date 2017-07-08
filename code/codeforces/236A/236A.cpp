#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	set<char> name_set;
	for(int i = 0; i < s.length(); i++) {
		name_set.insert(s[i]);
	}
	if(!(name_set.size() % 2)) {
		cout << "CHAT WITH HER!" << endl;
	} else {
		cout << "IGNORE HIM!" << endl;
	}
	return 0;
}

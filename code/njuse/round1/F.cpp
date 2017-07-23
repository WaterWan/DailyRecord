#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 55;

int comp(string s1, string s2) {
	string s = s1 + s1;
	for(int i = 0; i < s2.length(); i++) {
		if(s2 == s.substr(i, s2.length())) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n;
	string s[maxn];
	int count[maxn];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		count[i] = 0;
	}
	
	for(int i = 0; i < n; i++) {
		string t = s[i];
		for(int j = 0; j < n; j++) {
			if(comp(t, s[j]) == -1) {
				cout << -1 << endl;
				return 0;
			} else {
				count[j] += comp(t, s[j]);
			}
		}
	}
	cout << *min_element(count, count + n) << endl;
}

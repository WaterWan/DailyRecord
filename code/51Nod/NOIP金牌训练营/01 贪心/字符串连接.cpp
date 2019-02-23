#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cmp(string s1, string s2) {
	return s1 + s2 < s2 + s1;
}
const int maxn = 110;
string s[maxn];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s+n, cmp);
	string res;
	for(int i = 0; i < n; i++) {
		res += s[i];
	}
	cout << res;
	return 0;
}

/**
ID: Wan Zhong
TASK: contact 
LANG: C++11
**/

#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> m;
void work(string s, int max_len) {
	int len = s.length();
	string t = s.substr(0, max_len - 1);
	for(int i = max_len - 1; i < len; i++) {
		t += s[i];
		m[t]++;
		t = t.substr(1);
	}
}
map<int, vector<string> > m2;
bool cmp(string s1, string s2) {
	if(s1.length() != s2.length()) {
		return s1.length() < s2.length();
	}
	return s1 < s2;
}
int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	int A, B, N;
	cin >> A >> B >> N;
	string s;
	string t;
	while(cin >> t) {
		s += t;
	}
	for(int i = A; i <= B; i++) {
		work(s, i);
	}
	for(auto it = m.begin(); it != m.end(); it++) {
		if(m2.count(it->second) == 0) {
			vector<string> l;
			l.push_back(it->first);
			m2[it->second] = l;
		} else {
			m2[it->second].push_back(it->first);
		}
	}
	int cnt = 0;
	for(auto it = m2.rbegin(); it != m2.rend(); it++) {
		cnt++;
		if(cnt > N) {
			break;
		}
		cout << it->first << endl;
		vector<string> l = it->second;
		sort(l.begin(), l.end(), cmp);
		for(int i = 0; i < l.size() - 1; i++) {
			cout << l[i] << " \n"[(i + 1) % 6 == 0];
		}
		cout << l[l.size() - 1];
		cout << "\n";
	}
	return 0;
}

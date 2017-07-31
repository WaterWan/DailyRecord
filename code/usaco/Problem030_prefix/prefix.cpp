/**
ID: Wan Zhong
TASK: prefix
LANG: C++
**/ 
#include <iostream>
#include <stdio.h>
#include <string.h>
const int maxn = 205;
const int maxl = 200005;
 
using namespace std;
 
int n = 0;
int ans = 0;
bool dp[maxl];
string s;
string p[maxn];
 
int main() {
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	while(cin >> p[n]) {
		if(p[n] == ".") {
			break;	
		} 
		n++;
	}
	string temp;
	while(cin >> temp) {
		s += temp;
	}	
	memset(dp, 0 ,sizeof dp);
	dp[0] = true;
	for(int i = 0, t = s.size(); i < t; i++) {
		if(dp[i]) {
			for(int j = 0; j < n; j++) {
				bool flag = true;
				for(int k  =0; k < p[j].size(); k++) {
					if(s[k+i] != p[j][k]) {
						flag = false;
						break;
					}
				}
				if(flag) {
					dp[i+p[j].size()]=true;
				}
			}
		}
	}
	for(int i = 0; i <= s.size();i++) {
		if(dp[i]) ans=i;
	}
	cout << ans << endl;
	return 0;
}



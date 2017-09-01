#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>


using namespace std;
const int maxn = 1005;

typedef long long LL;
LL y[maxn];
int n;
bool visited[maxn];

bool check(int p1,int p2);


int main(){
	cin >> n;
	for (int i = 0;i < n; i++){
		cin >> y[i];
	}
	string res;
	if (check(0,1)){
		res = "Yes";
	} else if(check(0,2)) {
		res = "Yes";
	} else if(check(1,2)) {
		res = "Yes";
	} else {
		res = "No";
	}
	cout << res << endl;
	return 0;
}

bool check(int p1,int p2){
	LL dx = p2 - p1;
	LL dy = y[p2] - y[p1];
	memset(visited, 0, sizeof visited);
	visited[p1] = visited[p2] = true;
	for (int i = 0; i < n; i++){
		double t1 = (i - p1) * dy;
		double t2 = (y[i]-y[p1]) * dx;
		if (!visited[i] && t1 == t2){
			visited[i] = true;
		}
	}
	bool ok = false;
	LL x0, y0;
	for (int i = 0;i < n;i++){
		if (!visited[i] && ok){
			double t1 = (i - x0)*dy;
			double t2 = (y[i] - y0)*dx;
			if (t1 == t2){
				continue;
			}else{
				return false;
			}
		}
		if (!ok && !visited[i]){
			ok = true;
			x0 = i;
			y0 = y[i];
		}
	}
	if (ok){
		return true;
	}else{
		return false;
	}
}

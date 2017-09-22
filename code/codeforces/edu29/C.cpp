#include <iostream>
#include <cstring>
typedef long long ll;
using namespace std;

int A[4][4];
int B[4][4];
const int maxn = 1000;
ll visit[maxn]; // a * 4 + b
ll record[maxn][2];
int a, b;
ll a_point = 0;
ll b_point = 0;

int main() {
	ll k;
	cin >> k;
	cin >> a >> b;
	memset(visit, 0, sizeof visit);
	memset(record, 0, sizeof record);
	int n = 3;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> B[i][j];
		}
	}

	ll t = 1;
	while(t < k + 1) {
		
		int t1 = a;
		int t2 = b;
		if(a > b) {
			if(a == 3 && b == 1) {
				b_point++;	
			} else {
				a_point++;
			}
		} else if(a < b) {
			if(b == 3 && a == 1) {
				a_point++;
			} else {
				b_point++;
			}
		}
		int temp = a * 4 + b;
		if(!visit[temp]) {
			visit[temp] = t;
			record[t][0] = a_point;
			record[t][1] = b_point;
		} else {
			ll start = visit[temp];
			ll last = visit[temp] - 1;
			ll end = t - 1;
			a_point = record[last][0] + (k - last) / (end - last) * (record[end][0] - record[last][0]);
			b_point = record[last][1] + (k - last) / (end - last) * (record[end][1] - record[last][1]);
			ll remain = (k - last) % (end - last);
			a_point += record[start + remain - 1][0] - record[last][0];
			b_point += record[start + remain - 1][1] - record[last][1];
			break;
		}
		a = A[t1][t2];
		b = B[t1][t2];
		t++;
	}
	cout << a_point << " " << b_point << endl;
}

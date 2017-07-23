#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
#define INF 0x3f3f3f3f
char s[MAXN][MAXN];
long long ans [MAXN][3];
int m,n;
long long step(int tar,int mo){
	return min (tar,mo-tar);
}
int main(){
	cin>>n>>m;
	for (int i=0;i<n;i++){
		ans[i][0]= ans[i][1]= ans [i][2]=INF;
	}
	for (int i=0;i<n;i++){
		scanf("%s",s[i]);
		for (int j=0;j<m;j++){
			char temp = s[i][j];
			if (temp>='0'&&temp<='9'){
				ans[i][0]= min(ans[i][0],step(j,m));
			}else if (temp>='a'&&temp<='z'){
				ans[i][1]= min (ans [i][1],step(j,m));
			}else if (temp =='#'||temp == '*'||temp == '&'){
				ans [i][2] = min(ans[i][2],step(j,m));
			}
		}
	}
	long long anss = INF;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			for (int k = 0;k<n;k++){
				if (i!=j&&i!=k&&j!=k){
					long long temp = ans[i][0]+ans[j][1]+ans[k][2];
					anss = min (anss ,temp);
				}
			}
		}
	}
	cout<<anss<<endl;
	return 0;
}



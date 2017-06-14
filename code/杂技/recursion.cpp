#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int n;
vector<int> List;
bool visit[MAXN];
void dfs(int depth){
	if (depth==n+1){
		for (int i : List){
			cout<<i<<" ";
		}
		cout<<endl;
		return ;
	}
	for (int i=1;i<=n;i++){
		if (visit[i]){
			continue;
		}
		List.push_back(i);
		visit[i]=true;
		dfs(depth+1);
		List.pop_back();
		visit[i]=false;
	}
}
int main(){
	cin>>n;
	memset(visit,false,sizeof(visit));
	dfs(1);
	return 0;
} 

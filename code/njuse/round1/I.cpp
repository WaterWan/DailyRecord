#include <iostream>
#include <cstring>
#include <vector>

using namespace std;  

const int maxn = 105;

int main() { 
	vector<int> v; 
	int n;
	int b[maxn];
	int t, m; 
  
	memset(b, 0, sizeof b);
    cin >> n >> m;  
    for(int i = 1;i <= n;i++) {
        v.push_back(i);  	
	} 
	
	int p = 0; 
    for(int i = 1; i <= m; i++){  
        cin >> t;  
        p = (p + t) % n;  
        b[i] = v[p];  
        for(int j = p; j < n - 1; j++) {
        	v[j]=v[j+1];  
		}
        v.pop_back();  
        n--;  
    }  
    
    cout << b[1];
    
    for(int i = 2; i <= m; i++) {
        cout << " " << b[i]; 	
	} 
    cout << endl;
    return 0;
}

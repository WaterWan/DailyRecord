#include<iostream>  

using namespace std; 
 
int fact[100];  

int main() {  
  
    int n, k;
	int count = 0; 
    cin >> n >> k;  
    int temp = n;
    if(k == 1) {  
        cout << n << endl;  
        return 0;  
    } 
	
	int i = 2;
	int re = 1;
	while(n != 1) {
		while(n % i == 0) {
			n /= i;
			fact[count++] = i;
		}
		i++;
		if(count == k) {
			break;
		}
	} 

	if(fact[count] != 1 && count >= k) {
		for(int q = 0; q < k - 1; q++) {
			cout << fact[q] << " ";
			re *= fact[q];
		}
		cout << temp / re << endl;
		return 0;
	}
	cout << "-1" << endl;
}  

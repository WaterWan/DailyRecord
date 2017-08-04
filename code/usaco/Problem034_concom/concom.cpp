/**
ID: Wan Zhong
TASK: concom
LANG: C++11
**/ 
// copy from haolink1
//Main Idea:  
//brute force;  
//shares[i][j] is the initial shares company i own for company j;  
//fianl_shares[i][j] is the shares company i own for j after calculate;  
//used[i][j] == 1 denote i control j to avoid repeated computation; 
#include <stdio.h>  
#include <fstream>
using namespace std;  
  
const int com = 100;  
int shares[com][com], final_shares[com][com];  
bool  used[com][com];  
  
int main(){  
    freopen("concom.in", "r", stdin); 
	freopen("concom.out", "w", stdout); 
    int num;  
    scanf("%d", &num);  
    int com_1; 
	int com_2;  
    for(int i = 0; i < num ; i++){  
    	scanf("%d%d", &com_1, &com_2);
    	scanf("%d", &shares[com_1-1][com_2-1]);
        final_shares[com_1-1][com_2-1] = shares[com_1-1][com_2-1];  
    }  
      
    bool flag = true;  
    while(flag){  
        flag = false;  
        for(int i = 0; i < com; i++){  
            for(int j = 0; j < com; j++){  
                if(used[i][j] == 0 && final_shares[i][j] > 50 && i != j){  
                    //used[i][j] = used[j][i] = 1;  
                    used[i][j] = true;  
                    flag = true;  
                    for(int k = 0; k < com; k++){  
                        if(k != i && k != j) {// now company i got company k's share that j own;  
                            final_shares[i][k] += shares[j][k]; 
						}
                    }  
                }  
            }  
        }  
    }  
    flag = true;  
    ofstream fout("concom.out");  
    for(int i = 0; i < com; i++){  
        for(int j = 0; j < com; j++){  
            if(final_shares[i][j] > 50 && i != j){  
            	printf("%d %d\n", i+1, j+1);
                flag = false;  
            }  
        }  
    }  
    if(flag) {
    	printf("0\n");
	}  
    return 0;  
} 

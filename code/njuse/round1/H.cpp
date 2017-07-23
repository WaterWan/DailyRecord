#include <iostream>  
#include <map>
#include <string>
#include <cmath>
  
using namespace std;  

const int maxn = 100005;  
  
long long b1, q, l, m;
  
map<long long, bool> bad_num;  

int main() {  
    cin >> b1 >> q >> l >> m;  
    long long temp;  
    for(int i = 0; i < m; ++i) {  
        cin >> temp;
        bad_num[temp] = true;  
    }  
  	string result;
  	/**
  	* 1.����Ϊ0�������
	  	1.1 ������ܳ���0����ô������
		1.2 0 
  	* 2.���Ϊ0, ����Ϊ0����ʱ���оͱ����b1, 0, 0, 0, 0,���� 
  	*	��ʱҪ��ע�������Ƿ��ˣ�����ǳ�����ô���о��˻���b1 
  	* 3.���Ϊ0������Ϊ��1 
  	  3.1 1����ʱ�����˻�Ϊb1, b1, b1���� 
  	*
  	*/
    if(b1 == 0) {  
        if(!bad_num[0]) {
        	result = "inf";
		} else {
			result = "0";
		}
    } else if(q == 0) {  
        if(abs(b1) > l) {
        	result = "0";
		} else {  
            if(!bad_num[0]) {
            	result = "inf";
			} else {  
                if(!bad_num[b1]) {
                	result = "1";	
				} else {
					result = "0";
				}
            }  
        }  
    } else if(abs(b1) <= l && abs(q) == 1) {  
        if(q==1) {  
            if(!bad_num[b1]) {
            	result = "inf";
			} else {
				result = "0";
			}   
        } else {  
            if(bad_num[b1] && bad_num[-1 * b1]) {
            	result = "0";
			} else {
				result = "inf";
			}  
        }  
    } else {  
        long long count = 0;  
        long long t = b1;  
        while(abs(t) <= l) {  
            if(!bad_num[t]) {
            	count++;
			}  
            t *= q;  
        }  
        cout << count << endl;
		return 0;  
    } 
    cout << result << endl;
    return 0;  
}  

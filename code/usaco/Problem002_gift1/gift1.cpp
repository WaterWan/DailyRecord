/*
ID:njuwz151
LANG:C++
TASK:gift1
*/
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <list>
#include <utility>

using namespace std;

int main() {
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int np;
	cin >> np;
	string *name = new string[np];
	map<string, int> money;
	list<string> nameList;
	for(int i = 0; i < np; i++) {
		cin >> name[i];
		money.insert(pair<string, int>(name[i], 0));
		nameList.push_back(name[i]);
	}
	string give;
	while(cin >> give) {

		int gift, num;
		cin >> gift >> num;
		if(gift == 0 && num == 0) {
			continue;
		}
		money[give] -= gift / num * num;
		string receive;
		for(int i = 0; i < num; i++) {
			cin >> receive;
			money[receive] += gift / num; 
		}
	}

	

	
	for (list<string>::iterator ii= nameList.begin(); ii != nameList.end(); ++ii) {  
        string temp = *ii;
		cout << temp << " " <<  money[temp] << endl;
    } 
	
	return 0;

}

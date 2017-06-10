#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int N;

bool close(int a, int b)
{
  if (abs(a-b) <= 2) return true;
  if (abs(a-b) >= N-2) return true;
  return false;
}

bool close_enough(int n1, int n2, int n3,
		  int c1, int c2, int c3)
{
  return close(n1,c1) && close(n2,c2) && close(n3,c3);
}

int main(void)
{
  int f1, f2, f3;
  int m1, m2, m3;

  ifstream fin("combo.in");
  fin >> N;
  fin >> f1 >> f2 >> f3;
  fin >> m1 >> m2 >> m3;
  fin.close();

  int total = 0;
  for (int n1=1; n1<=N; n1++)
    for (int n2=1; n2<=N; n2++)
      for (int n3=1; n3<=N; n3++)
	if (close_enough(n1,n2,n3,f1,f2,f3) ||
	    close_enough(n1,n2,n3,m1,m2,m3))
	  total++;

  ofstream fout("combo.out");
  fout << total << "\n";
  fout.close();

  return 0;
}

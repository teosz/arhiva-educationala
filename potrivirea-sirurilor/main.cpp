#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream in("strmatch.in");
ofstream out("strmatch.out");
string a,b;
int n,m, total;
int *v;
int p[1000];
void citire()
{

  getline(in,a);
  getline(in,b);
}
void urm()
{
  int j;
  p[0] = -1;
  j = -1;
  for(int i=0;i<=n;i++)
  {
    while(j>=0 && a[i] != a[j])
    {
      j = p[j];
    }

    j++;
    p[i+1] = j;
  }

}
int poz(int j)
{
  for(int i=1;i<=n;i++)
  {
    if(a[i-1] != b[j+i-1])
      return i;
  }
  return -1;
}
void match()
{
  int j=0;
  while(j<m && j>=0)
  {
    int match = poz(j)-1;
    if(match  == -1)
    {
       out << j;
       j =
    }
    else
    {
      cout << "(" << j << ") ";
      cout << "failed at " << match <<" ";
      cout << "fail = " << p[match] << " ";
      cout << "jump by " << match - p[match] << "\n";
      j += match- p[match];
    }
  }

}
int main()
{
  citire();
  n = a.length();
  m = b.length();

  urm();
  match();

  in.close();
  out.close();
}

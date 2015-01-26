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
bool search(int i)
{
  for(int j=1;j<=n;j++)
    if(a[j-1] != b[j+i-1])
      return 0;
  return 1;
}
void prefix()
{
  for(int i=1;i<=n;i++)
  {
    int k=0;
    while(k>0 && a[k+1] != a[k])
      k = p[k];
    if(a[k+1] == a[k])
        k++;
    p[i] =k;
  }
}
void match()
{
  int q=0;
  for(int i=1;i<=m;i++)
  {
    while(q>0 && a[q-1] != b[i])
      q = p[q];
    if(a[q+1] == b[i])
      q++;
    out << q << " " << i << "\n";
    if(q==n)
      out <<i;
  }
}
int main()
{
  citire();
  n = a.length();
  m = b.length();
  v = new int[n];
  prefix();
  for(int i=1;i<=n;i++)
    out << p[i] << " ";
  //match();
  // out << total<<"\n";
  // for(int i=1;i<=total;i++)
  //   out << v[i] << " ";
  in.close();
  out.close();
}

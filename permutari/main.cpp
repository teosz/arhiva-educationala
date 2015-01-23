#include <iostream>
#include <fstream>
using namespace std;
ifstream in("permutari.in");
ofstream out("permutari.out");
const int K=4000000;
int n, st[9];
int valid(int k)
{

  for(int i=1;i<k;i++)
    if(st[i] == st[k])
      return 0;
   return 1;


}
int back(int k)
{

  if(k==n+1)
  {
    for(int i=1;i<k;i++)
      out << st[i] << " ";
    out << "\n";
    return 0;
  }
  for(int i=1;i<=n;i++)
  {
    st[k] = i;
    if(valid(k))
      back(k+1);
  }
}
int main()
{

  in >> n;
  back(1);
  return 0;
}

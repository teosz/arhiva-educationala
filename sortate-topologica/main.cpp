#include <fstream>
using namespace std;
ifstream in("sortaret.in");
ofstream out("sortaret.out");
const int N=10001;
const int M=100001;
int a[N][N];
int n,m, v[N];
void citire()
{
  in >> n >> m;
  for(int i=1;i<=m;i++)
  {
    int x,y;
    in >> x >> y;
    a[x][y] = 1;
  }
}
void  afisare()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
        out << a[i][j] << " ";
    out << "\n";
  }
}
void dfs(int i)
{
  for(int j=1;j<=n;j++)
  {
    if(a[i][j])
      {

        dfs(j);
        
      }
  }
  if(v[i] == 0)
  {
  out << i;
  v[i] = 1;
  }

}
int main()
{

  citire();
  for(int i=1;i<=n;i++)
  {

    dfs(i);

  }
  return 0;
}

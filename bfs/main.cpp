#include <fstream>
#include <vector>
#include <queue>
// #include <cstdlib>
#include <cstring>

using namespace std;
ifstream in("bfs.in");
ofstream out("bfs.out");
const int N=1012465;
vector<int> a[N];
queue<int> q;
int n,m,s;
int g[N], cost[N];

void citire()
{
  in >> n >> m >> s;
  for(int i=1;i<=m;i++)
  {
    int x,y;
    in >> x>>y;
    a[x].push_back(y);
  }

}
void bfs(int s)
{
  // fill(cost, cost+n, -1);
  // /out << q
  memset(cost, -1, sizeof(cost));
  q.push(s);
  cost[s] = 0;
  while(!q.empty())
  {
    int x =  q.front();
    q.pop();
    // out << x;
    // out << g[x];
    for(int i=0;i<g[x];i++)
    {
      // out << cost[5];
      // out << a[x][i];
      if(cost[a[x][i]] == -1)
      {
          // out << i;
          cost[a[x][i]] = cost[x] + 1;
          q.push(a[x][i]);
      }
    }

  }
}
int main()
{
  citire();
  for(int i=1;i<=m;i++)
    g[i] = a[i].size();
  bfs(s);
  for(int i=1;i<=n;i++)
    out << cost[i] << " ";
  in.close();
  out.close();
  return 0;
}

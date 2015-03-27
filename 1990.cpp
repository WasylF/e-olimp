//solution by Wsl_F
#include <bits/stdc++.h>

using namespace std;


typedef vector<int> vi;

#define pb(x)  push_back(x)
#define F(i,j) ( ( (i)-1 )*m + (j)-1 )

const int MaxN= 100;

int next_[MaxN*MaxN+100];
bool used[MaxN*MaxN+100];

int board[MaxN+10][MaxN+10];

vi g[MaxN*MaxN+100];


bool try_kuhn (int v)
{
   if (used[v])  return false;
   used[v] = true;
   for (int i=0; i<g[v].size(); i++)
   {
       int to = g[v][i];
       bool f= (next_[to] == -1);

       if (!f) f= try_kuhn(next_[to]);
       if (f)
       {
           next_[to] = v;
           return true;
       }
   }
   return false;
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

int n,m,a,b;
cin>>n>>m;
char c;


int empt= 0;
memset(board,-1,sizeof(board));

for (int i=1; i<=n; i++)
   for (int j=1; j<=m; j++)
   {
       cin>>c;
       if (c=='.') { board[i][j]= 0; empt++; }
       else board[i][j]= 1;
   }

if (empt%2)
{
   cout<<"NO"<<endl;
   return 0;
}

for (int i=1; i<=n; i++)
   for (int j= 1; j<=m; j++)
       if (board[i][j]==0 && ((i&1)==(j&1)))
       {
           int u= F(i,j);
           {
               if (board[i][j-1]==0) g[u].pb(u-1);
               if (board[i][j+1]==0) g[u].pb(u+1);
               if (board[i-1][j]==0) g[u].pb(u-m);
               if (board[i+1][j]==0) g[u].pb(u+m);
           }
       }

int sum= 0;

memset(next_,-1,sizeof(next_));
for (int i=1; i<=n; i++)
   for (int j= 1; j<=m; j++)
    if (board[i][j]==0 && ((i&1)==(j&1)))
    {
       memset(used,0,sizeof(used));
       if (try_kuhn(F(i,j))) sum++;
    }

if (sum*2==empt) cout<<"YES"<<endl;
else cout<<"NO"<<endl;

return 0;
}

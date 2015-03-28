//solution by Wsl_F
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <cassert>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <complex>
#include <utility>
#include <climits>
#include <cctype>
#include <x86intrin.h>



using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))


const int MaxN= 2500;
vi g[MaxN+10];
int d[MaxN+10];
int prev_[MaxN+10];

int dfs(int v, int del)
{
   memset(d,63,sizeof(d));
   d[v]= 0; d[del]= -1;
   queue<int> q;
   q.push(v);
   while (!q.empty())
   {
       v= q.front(); q.pop();
       for (int i= g[v].size()-1; i>=0; i--)
           if (d[v]+1<d[g[v][i]])
           {
               d[g[v][i]]= d[v]+1;
               q.push(g[v][i]);
               prev_[g[v][i]]= v;
           }
   }
   return v;
}

int getNewDiametr(int v, int u)
{
   int v1= dfs(v,u);
   int d1= d[dfs(v1,u)];
   int u1= dfs(u,v);
   int d2= d[dfs(u1,v)];
   return max((d1+1)/2+(d2+1)/2+1,max(d1,d2));
}

int getCentr(int v, int u)
{
   int v1= dfs(v,u);
   v= dfs(v1,u);
   int d1= d[v];
   d1= (d1+1)/2;

   for (int i=0; i<d1; i++)
       v= prev_[v];
   return v;
}

void getCentres(int v, int u, int &V, int &U)
{
   V= getCentr(v,u);
   U= getCentr(u,v);
}


int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
srand(__rdtsc());
// LL a[110];
// memset(a,0,sizeof(a));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<fixed;
//cout<<setprecision(9);
//cout<<(int)'a'<<" "<<(int)'A'<<endl;
int n;
cin>>n;

int a,b;
for (int i= 1; i<n; i++)
{
   cin>>a>>b;
   g[a].pb(b);
   g[b].pb(a);
}

int ans= n;
int ansV= 0, ansU= 0;
for (int i=1; i<=n; i++)
   for (int j= g[i].size()-1; j>=0; j--)
       if (i<g[i][j])
       {
           int tmp= getNewDiametr(i,g[i][j]);
           if (tmp<ans)
           {
               ans= tmp;
               ansV= i;
               ansU= g[i][j];
           }
       }

cout<<ans<<endl;
cout<<ansV<<" "<<ansU<<endl;
int V,U;
getCentres(ansV,ansU,V,U);
cout<<V<<" "<<U<<endl;

return 0;
}

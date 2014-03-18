//solution by Wsl_F
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define author Wsl_F
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>


using namespace std;

typedef long long LL;

#define MAX  1000000
#define LMAX 78500

LL f[MAX+10];
LL primes[LMAX+10];
LL cnt=0;

void init(LL n)
{
 for (LL i=0; i<=n; i+=2)
    f[i]= 0;
 for (LL i=3; i<=n; i+=2)
    f[i]= 1;
 f[2]= 2;
}

void EratosfenSieve(LL n)
{
    init(n);
    primes[cnt++]= 2;

    for (LL i= 3; i<=n; i+= 2)
        if (f[i])
        {
            primes[cnt++]= i;
            for (LL j= i*1LL*i; j<=n; j+=i)
                f[j]= 0;
        }
}


LL solve(LL n)
{
 if (n==0) return 0;
 if (n==1) return 0;


 LL pw= log2(n);
 LL ans=0;
 for (LL st= pw; st>1; st--)
 {
  LL t= pow(n,1/st);
  while (pow(t,st)>n) t--;
  while (pow(t+1,st)<=(n+0.5)) t++;

  LL *j= lower_bound(primes,primes+cnt,t);
  while (*j>t) j--;

  ans+= (j-primes+1);

 }

 return ans;
}

int main()
{

 ios_base::sync_with_stdio(0);
// LL a[110];
// memset(a,0,sizeof(a));

 freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);


 EratosfenSieve(MAX);
 //cout<<cnt<<endl;


 LL t,low,high;
 cin>>t;
 for (LL T=0; T<t; T++)
 {
     cin>>low>>high;
     cout<<solve(high)-solve(low-1)<<endl;
 }
 return 0;
}

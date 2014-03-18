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

int f[MAX+10];
int primes[LMAX+10];
int cnt=0;

void init(int n)
{
for (int i=0; i<=n; i+=2)
   f[i]= 0;
for (int i=3; i<=n; i+=2)
   f[i]= 1;
f[2]= 2;
}

void EratosfenSieve(int n)
{
   init(n);
   primes[cnt++]= 2;

   for (int i= 3; i<=n; i+= 2)
       if (f[i])
       {
           primes[cnt++]= i;
           for (LL j= i*1LL*i; j<=n; j+=i)
               f[j]= 0;
       }

    primes[cnt]= 2*1000*1000*1000; //2*10^9
}


int chek(LL n)
{

if (n==1) return 0;

for (int i=0; (i<cnt&&primes[i]<=n); i++)
{
    if (!(n%primes[i]))
    {
        if (n==primes[i]) return 0;
        while (n%primes[i]==0) n/=primes[i];
        if (n!=1) return 0;
        else return 1;
    }
}

return 0;

}

int main()
{

ios_base::sync_with_stdio(0);
// int a[110];
// memset(a,0,sizeof(a));

freopen("input.txt","r",stdin);
freopen("output_brut.txt","w",stdout);


EratosfenSieve(MAX);
//cout<<cnt<<endl;

int t,low,high;
cin>>t;
for (int T=0; T<t; T++)
{
    cin>>low>>high;
    LL ans=0;

    for (int i= low; i<=high; i++)
    {
       //ans+= chek(i);
       if (chek(i)) { /*cout<<i<<" "; */ ans++; }
    }
    cout<<ans<<endl;
}
return 0;
}

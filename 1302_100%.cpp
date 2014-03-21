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
#define LMAX 80070
#define INF 1000000000000LL     //10^12

LL f[MAX+10];
LL nearPrimes[LMAX+10];
LL cnt=0;

void init(LL n)
{
for (LL i=0; i<=n; i+=2)
   f[i]= 0;
for (LL i=3; i<=n; i+=2)
   f[i]= 1;
f[2]= 2;
}

void addPrime(LL n)
{
LL t=n*n;
while (t>0 && t<INF)
{
    nearPrimes[cnt++]= t;
    t*= n;
}
}

void EratosfenSieve(LL n)
{
   init(n);
   cnt= 0;
   addPrime(2);

   for (LL i= 3; i<=n; i+= 2)
       if (f[i])
       {
           addPrime(i);
           for (LL j= i*1LL*i; j<=n; j+=i)
               f[j]= 0;
       }
}


int main()
{

ios_base::sync_with_stdio(0);
// LL a[110];
// memset(a,0,sizeof(a));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);


EratosfenSieve(MAX);
//cout<<cnt<<endl;

sort(nearPrimes,nearPrimes+cnt);
nearPrimes[cnt]= INF+1;

int T;
LL low,high;
cin>>T;
for (int t=0; t<T; t++)
{
    cin>>low>>high;
    LL* L= lower_bound(nearPrimes,nearPrimes+cnt,low);
    LL* R= upper_bound(nearPrimes,nearPrimes+cnt,high);
    cout<<LL(R-L)<<endl;
}
return 0;
}

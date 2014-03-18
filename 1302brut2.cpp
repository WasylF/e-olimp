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


int сheck(LL n)
{

if (n==1) return 0;
LL sqrtn= sqrt(n);

for (int i=2; i<=sqrtn; i++)
{
    if (n%i==0)
    {
        if (n==i) return 0;
        while (n%i==0) n/=i;
        if (n!=1) return 0;
        else return 1;
    }
}

return 0;

}

int main()
{

ios_base::sync_with_stdio(0);

freopen("input.txt","r",stdin);
freopen("output_brut.txt","w",stdout);

int t,low,high;
cin>>t;
for (int T=0; T<t; T++)
{
    cin>>low>>high;
    LL ans=0;

    for (int i= low; i<=high; i++)
       if (check(i)) { ans++; /*cout<<i<<" "; */}

    cout<<ans<<endl;
}
return 0;
}

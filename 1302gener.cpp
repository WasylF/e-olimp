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
#include <x86intrin.h>


using namespace std;

typedef long long LL;

#define MAX  1000000
#define LMAX 78500

int main()
{

 ios_base::sync_with_stdio(0);
// LL a[110];
// memset(a,0,sizeof(a));

 //freopen("input.txt","r",stdin);
 freopen("input.txt","w",stdout);
 srand(__rdtsc());


 LL t,low,high;
// cin>>t;
 t= 10;
 cout<<t<<endl;
 for (LL T=0; T<t; T++)
 {
     low= rand()%1000+1;
     high= low+rand()%1000000;
     cout<<low<<" "<<high<<endl;
 }
 cout<<endl;
 return 0;
}

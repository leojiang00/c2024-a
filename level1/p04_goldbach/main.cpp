#include <iostream>
#include<chrono>
#include<algorithm>
#include <c++/bits/exception_ptr.h>
using namespace std;
const int N=1000;
bool vis[N];
int primes[N],tot=0,f=1,arry[100000],vis2[N];
int main() {
    vis[1] = 1;
    for(int i=2;i<=N/2;i++) {
        if(!vis[i]) primes[tot++]=i;
        for(int j=2*i;j<=N;j+=i)
            vis[j]=1;
    }
    for(int i=1;i<=24;i++) {
        for(int j=1;j<=24;j++) {
            if((primes[i] + primes[j] > 100)||(vis2[primes[i] + primes[j]] == 1)) continue;
            arry[f++] = primes[i] + primes[j];
            vis2[arry[f]] = 1;
        }
    }
    for(int i=tot;i>=1;i--) {
        for(int j=1;j<=i-1;j++) {
            if(arry[j]>arry[j+1]) swap(arry[j],arry[j+1]);
        }
    }
    for(int i=1;i<=tot;i++) {
        cout<<arry[i]<<endl;
    }
    cout<<tot;
    return 0;
}
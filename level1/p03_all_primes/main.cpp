#include <iostream>
#include<chrono>
using namespace std;
const int N=1000;
bool vis[N];
int primes[N],tot=0;
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    vis[1] = 1;
    for(int i=2;i<=N/2;i++) {
        if(!vis[i]) primes[tot++]=i;
        for(int j=2*i;j<=N;j+=i)
            vis[j]=1;
    }
    for(int i=1;i<=tot;i++) {
        cout<<primes[i]<<endl;
    }
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish-start;
    std::cout<<elapsed.count();
    return 0;
}
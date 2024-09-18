#include<iostream>
using namespace std;
int main() {
    int n,f=1;
    cin>>n;
    for(int i=2;i<=n-1;i++) {
        if(n%i==0) {
            f=0;
            break;
        }
    }
    if(f==1) cout<<"Y";
    else cout<<"N";
    return 0;
}
#include<iostream>
using namespace std;
int hanoi(int n, char a, char b, char c){
    if(n==1) {
        cout<<a<<"->"<<c<<endl;
        return 0;
    }
    else{
        hanoi(n-1,a,c,b);
        hanoi(1,a,b,c);
        hanoi(n-1,b,a,c);
        return 0;
    }
}
int main() {
    int n;
    cin>>n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
#include<iostream>//base64编码以及解码
#include<cstring>
#include<cmath>
#include<bitset>
#include <stdio.h>
#include <c++/ostream>
#include <c++/string>
#include <c++/string>
#include <c++/bits/ios_base.h>
#include <c++/bits/ios_base.h>
using namespace std;
string base64Code(string s,int left) {
    string CodeBase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz"
                      "0123456789+/";
    int makeUp;
    string binaryResult, base64Result;
    for(int i=0;i<s.length();i++) {
        int x = int(s[i]);
        for(int j=7;j>=0;--j) {
            binaryResult += ((x>>j)&1)?'1':'0';
        }
    }
    while(binaryResult.length()%6) binaryResult += '0';
    for(int i=0;i<binaryResult.length();i+=6) {
        int countValue = 0;
        for(int j=i;j<=i+5;j++) {
            if(binaryResult[j]!='0') {
                countValue += pow(2,(5-(j-i)));
            }
        }
        base64Result += CodeBase[countValue];
    }
    if(left == 1) base64Result += "==";
    if(left == 2) base64Result += "=";
    return base64Result;
}
string decodeBase64(string s,int left) {
    int base64Length = s.length()-1,temp;
    string bringBack,realBringBack;
    while(s[base64Length]!='=') base64Length--;
    for(int i=0;i<=base64Length;i++) {
        if(s[i]>='A' && s[i]<='Z') {
            temp = int(s[i]-'A');
            bitset<6> binary(temp);
            bringBack += binary.to_string();
        }
        if(s[i]>='a' && s[i]<='z') {
            temp = int(s[i]-'a')+26;
            bitset<6> binary(temp);
            bringBack += binary.to_string();
        }
        if(s[i]>='0' && s[i]<='9') {
            temp = int(s[i]-'0')+52;
            bitset<6> binary(temp);
            bringBack += binary.to_string();
        }
        if(s[i] == '+') {
            temp = 62;
            bitset<6> binary(temp);
            bringBack += binary.to_string();
        }
        if(s[i] == '/') {
            temp = 63;
            bitset<6> binary(temp);
            bringBack += binary.to_string();
        }
    }
    base64Length = bringBack.length()-1;
    if(left==1) base64Length-=2;
    if(left==2) base64Length-=4;
    for(int i=0;i<=base64Length;i+=8) {
        int countValue = 0;
        for(int j=i;j<=i+7;j++) {
            if(bringBack[j]!='0') {
                countValue += pow(2,(7-(j-i)));
            }
        }
        char transback = char(countValue);
        realBringBack += transback;
    }
    return realBringBack;
}
int main(){
    int n,len;
    string str,result,bringB;
    cin>>str;
    len = str.length();
    n = len%3;
    result = base64Code(str,n);
    cout<<result<<endl;
    bringB = decodeBase64(result,n);
    cout<<bringB<<endl;
    return 0;
}
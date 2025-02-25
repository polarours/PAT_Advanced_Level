#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

bool isReversePrime(int N,int D){
    int num1=N;
    std::vector<int> v;
    while(N>0){
        v.push_back(N%D);
        N/=D;
    }
    string s="";
    for(int i=0;i<v.size();i++){
        s+=to_string(v[i]);
    }
    int num2=0;//需要以D进制转换为int
    for(int i=0;i<s.size();i++) {
        num2+=(s[i]-'0')*(pow(D,s.size()-1-i));
    }
    if(isPrime(num1)&&isPrime(num2)) return true;
    return false;
}

int main(){
    int N=0,D=0;
    bool flag=false;
    while(1){
        cin>>N;
        if(N<0) break;
        cin>>D;
        flag=isReversePrime(N,D);
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
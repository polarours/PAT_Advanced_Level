#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    if(sum<0) cout<<"-";
    string s=to_string(abs(sum));
    vector<char> v1;
    vector<char> v2;
    for(int i=s.size()-1;i>=0;i--){
        v1.push_back(s[i]);
    }
    for(int j=1;j<v1.size()+1;j++){
        v2.push_back(v1[j-1]);
        if((j%3==0)&&(j!=v1.size())) v2.push_back(',');
    }
    v1.clear();
    for(int k=v2.size()-1;k>=0;k--){
        v1.push_back(v2[k]);
    }
    for(char c:v1) cout<<c;
    return 0;
}
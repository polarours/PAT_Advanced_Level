#include <bits/stdc++.h>

using namespace std;

int main(){
    string s,s1,s2;
    int num=0,num1=0;
    double num2=0;
    map<int,double> m;
    vector<int> v1;
    vector<double> v2;
    int ans=0;
    for(int i=0;i<2;i++) {
        cin>>s;
        num=stoi(s);
        for(int j=0;j<num;j++) {
            cin>>s1>>s2;
            num1=stoi(s1);
            num2=stod(s2);
            if(m.find(num1)==m.end()) {
                m[num1]=num2;
            }else m[num1]+=num2;
        }
    }
    for(auto pair:m) {
        if(pair.second==0) continue;
        ans++;
        v1.push_back(pair.first);
        v2.push_back(pair.second);
    }
    if(ans==0) cout<<ans<<endl;
    else cout<<ans<<" ";
    for(int i=0;i<v1.size();i++) {
        if(i==v1.size()-1) cout<<v1[v1.size()-1-i]<<" "<<fixed<<setprecision(1)<<v2[v1.size()-1-i];
        else cout<<v1[v1.size()-1-i]<<" "<<fixed<<setprecision(1)<<v2[v1.size()-1-i]<<" ";
    }
    if(ans!=0) cout<<endl;
    return 0;
}

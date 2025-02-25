#include <bits/stdc++.h>

using namespace std;

int main(){
    double d11,d12,d13,d21,d22,d23,d31,d32,d33;
    double max1,max2,max3;
    cin>>d11>>d12>>d13;
    cin>>d21>>d22>>d23;
    cin>>d31>>d32>>d33;
    max1=max(d11,d12)>d13?max(d11,d12):d13;
    max2=max(d21,d22)>d23?max(d21,d22):d23;
    max3=max(d31,d32)>d33?max(d31,d32):d33;
    if(max1==d11) cout<<"W"<<" ";
    else if(max1==d12) cout<<"T"<<" ";
    else cout<<"L"<<" ";
    if(max2==d21) cout<<"W"<<" ";
    else if(max2==d22) cout<<"T"<<" ";
    else cout<<"L"<<" ";
    if(max3==d31) cout<<"W"<<" ";
    else if(max3==d32) cout<<"T"<<" ";
    else cout<<"L"<<" ";
    double d=2*(max1*max2*max3*0.65-1);
    cout<<fixed<<setprecision(2)<<d<<endl;
    return 0;
}
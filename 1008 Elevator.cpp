#include <bits/stdc++.h>

using namespace std;

int main(){
    int num=0,temp=0,cur=0;
    int sum=0;
    cin>>num;
    vector<int> v(num);
    for(int i=0;i<num;i++){
        cin>>temp;
        if(temp>cur) sum+=5+(temp-cur)*6;
        else sum+=5+(cur-temp)*4;
        cur=temp;
    }
    cout<<sum;
    return 0;
}

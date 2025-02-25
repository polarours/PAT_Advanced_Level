#include <bits/stdc++.h>

using namespace std;

int main(){
    int num=0,temp=0,max=-1;
    int ans=INT_MIN;
    int left=0,right=0,leftINdex=0,rightIndex=0;
    cin>>num;
    int a[num];
    bool flag=false;
    for(int i=0;i<num;i++){
        cin>>temp;
        a[i]=temp;
    }
    int index=0;
    temp=0;
    while(index<num){
        if(a[index]>=0) flag=true;
        temp+=a[index];
        if(temp<=0){
            if(a[index]==0) {
                leftINdex=index;
                rightIndex=index;
            }else {
                left=index+1;
                temp=0;
            }
        }
        if(temp>max){
            ans=temp;
            max=temp;
            right=index;
            leftINdex=left;
            rightIndex=right;
        }
        index++;
    }
    if(!flag) cout<<"0"<<" "<<a[0]<<" "<<a[num-1]<<endl;
    else cout<<ans<<" "<<a[leftINdex]<<" "<<a[rightIndex]<<endl;
    return 0;
}
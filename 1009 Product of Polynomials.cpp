#include <string>
#include <string.h>
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
    int num=0,a=0,x=0;
    int temp;
    double d,dt;
    map<int,double> Map1;
    map<int,double> Map2;
    map<int,double> Map3;
    vector<int> v1;
    vector<double> v2;
    cin>>num;
    for(int j=0;j<num;j++){
        cin>>x>>d;
        Map1[x]=d;
    }
    cin>>num;
    for(int k=0;k<num;k++){
        cin>>x>>d;
        Map2[x]=d;
    }
    for(auto pair1:Map1){
        for(auto pair2:Map2){
            temp=pair1.first+pair2.first;
            dt=pair1.second*pair2.second;
            if(Map3.find(temp)!=Map3.end()) Map3[temp]+=dt;
            else Map3[temp]=dt;
        }
    }
    auto it=Map3.begin();
    while(it!=Map3.end()){
        if(it->second==0) it++;
        else {
            v1.push_back(it->first);
            v2.push_back(it->second);
            it++;
        }
    }
    cout<<v1.size()<<" ";
    for(int i=v1.size()-1;i>=0;i--){
        if(i!=0) cout<<v1[i]<<" "<<fixed<<setprecision(1)<<v2[i]<<" ";
        else cout<<v1[i]<<" "<<fixed<<setprecision(1)<<v2[i]<<endl;
    }
    return 0;
}
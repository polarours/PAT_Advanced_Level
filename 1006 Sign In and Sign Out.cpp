#include <bits/stdc++.h>

using namespace std;

void StringSplit(string str,const char split,vector<string>& ans) {
    istringstream ss(str);
    string token;
    while(getline(ss,token,split)) {
        ans.push_back(token);
    }
}

int main(){
    int num;
    cin>>num;
    string s1,s2,s3;
    vector<string> v;
    vector<string> strings1,strings2;
    int num1=0,num2=0;//num1来的时间,num2离开的时间
    int early=INT_MAX,late=INT_MIN;
    string earlyPerson,latePerson;
    map<string,vector<string>> Map;
    for(int i=0;i<num;i++) {
        cin>>s1>>s2>>s3;
        v.push_back(s2);
        v.push_back(s3);
        Map[s1]=v;
        v.clear();
    }
    for(auto pair:Map) {
        v=pair.second;
        StringSplit(v[0],':',strings1);
        StringSplit(v[1],':',strings2);
        num1=stoi(strings1[0])*3600+stoi(strings1[1])*60+stoi(strings1[2]);
        num2=stoi(strings2[0])*3600+stoi(strings2[1])*60+stoi(strings2[2]);
        if(num1<early){
            earlyPerson=pair.first;
            early=num1;
        }
        if(num2>late){
            latePerson=pair.first;
            late=num2;
        }
        strings1.clear();
        strings2.clear();
    }
    cout<<earlyPerson<<" "<<latePerson<<endl;
    return 0;
}
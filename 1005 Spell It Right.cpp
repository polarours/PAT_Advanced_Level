#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int num=0,temp=0;
    vector<string> ans;
    for(char c:s){
        num+=c-'0';
    }
    string str=to_string(num);
    for(int i=0;i<str.length();i++){
        switch(str[i]-'0'){
            case 0:ans.push_back("zero");
            break;
            case 1:ans.push_back("one");
            break;
            case 2:ans.push_back("two");
            break;
            case 3:ans.push_back("three");
            break;
            case 4:ans.push_back("four");
            break;
            case 5:ans.push_back("five");
            break;
            case 6:ans.push_back("six");
            break;
            case 7:ans.push_back("seven");
            break;
            case 8:ans.push_back("eight");
            break;
            case 9:ans.push_back("nine");
            break;
            default:
                break;
        }
    }
    for(int i=0;i<ans.size();i++){
        if(i!=ans.size()-1) cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
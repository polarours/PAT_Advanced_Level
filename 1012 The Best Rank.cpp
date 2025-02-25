#include <bits/stdc++.h>

using namespace std;

int getMin(const vector<int>& vec){
    return *min_element(vec.begin(),vec.end());
}

int main(){
    int n,m;
    cin>>n>>m;
    string s;
    int A=0,C=0,M=0,E=0;
    map<string,vector<int>> Map;
    map<string,map<string,int>> ans;
    vector<int> index;
    vector<int> vc,vm,ve,va;
    int indexA=0,indexC=0,indexM=0,indexE=0;
    for(int i=0;i<n;i++){
        cin>>s>>C>>M>>E;
        A=(C+M+E)/3;
        Map[s].push_back(C);
        Map[s].push_back(M);
        Map[s].push_back(E);
        Map[s].push_back(A);
        vc.push_back(C);
        vm.push_back(M);
        ve.push_back(E);
        va.push_back(A);
    }
    sort(vc.begin(),vc.end(),greater<int>());
    sort(vm.begin(),vm.end(),greater<int>());
    sort(ve.begin(),ve.end(),greater<int>());
    sort(va.begin(),va.end(),greater<int>());
    for(int i=0;i<m;i++){
        cin>>s;
        auto it=Map.find(s);
        if(it==Map.end()) cout<<"N/A"<<endl;
        else{
            C=it->second[0];
            M=it->second[1];
            E=it->second[2];
            A=it->second[3];
            for(int i=1;i<n+1;i++){
                if(vc[i-1]==C){
                    indexC=i;
                    break;
                }
            }
            for(int i=1;i<n+1;i++){
                if(vm[i-1]==M){
                    indexM=i;
                    break;
                }
            }
            for(int i=1;i<n+1;i++){
                if(ve[i-1]==E){
                    indexE=i;
                    break;
                }
            }
            for(int i=1;i<n+1;i++){
                if(va[i-1]==A){
                    indexA=i;
                    break;
                }
            }
            index.push_back(indexA);
            index.push_back(indexC);
            index.push_back(indexM);
            index.push_back(indexE);
            int min=getMin(index);
            if(min==indexA) cout<<min<<" A"<<endl;
            else if(min==indexC) cout<<min<<" C"<<endl;
            else if(min==indexM) cout<<min<<" M"<<endl;
            else cout<<min<<" E"<<endl;
            index.clear();
        }
    }

    return 0;
}
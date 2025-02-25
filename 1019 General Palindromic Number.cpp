#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 0, b = 0;
    bool flag = true;
    cin >> N >> b;
    vector<int> res;
    while (N != 0) {
        res.push_back(N % b);
        N /= b;
    }
    int left = 0, right = res.size() - 1;
    while (left <= right) {
        if (res[left++]  != res[right--] )
            flag = false;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        if (i != 0)
            cout << res[i]  << " ";
        else
            cout << res[i] << endl;
    }

    return 0;
}

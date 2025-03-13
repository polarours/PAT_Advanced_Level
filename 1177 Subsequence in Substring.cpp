#include <bits/stdc++.h>

bool isSubsequence(std::string str, std::string subsequence) {//pabt pat
    int pos_1 = 0, pos_2 = 0;
    while (pos_1 < str.size() && pos_2 < subsequence.size()) {
        if(str[pos_1] == subsequence[pos_2]) {
            pos_1++;
            pos_2++;
        }else {
            pos_1++;
        }
    }
    if(pos_2 != subsequence.size()) {
        return false;
    }
    return true;
}

int main() {
    std::string S, P;
    std::getline(std::cin, S);
    std::getline(std::cin, P);

    char left_c = P[0];
    int left_index = 0;
    while(S[left_index] != left_c) left_index++;
    S = S.substr(left_index);

    std::string res = "";
    int len = P.size();
    bool found = false;
    while(len <= S.size()) {
        if(found) break;
        for(int i = 0; i <= S.size() - len; i++) {
            std::string sub = S.substr(i, len);
            if(isSubsequence(sub, P)) {
                res = sub;
                found = true;
                break;
            }
        }
        len++;
    }

    std::cout << res << std::endl;

    return 0;
}
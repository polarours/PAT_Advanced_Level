#include <bits/stdc++.h>


int main() {
    std::string N;
    std::cin >> N;

    int size = N.size();
    if(size < 4) {
        while(4 - size) {
            N = "0" + N;
            size++;
        }
    }
    
    std::vector<char> v;
    for (int i = 0; i < N.size(); i++) {
        v.push_back(N[i]);
    }

    while (1) {
        std::vector<char> v1 = v, v2 = v;
        std::string s1 = "", s2 = "", s3 = "";
        int n1, n2, n3;
        std::sort(v1.begin(), v1.end(), std::greater<char>());
        std::sort(v2.begin(), v2.end());
        for (int i = 0; i < v1.size(); i++) {
            s1 += v1[i];
        }
        for (int i = 0; i < v2.size(); i++) {
            s2 += v2[i];
        }
        n1 = std::stoi(s1);
        n2 = std::stoi(s2);
        n3 = n1 - n2;
        s3 = std::to_string(n3);
        int size = s3.size();
        if(size < 4) {
            while(4 - size) {
                s3 = "0" + s3;
                size++;
            }
        }
        if(n3 == 0) {
            std::cout << s1 << " - " << s2 << " = 0000" << std::endl;
            break;
        }
        if(n3 == 6174) {
            std::cout << s1 << " - " << s2 << " = " << s3 << std::endl;
            break;
        }
        std::cout << s1 << " - " << s2 << " = " << s3 << std::endl;
        for(int i = 0; i < v.size(); i++) {
            v[i] = s3[i];
        }
    }

    return 0;
}
#include <bits/stdc++.h>

int main() {
    std::string s1, s2, s3, s4, res;
    std::cin >> s1 >> s2 >> s3 >> s4;

    int day = 0, hour = 0, minute = 0;
    int num = 0, start = 0;
    std::vector<int> vec;
    int len1 = std::min(s1.size(), s2.size());
    int len2 = std::min(s3.size(), s4.size());
    for(int i = 0; i < len1; i++) {
        if(s1[i] >= 'A' && s1[i] <= 'G' && s2[i] >= 'A' && s2[i] <= 'G' && s1[i] == s2[i]) {
            num = s1[i] - 'A' + 1;
            start = i;
            vec.push_back(num);
            break;
        }
    }

    for(int i = start + 1; i < len1; i++) {
        if((s1[i] >= '0' && s1[i] <= '9' || s1[i] >= 'A' && s1[i] <= 'N') && (s2[i] >= 'A' && s2[i] <= 'N' || s2[i] >= '0' && s2[i] <= '9') && s1[i] == s2[i]) {
            if(s1[i] >= '0' && s1[i] <= '9') {
                num = s1[i] - '0';
            } else {
                num = s1[i] - 'A' + 10;
            }
            vec.push_back(num);
            break;
        }
    }

    int pos = 0;
    for(int i = 0; i < len2; i++) {
        if(std::isalpha(s3[i]) && std::isalpha(s4[i]) && s3[i] == s4[i]) {
            pos = i;
            break;
        }
    }

    switch(vec[0]) {
        case 1:
            std::cout << "MON ";
        break;
        case 2:
            std::cout << "TUE ";
        break;
        case 3:
            std::cout << "WED ";
        break;
        case 4:
            std::cout << "THU ";
        break;
        case 5:
            std::cout << "FRI ";
        break;
        case 6:
            std::cout << "SAT ";
        break;
        case 7:
            std::cout << "SUN ";
        break;
        default:
            break;
    }

    std::cout << std::setw(2) << std::setfill('0') << vec[1] << ":" << std::setw(2) << std::setfill('0') << pos << std::endl;

    return 0;
}
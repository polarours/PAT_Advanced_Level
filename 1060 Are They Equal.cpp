#include<bits/stdc++.h>

int main() {
    int N;
    std::string s1, s2;
    std::cin >> N >> s1 >> s2;

    bool flag_0_s1 = true, flag_0_s2 = true;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != '0' && s1[i] != '.') {
            flag_0_s1 = false;
        }
    }
    for(int i = 0; i < s2.size(); i++) {
        if(s2[i] != '0' && s2[i] != '.') {
            flag_0_s2 = false;
        }
    }

    int exponent1 = 0, exponent2 = 0;
    std::string str1, str2;

    std::string::iterator it1 = std::find(s1.begin(), s1.end(), '.');
    std::string::iterator it2 = std::find(s2.begin(), s2.end(), '.');
    int s1_left = std::distance(s1.begin(), it1), s2_left = std::distance(s2.begin(), it2);
    int s1_right = std::distance(it1, s1.end()), s2_right = std::distance(it2, s2.end());

    bool flag1 = false, flag2 = false;
    int pos1 = 0, pos2 = 0;
    if(s1_left > 1) {
        for(int i = 0; i < s1_left; i++) {
            if(s1[i] != '0') {
                pos1 = i;
                flag1 = true;
                break;
            }
        }
        if(flag1) {
            s1 = s1.substr(pos1);
        }else {
            std::string temp = "0";
            temp += s1.substr(s1_left);
            s1 = temp;
        }
    }

    if(s2_left > 1) {
        for(int i = 0; i < s2_left; i++) {
            if(s2[i] != '0') {
                pos2 = i;
                flag2 = true;
                break;
            }
        }
        if(flag2) {
            s2 = s2.substr(pos2);
        }else {
            std::string temp = "0";
            temp += s2.substr(s2_left);
            s2 = temp;
        }
    }

    std::string::iterator it3 = std::find(s1.begin(), s1.end(), '.');
    std::string::iterator it4 = std::find(s2.begin(), s2.end(), '.');
    int string1_left = std::distance(s1.begin(), it3), string2_left = std::distance(s2.begin(), it4);
    int string1_right = std::distance(it3, s1.end()), string2_right = std::distance(it4, s2.end());

    s1_left = string1_left;
    s2_left = string2_right;
    s1_right = string1_right;
    s2_right = string2_right;

    if(s1[0] == '0') {
        int pos = 0;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != '0' && s1[i] != '.') {
                pos = i;
                break;
            }
        }
        int num = s1.size() - pos;
        if(num <= N) {
            int diff = N - num;
            std::string temp = "0.";
            temp += s1.substr(pos);
            while(diff > 0) {
                temp += "0";
                diff--;
            }
            str1 = temp;
            exponent1 -= pos - 2;
        }else {
            std::string temp = "0.";
            int start = pos, cur_size = 0;
            while(cur_size < N) {
                temp += s1[start++];
                cur_size++;
            }
            str1 = temp;
            exponent1 -= pos - 2;
        }
    }else {//左移
        int cur_size = 0, start = 0;
        std::string t = "0.";
        exponent1 += s1_left;
        while(cur_size < N) {
            if(s1[start] != '.') {
                t += s1[start++];
                cur_size++;
            }else {
                start++;
            }
        }
        str1 = t;
    }

    if(s2[0] == '0') {
        int pos = 0;
        for(int i = 0; i < s2.size(); i++) {
            if(s2[i] != '.' && s2[i] != '0') {
                pos = i;
                break;
            }
        }
        int num = s2.size() - pos;
        if(num <= N) {
            int diff = N - num;
            std::string temp = "0.";
            temp += s2.substr(pos);
            while(diff > 0) {
                temp += "0";
                diff--;
            }
            str2 = temp;
            exponent2 -= pos - 2;
        }else {
            std::string temp = "0.";
            int start = pos, cur_size = 0;
            while(cur_size < N) {
                temp += s2[start++];
                cur_size++;
            }
            str2 = temp;
            exponent2 -= pos - 2;
        }
    }else {//左移
        int cur_size = 0, start = 0;
        std::string t = "0.";
        exponent2 += s1_left;
        while(cur_size < N) {
            if(s2[start] != '.') {
                t += s2[start++];
                cur_size++;
            }else {
                start++;
            }
        }
        str2 = t;
    }

    if(flag_0_s1) {
        str1 = "0.";
        for(int i = 0; i < N; i++)
            str1 += "0";
        exponent1 = 0;
    }
    if(flag_0_s2) {
        str2 = "0.";
        for(int i = 0; i < N; i++)
            str2 += "0";
        exponent2 = 0;
    }

    if(str1 == str2 && exponent1 == exponent2) {
        std::cout << "YES " << str1 << "*10^" << exponent1 << std::endl;
    }else {
        std::cout << "NO " << str1 << "*10^" << exponent1 << " " << str2 << "*10^" << exponent2 << std::endl;
    }

    return 0;
}
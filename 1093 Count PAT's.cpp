#include<bits/stdc++.h>

const int N = 1000000007;

int main() {
    std::string str;
    std::cin >> str;

    int first_P = 0, last_T = str.size() - 1, last_P = 0;
    while(str[first_P] != 'P') first_P++;
    while(str[last_T] != 'T') last_T--;

    str = str.substr(first_P, last_T - first_P + 1);

    long long int result = 0;
    int count_P = 0, count_T = 0, count_A = 0;
    for(int pos = first_P + 1; pos <= last_T; pos++) {
        if(str[pos] == 'T') count_T++;
    }
    long long temp = 0;
    for(int pos = 0; pos < str.size(); pos++) {
        if(str[pos] == 'P') count_P++;
        else if(str[pos] == 'A') {
            result = (result + count_P * count_T) % N;
        }else {
            count_T--;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
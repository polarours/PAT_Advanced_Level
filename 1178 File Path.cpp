#include <bits/stdc++.h>

void StringSplit(std::string str, const char split, std::vector<std::string>& result) {
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, split)) {
        result.push_back(token);
    }
}

std::string del_space(std::string str) {
    int index = 0;
    for(const char c : str) {
        if(c == ' ') index++;
        else break;
    }
    return str.substr(index);
}

int main() {
    int N;
    std::cin >> N;

    std::string s, root;
    std::set<std::string> set_file;
    std::vector<std::string> files;
    std::cin >> root;
    std::cin.ignore();
    files.push_back(root);
    for(int i = 1; i < N; i++) {
        std::getline(std::cin, s);
        std::string str = del_space(s);
        set_file.insert(str);
        files.push_back(s);
    }

    int K;
    std::cin >> K;
    std::vector<std::string> query(K);
    for(int i = 0; i < K; i++) {
        std::cin >> query[i];
    }

    for(int i = 0; i < K; i++) {
        std::vector<std::string> result;
        std::string query_file = query[i];
        if(query_file != "0000" && set_file.find(query_file) == set_file.end()) {
            std::cout << "Error: " << query_file << " is not found." << std::endl;
        }else if(query_file == "0000") {
            std::cout << query_file << std::endl;
        }else {
            int pos = 0;
            for(int j = 0; j < N; j++) {
                std::string s = del_space(files[j]);
                if(s == query_file) {
                    pos = j;
                    break;
                }
            }
            result.push_back(query_file);
            int cur_length = files[pos].size();
            for(int k = pos - 1; k >= 0; k--) {
                if(files[k].size() < cur_length) {
                    cur_length = files[k].size();
                    std::string s = del_space(files[k]);
                    result.push_back(s);
                }
            }
            if(!result.empty()) {
                std::reverse(result.begin(), result.end());
                for(int i = 0; i < result.size(); i++) {
                    if(i != result.size() - 1) {
                        std::cout << result[i] << "->";
                    }else {
                        std::cout << result[i] << std::endl;
                    }
                }
            }
        }
    }



    return 0;
}
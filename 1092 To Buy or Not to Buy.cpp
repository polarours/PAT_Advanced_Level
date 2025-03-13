#include <bits/stdc++.h>

int main() {
    std::string shop_beads, want_beads;
    std::cin >> shop_beads >> want_beads;

    if(want_beads.size() > shop_beads.size()) {
        std::cout << "No " << want_beads.size() - shop_beads.size() << std::endl;
    }

    std::unordered_map<char, int> m_1, m_2;
    for(const auto& c : shop_beads) {
        if(m_1.find(c) == m_1.end()) {
            m_1[c] = 1;
        }else {
            m_1[c]++;
        }
    }
    for(int i = 0; i < want_beads.size(); i++) {
        if(m_2.find(want_beads[i]) == m_2.end()) {
            m_2[want_beads[i]] = 1;
        }else {
            m_2[want_beads[i]]++;
        }
    }

    bool is_miss = false;
    int miss = 0, extra = 0;
    for(int i = 0; i < want_beads.size(); i++) {
        char c = want_beads[i];
        if(m_1.find(c) == m_1.end()) {//没找到
            is_miss = true;
        }else {
            if(m_1[c] <= 0) is_miss = true;
            m_1[c]--;
            m_2[c]--;
        }
    }

    if(is_miss) {
        for(const auto& pair : m_2) {
            if(pair.second != 0) miss += pair.second;
        }
        for(const auto& pair : m_1) {
            if(pair.second < 0) miss += std::abs(pair.second);
        }
        std::cout << "No " << miss << std::endl;
    }else {
        for(const auto& pair : m_1) {
            if(pair.second != 0) extra += pair.second;
        }
        std::cout << "Yes " << extra << std::endl;
    }

    return 0;
}
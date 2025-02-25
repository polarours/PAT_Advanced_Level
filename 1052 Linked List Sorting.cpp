#include <bits/stdc++.h>

struct Node {
    std::string address;
    int key;
    std::string next;
};


int main() {
    int N;
    std::string start_address;
    std::cin >> N >> start_address;

    std::vector<std::tuple<std::string, int, std::string>> vec;
    std::unordered_map<std::string, Node> map_node;
    for(int i = 0; i < N; i++) {
        int key;
        std::string address, next;
        std::cin >> address >> key >> next;
        map_node[address] = {address, key, next};
    }

    std::string cur_addr = start_address;
    while(cur_addr != "-1" && map_node.find(cur_addr) != map_node.end()) {
        Node& node = map_node[cur_addr];
        vec.push_back({node.address, node.key, node.next});
        cur_addr = node.next;
    }

    std::sort(vec.begin(), vec.end(),[](std::tuple<std::string, int, std::string> a, std::tuple<std::string, int, std::string> b) {
        return std::get<1>(a) < std::get<1>(b);
    });

    if(vec.size() > 0)
        std::cout << vec.size() << " " << std::get<0>(vec[0]) << std::endl;
    else
        std::cout << "0 -1" << std::endl;
    for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size() - 1)
            std::cout << std::get<0>(vec[i]) << " " << std::get<1>(vec[i]) << " " << std::get<0>(vec[i + 1]) << std::endl;
        else
            std::cout << std::get<0>(vec[i]) << " " << std::get<1>(vec[i]) << " " << -1 << std::endl;
    }

    return 0;
}
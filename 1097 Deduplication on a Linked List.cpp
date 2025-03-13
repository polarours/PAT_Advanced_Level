#include <set>
#include <bits/stdc++.h>

const int MAXN = 100000;

struct ListNode {
    int val;
    int address;
    int next;
};

int main() {
    int start_address, N;
    std::cin >> start_address >> N;

    std::vector<ListNode*> nodes(MAXN);
    std::set<int> visited;
    int addr, key, next;
    while(N--) {
        std::cin >> addr >> key >> next;
        ListNode* node = new ListNode();
        node->address = addr;
        node->val = key;
        node->next = next;
        nodes[addr] = node;
    }

    std::vector<ListNode*> result;
    std::vector<ListNode*> del;
    ListNode* p = nodes[start_address];
    for(; p->next != -1; p = nodes[p->next]) {
        if(visited.find(std::abs(p->val)) == visited.end()) {
            visited.insert(std::abs(p->val));
            result.push_back(p);
        }else {
            del.push_back(p);
        }
    }
    if(visited.find(std::abs(p->val)) == visited.end()) {
        visited.insert(std::abs(p->val));
        result.push_back(p);
    }else {
        del.push_back(p);
    }

    for(int i = 0; i < result.size(); i++) {
        if(i != result.size() - 1) {
            result[i]->next = result[i + 1]->address;
        }else {
            result[i]->next = -1;
        }
    }

    for(int i = 0; i < del.size(); i++) {
        if(i != del.size() - 1) {
            del[i]->next = del[i + 1]->address;
        }else {
            del[i]->next = -1;
        }
    }

    for(int i = 0; i < result.size(); i++) {
        std::cout << std::setw(5) << std::setfill('0') << result[i]->address << " " << result[i]->val << " ";
        if(result[i]->next != -1) {
            std::cout << std::setw(5) << std::setfill('0') << result[i]->next << std::endl;
        }else {
            std::cout << result[i]->next << std::endl;
        }
    }

    for(int i = 0; i < del.size(); i++) {
        std::cout << std::setw(5) << std::setfill('0') << del[i]->address << " " << del[i]->val << " ";
        if(del[i]->next != -1) {
            std::cout << std::setw(5) << std::setfill('0') << del[i]->next << std::endl;
        }else {
            std::cout << del[i]->next << std::endl;
        }
    }

    return 0;
}
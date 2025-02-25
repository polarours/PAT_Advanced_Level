#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int level;   // 当前结点
    int flag;    // 是否有孩子结点 0代表无 1代表有
    int farther; // 父结点
} Node;

int main() {
    // 初始化
    int N, M;
    cin >> N >> M;
    vector<int> res;
    Node nodes[300];
    int curNode, curNodeNumber, childNode;
    int maxLevel = 1;

    // 初始化 nodes[0]跳过
    for (int i = 0; i <= N; i++) {
        nodes[i].level = 0;
        nodes[i].flag = 0;
        nodes[i].farther = 0;
    }
    nodes[1].level = 1; // “01”高度为1

    // 接收孩子结点
    while (M--) {
        cin >> curNode;
        cin >> curNodeNumber;

        if (curNodeNumber != 0)
            nodes[curNode].flag = 1;

        while (curNodeNumber--) {
            cin >> childNode;

            // 保存父结点
            nodes[childNode].farther = curNode;
        }
    }

    // 划分层次
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (nodes[j].farther == i)
                nodes[j].level = nodes[i].level + 1;
        }
    }

    int count = 0;
    // 遍历每一层的终端结点
    for (int i = 1; i <= N; i++) {
        if(nodes[i].level > maxLevel) {
            maxLevel = nodes[i].level;
            res.push_back(count);
            count = 0;
            if(nodes[i].flag == 0 && nodes[i].level > 0) count++;
        }else {
            if(nodes[i].flag == 0 && nodes[i].level > 0) {
                count++;
            }
        }
    }
    res.push_back(count);

    // 输出res
    for (int i = 0; i < res.size(); i++) {
        if (i != res.size() - 1)
            cout << res[i] << " ";
        else
            cout << res[i] << endl;
    }

    return 0;
}



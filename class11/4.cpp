// 对于这道题，只要保证没有环就行了
// 用拓扑排序
// 我用dfs做对过这道题。。。另一个办法就是尝试所有方法看看有没有可能做出来，反正数很小
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[8];
priority_queue<int, vector<int>, greater<int>> q;
int schedule[8];
int inDegree[8];
bool vis[8];
int val;

void initInDegree() {
    for (vector<int> v: graph) {
        for (int j: v) {
            inDegree[j] ++;
        }
    }
}

bool topsort() {
    initInDegree();
    int cnt = 1;
    for (int i = 1; i < 8; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
            vis[i] = true;
        }
    }
    if (q.size() == 0) {
        return false;
    }
    while (!q.empty()) {
        val = q.top(); q.pop();
        schedule[cnt++] = val;
        for (int i: graph[val]) {
            if (vis[i]) {
                continue;
            }
            inDegree[i] --;
            if (inDegree[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    if (cnt != 8) {
        return false;
    } else {
        return true;
    }
}

int main() {
    graph[1].push_back(7);
    graph[1].push_back(4);
    graph[2].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);
    int x, y;
    cin >> x >> y;
    while (x != 0 && y != 0) {
        graph[x].push_back(y);
        cin >> x >> y;
    }
    if (topsort()) {
        for (int i = 1; i < 8; i++) {
            cout << schedule[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    }
}
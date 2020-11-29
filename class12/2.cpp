#include <bits/stdc++.h>
using namespace std;
int N, M;
bool vis[21];
vector<int> graph[21];
int steps[21];
bool suc = false;

void dfs(int now) {
    if (suc) {
        return;
    }
    for (int i: graph[now]) {
        if (suc) {
            return;
        }
        if (vis[i]) {
            if (steps[now] - steps[i]+1 >= 6) {
                suc = true;
                return;
            }
            continue;
        }
        vis[i] = true;
        steps[i] = steps[now] + 1;
        dfs(i);
        vis[i] = false;
    }
}

int main() {
    cin >> N >> M;
    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vis[1] = true;
    steps[1] = 0;
    dfs(1);
    if (suc) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
bool vis[10001];
bool inStack[10001];
int M, N;

int x,y;

bool circ(int now) {
    inStack[now] = true;
    vis[now] = true;
    for (int i: graph[now]) {
        if (inStack[i]) {
            return true;
        } else {
            if (vis[i]) {
                continue;
            }
            if (circ(i)) {
                return true;
            }
        }
    }
    inStack[now] = false;
    return false;
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 0; i < N; i++) {
        if (graph[i].size() != 0 && (!vis[i])) {
            if (circ(i)) {
                cout << "N" << endl;
                return 0;
            }
        }
    }
    cout << "Y" << endl;
}
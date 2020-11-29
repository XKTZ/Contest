#include <bits/stdc++.h>
using namespace std;

string names[901];
map<string, int> namesmap;
int inDegree[901];
int M;
priority_queue<int, vector<int>, less<int>> q;
vector<int> graph[901];
vector<int> parent[901];
int topop[901];
bool vis[901];
int curser = 0;
string a,b ;

int viscirc[901];
bool visitedInCirc[901];

void check(string s) {
    if (namesmap.count(s) == 0) {
        namesmap[s] = curser;
        names[curser] = s;
        curser ++;
    }
}

void initInDegree() {
    for (vector<int> v: graph) {
        for (int j : v) {
            inDegree[j] ++;
        }
    }
}

void inCirc(int x) {
    if (visitedInCirc[x]) {
        return;
    }
    queue<int> q;
    q.push(x);
    visitedInCirc[x] = true;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int y: parent[x]) {
            if (!visitedInCirc[y]) {
                visitedInCirc[y] = true;
                q.push(y);
            }
        }
    }
}

/**
 * 0: not visited
 * 1: visiting
 * 2: visited
 **/
void circ(int now) {
    viscirc[now] = 1;
    for (int i: graph[now]) {
        if (viscirc[i] == 0) {
            circ(i);
        } else if (viscirc[i] == 1) {
            inCirc(i);
        }
    }
    viscirc[now] = 2;
}

int topo() {
    int cnt = 0;
    initInDegree();
    for (int i = 0; i < curser; i++) {
        if (!visitedInCirc[i] && viscirc[i] == 0) {
            circ(i);
        }
    }
    for (int i = 0; i < curser; i++) {
        if (visitedInCirc[i]) {
            for (int j: graph[i]) {
                inDegree[j] --;
            }
        }
    }
    for (int i = 0; i < curser; i++) {
        if (inDegree[i] == 0 && !visitedInCirc[i]) {
            q.push(i);
            vis[i] = true;
        }
    }
    while (!q.empty()) {
        int node = q.top(); q.pop();
        topop[cnt++] = node;
        for (int i: graph[node]) {
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
    return cnt;
}

int main() {
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        check(a);
        check(b);
        graph[namesmap[a]].push_back(namesmap[b]);
        parent[namesmap[b]].push_back(namesmap[a]);
    }
    int c = topo();
    for (int i = c-1; i > -1; i--) {
        cout << names[topop[i]] << endl;
    }
}
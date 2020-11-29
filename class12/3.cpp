#include <bits/stdc++.h>
using namespace std;

const int MAXNUM = 1000001;
int vis[MAXNUM];
int x, y;

int main() {
    cin >> x >> y;
    queue<int >q;
    if (x == y) {
        cout << 0 << endl;
        return 0;
    }
    q.push(x);
    vis[x] = 1;
    while (!q.empty()) {
        x = q.front();q.pop();
        if (x-1 >= 0 && vis[x-1] == 0) {
            if (x-1 == y) {
                cout << vis[x] << endl;
                return 0;
            }
            vis[x-1] = vis[x] + 1;
            q.push(x-1);
        }
        
        if (x+1 <= MAXNUM && vis[x+1] == 0) {
            if (x+1 == y) {
                cout << vis[x] << endl;
                return 0;
            }
            vis[x+1] = vis[x] + 1;
            q.push(x+1);
        }
        
        if (x*2 <= MAXNUM && vis[x*2] == 0) {
            if (x*2 == y) {
                cout << vis[x] << endl;
                return 0;
            }
            vis[x*2] = vis[x] + 1;
            q.push(x*2);
        }
    }
}
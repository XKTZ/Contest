### 拓扑排序：
- A topological sort is an ordering of vertices in a directed acyclic graph, such that if there is a path from vi to vj, then vj appears after vi in the ordering
- 在对于一个图中$v_i$与$v_j$，如果有一条边使得$v_i$->$v_j$，那么$v_i$就在$v_j$前
- 有些时候拓扑排序并不可以施行(e.g. $v_1$->$v_2$->$v_3$->$v_1$)
- 这里用一个类似于贪心算法的算法：
    - 只有一个节点的in degree (既有多少边指向D)为0时，把这个节点压入栈中
    - 遍历所有的边，减去in degree
    - 当一个节点的in degree为0时，他就是那个情况下最大的
```cpp
/**
 * graph: 图
 * indegree: 内度
 * num: 点数
**/
void initInDegree(vector<int> graph*, int indegree*, int num) {
    for (vector<int> v: graph) {
        for (int j: v) {
            indegree[j]++;
        }
    }
}
/**
 * graph: 图
 * arr: 排序完毕后存放的地方
 * num: 点数
**/
bool graph(vector<int> graph*, int arr*, int num) {
    // bfs -> 初始化队列
    priority_queue<int> q;
    // 初始化vis函数
    bool* vis = new bool[num];
    for (int i = 0; i < num; i++) {
        vis[i] = false;
    }
    // 初始化内度
    int* indegree = new int[num];
    initInDegree(graph, indegree, num);
    // 初始化cnt
    int cnt = 0;
    // 压入队列
    for (int i = 0; i < num; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    // bfs
    while (!q.empty()) {
        // 正在bfs的值
        int node = q.top(); q.pop();
        // 加入
        arr[cnt++] = node;
        // 遍历边
        for (int i: graph[node]) {
            if (vis[i]) {
                continue;
            }
            // 先减去
            indegree[i] --;
            // 如果是0
            if (indegree[i] == 0) {
                // 压入
                q.push(i);
                vis[i] = true;
            }
        }
    }
    return cnt == num;
}
```
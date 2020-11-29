## Minimum Spanning Tree (最小生成树)
- Number of edges is |V|-1
- Acyclic
- Prim Algorithm:
    - 创建vis[]和dis[]
    - 从一个node开始 (A)
        - 找到dis中最短没有vis过的距离，之后去到那个距离
        - 直到全部vis
``` cpp
/*
普通做法
*/
int getMin(int* l, bool* vis, int len) {
    int minVal = INT32_MAX;
    int minIndex = -1;
    for (int i = 0; i < len; i++) {
        if (!vis[i] && l[i] < minVal) {
            minVal = l[i];
            minIndex = i;
        }
    }
    return minIndex;
}

/**
 * 类似于dijekstra
 **/
void prim(vector<pair<int, int>> graph*, int len, int start) {
    // visited
    bool* vis = new bool[len];
    // distance
    int* dis = new int[len];
    vis[start] = true;
    last[start] = -1;
    int alreadyVisited = 1;
    while (alreadyVisited < len) {
        int indexThis = getIndex(dis, vis, len);
        for (pair<int, int> i: graph[indexThis]) {
            dis[i.first] = min(dis[i.first], i.second);
            // 每次如果要刷新这个点，就把这个点的父点改做现在的点
            if (dis[i.first] > i.second){
                last[i.first] = indexThis;
            }
        }
        alreadyVisited ++;
    }
}
```
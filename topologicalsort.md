### 拓扑排序：
- A topological sort is an ordering of vertices in a directed acyclic graph, such that if there is a path from vi to vj, then vj appears after vi in the ordering
- 在对于一个图中$v_i$与$v_j$，如果有一条边使得$v_i$->$v_j$，那么$v_i$就在$v_j$前
- 有些时候拓扑排序并不可以施行(e.g. $v_1$->$v_2$->$v_3$->$v_1$)
- 这里用一个类似于贪心算法的算法：
    - 只有一个节点的in degree (既有多少边指向D)为0时，把这个节点压入栈中
    - 遍历所有的边，减去in degree
    - 当一个节点的in degree为0时，他就是那个情况下最大的
```
void topsort(graph G) {
    Queue Q;
    int counter = 0;
    vertex v, w;
    Q = create_queue();
    for each vertex v
        // 必须要indegree是0才能加
        if (indegree[v] = 0)
            q.add(v)
    while(!Q.Empty()) {
        v=  Q.poll)(;
        ++counter; // assign next number
        for each w adjacent to v
            if (--indegree[w] = 0)
                enqueue(w, Q)
    }
    if (counter != NUM_VERTEX)
        error ("Graph has a cycle)
}
```
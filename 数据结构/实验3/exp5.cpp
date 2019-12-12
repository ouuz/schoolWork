#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct qnode
{
    int v;
    int c;
    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator<(const qnode &r) const
    {
        return c > r.c;
    }
};
struct Edge
{
    int v, cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};
vector<vector<Edge> > E;
void Dijkstra(vector<int> &dist, int n, int start)
{
    dist.resize(n + 5);
    vector<int> vis;
    for (int i = 0; i <= n; i++)
    {
        vis.push_back(0);
    }
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    priority_queue<qnode> que;
    while (!que.empty())
        que.pop();
    dist[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[tmp.v][i].v;
            int cost = E[u][i].cost;
            if (!vis[v] && dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
void addedge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}

int main()
{
    int n, m, begP, endP;
    cin >> n >> m;
    E.resize(n + 5);
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        addedge(u + 1, v + 1, d);
    }
    vector<int> dist;
    cin >> begP;
    Dijkstra(dist, n, 1);
    cin >> endP;
    if (dist[endP] == INF)
    {
        cout << "Impossible";
    }
    else
    {
        cout << dist[endP];
    }
    cout << endl;
    return 0;
}


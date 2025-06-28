#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void dfs(int node, int par, vector<int> adj[], vector<int> &dist)
{
    dist[node] = 1 + dist[par];

    for (auto e : adj[node])
    {
        if (e == par)
            continue;
        dfs(e, node, adj, dist);
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    dfs(1, 0, adj, dist);

    int lastnode = 1;

    for (int i = 1; i <= n; i++)
    {
        if (dist[lastnode] < dist[i])
            lastnode = i;
    }

    dist.assign(n + 1, -1);
    dfs(lastnode, 0, adj, dist);

    cout << *max_element(begin(dist), end(dist));
}
signed main()
{
    // Humare saath Shree Raghunath to kisi baat ki chinta nahi

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
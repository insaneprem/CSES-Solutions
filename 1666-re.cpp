#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
map<int, int> mpp;
void dfs(int node, vector<int> adj[], vector<int> &vis, int compcnt)
{
    vis[node] = 1;
    mpp[compcnt] = node;

    for (auto e : adj[node])
    {
        if (!vis[e])
        {
            dfs(e, adj, vis, compcnt);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, cnt);
            cnt++;
        }
    }

    cout << mpp.size() - 1 << "\n";
    vector<int> city;
    for (auto it : mpp)
        city.push_back(it.second);

    for (int i = 0; i < city.size() - 1; i++)
    {
        cout << city[i] << " " << city[i + 1] << "\n";
    }

    mpp.clear();
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
vector<int> subtree;
void dfs(int node, int par, vector<int> adj[])
{
    for (auto e : adj[node])
    {
        if (e == par)
            continue;
        dfs(e, node, adj);
        subtree[node] += subtree[e];
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> adj[n + 1];
    subtree.assign(n + 1, 1);

    for (int u = 2; u <= n; u++)
    {
        int v;
        cin >> v;

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    dfs(1,0,adj);

    for (int i = 1; i <= n; i++)
        cout << subtree[i] - 1 << " ";
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
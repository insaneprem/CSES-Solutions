#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int p1 = 31;
const int p2 = 37;
void solve()
{
    string str;
    cin >> str;

    int n = str.size();
    vector<int> hash1(n), hash2(n);
    vector<int> pow1(n), pow2(n);

    hash1[0] = (str[0] - 'a' + 1), hash2[0] = (str[0] - 'a' + 1);
    pow1[0] = 1, pow2[0] = 1;

    for (int i = 1; i < n; i++)
    {
        pow1[i] = (pow1[i - 1] * p1) % MOD1;
        pow2[i] = (pow2[i - 1] * p2) % MOD2;

        hash1[i] = ((hash1[i - 1] * p1) + (str[i] - 'a' + 1)) % MOD1;
        hash2[i] = ((hash2[i - 1] * p2) + (str[i] - 'a' + 1)) % MOD2;
    }

    vector<int> border;

    for (int len = 1; len < n; len++)
    {
        int Prefixhash1 = hash1[len - 1];
        int Prefixhash2 = hash2[len - 1];

        int Suffixhash1 = (hash1[n - 1] - ((hash1[n - 1 - len] * pow1[len]) % MOD1) + MOD1) % MOD1;
        int Suffixhash2 = (hash2[n - 1] - ((hash2[n - 1 - len] * pow2[len]) % MOD2) + MOD2) % MOD2;

        if (Prefixhash1 == Suffixhash1 && Prefixhash2 == Suffixhash2)
            border.push_back(len);
    }

    for (auto idx : border)
        cout << idx << " ";
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
    // cin>>t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
}
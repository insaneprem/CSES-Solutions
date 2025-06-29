#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const int MOD1 = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int MOD3 = 998244353;
const int p1 = 31;
const int p2 = 37;
const int p3 = 41;
int get_hash(string str, int p, int MOD)
{
    int hash = 0;

    for (auto ch : str)
        hash = (hash * p + (ch - 'a' + 1)) % MOD;

    return hash;
}
void solve()
{
    string str, pattern;
    cin >> str >> pattern;

    int n = str.size(), m = pattern.size();
    if (m > n)
    {
        cout << 0;
        return;
    }
    int pattern_hash1 = get_hash(pattern, p1, MOD1);
    int pattern_hash2 = get_hash(pattern, p2, MOD2);
    int pattern_hash3 = get_hash(pattern, p3, MOD3);

    int pow1 = 1, pow2 = 1, pow3 = 1;

    for (int i = 0; i < m - 1; i++)
    {
        pow1 = (pow1 * p1) % MOD1;
        pow2 = (pow2 * p2) % MOD2;
        pow3 = (pow3 * p3) % MOD3;
    }

    int curr_hash1 = get_hash(str.substr(0, m), p1, MOD1);
    int curr_hash2 = get_hash(str.substr(0, m), p2, MOD2);
    int curr_hash3 = get_hash(str.substr(0, m), p3, MOD3);

    int count = 0;
    if (pattern_hash1 == curr_hash1 && pattern_hash2 == curr_hash2 && pattern_hash3 == curr_hash3)
        count = 1;

    for (int i = m; i < n; i++)
    {
        curr_hash1 = ((((curr_hash1 - (((str[i - m] - 'a' + 1) * pow1) % MOD1) + MOD1) % MOD1) * p1) + (str[i] - 'a' + 1)) % MOD1;
        curr_hash2 = ((((curr_hash2 - (((str[i - m] - 'a' + 1) * pow2) % MOD2) + MOD2) % MOD2) * p2) + (str[i] - 'a' + 1)) % MOD2;
        curr_hash3 = ((((curr_hash3 - (((str[i - m] - 'a' + 1) * pow3) % MOD3) + MOD3) % MOD3) * p3) + (str[i] - 'a' + 1)) % MOD3;

        if (curr_hash1 == pattern_hash1 && curr_hash2 == pattern_hash2 && curr_hash3 == pattern_hash3)
            count++;
    }

    cout << count;
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
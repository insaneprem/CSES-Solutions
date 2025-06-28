#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
void solve()
{
    string str;
    cin >> str;

    map<char, int> freq;
    for (auto ch : str)
        freq[ch]++;

    char odd = '*';
    int oddfreq = 0;

    string front = "";
    int cnt = 0;

    for (auto i : freq)
    {
        cnt += (i.second % 2 == 1);
        if (i.second % 2 == 1 && odd == '*')
        {
            odd = i.first;
            oddfreq = i.second;
        }
        else
            front += string(i.second / 2, i.first);
    }

    if (cnt > 1)
    {
        cout << "NO SOLUTION";
        return;
    }
    string back = string(front.rbegin(), front.rend());
    if (odd != '*')
        front += string(oddfreq, odd);
    front += back;

    cout << front;
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
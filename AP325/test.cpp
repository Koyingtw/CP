#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = 1;
    }
    int cnt = 0;
    for (auto &e : mp)
    {
        e.second = cnt;
        cnt++;
    }
    for (int i = 0; i < n; i++)
        cout << mp[a[i]] << ' ';
    cout << endl;
    system("pause");
    return 0;
}
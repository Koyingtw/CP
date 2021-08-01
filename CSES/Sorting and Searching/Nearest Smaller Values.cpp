#include <bits/stdc++.h>
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

void sol()
{
    int n;
    while (cin >> n)
    {
        pr x[n];
        stack<pr> s;
        vector<int> ans;
        cin >> x[0].F;
        x[0].S = 1;
        ans.emplace_back(0);
        s.push(x[0]);
        for (int i = 1; i < n; i++)
        {
            cin >> x[i].F;
            x[i].S = i + 1;
            bool yes = 1;
            while (s.top().F >= x[i].F)
            {
                s.pop();
                if (s.size() == 0)
                {
                    ans.emplace_back(0);
                    yes = 0;
                    break;
                }
            }
            if (yes)
                ans.emplace_back(s.top().S);
            s.push(x[i]);
        }
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}


#include <bits/stdc++.h>
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MEM(x, n) memset(x, n, sizeof(x));

using namespace std;
int x[5][5] = {
    {33, 55, 3, 64, 5},
    {26, 7, 18, 19, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 8, 70, 20},
    {9, 32, 23, 24, 25}};

void sol()
{
    int n;
    while (cin >> n)
    {
        cin.ignore();
        fr(i, 0, n)
        {
            bool b[5][5];
            for (int i = 0; i < 5; i++)
                MEM(b[i], 0);
            string s;
            getline(cin, s);
            stringstream ss;
            ss << s;
            int a;
            while (ss >> a)
            {
                fr(i, 0, 5)
                {
                    fr(j, 0, 5)
                    {
                        if (x[i][j] == a)
                            b[i][j] = 1;
                    }
                }
            }
            //cout<<b[4][2]<<endl;
            vector<int> ans;
            fr(i, 0, 5)
            {
                int find = 0, cnt = 0;
                fr(j, 0, 5)
                {
                    if (b[i][j] == 0)
                        find = x[i][j];
                    else
                        cnt++;
                }
                if (cnt == 4)
                    ans.push_back(find);
            }
            //cout<<ans.size();
            fr(j, 0, 5)
            {
                int find = 0, cnt = 0;
                fr(i, 0, 5)
                {
                    if (b[i][j] == 0)
                        find = x[i][j];
                    else
                        cnt++;
                }
                if (cnt == 4)
                    ans.push_back(find);
            }
            //cout<<ans.size();
            int find = 0, cnt = 0;
            fr(i, 0, 5)
            {
                if (b[i][i] == 0)
                    find = x[i][i];
                else
                    cnt++;
            }
            if (cnt == 4)
                ans.push_back(find);
            //cout<<ans.size();
            find = 0, cnt = 0;
            fr(i, 0, 5)
            {
                if (b[5 - i - 1][i] == 0)
                    find = x[5 - i - 1][i];
                else
                    cnt++;
            }
            if (cnt == 4)
                ans.push_back(find);
            //cout<<ans.size();
            map<int, int> m;
            if (ans.size() == 0)
                cout << -1 << endl;
            else
            {
                vector<int> out;
                sort(ans.begin(), ans.end());
                fr(i, 0, ans.size())
                {
                    m[ans[i]]++;
                }
                int mx = 0;
                map<int, int>::iterator it;
                for (it = m.begin(); it != m.end(); it++)
                {
                    mx = max(mx, it->second);
                }
                for (it = m.begin(); it != m.end(); it++)
                {
                    if (it->second == mx)
                        out.push_back(it->first);
                }
                cout << out[0];
                for (int i = 1; i < out.size(); i++)
                    cout << " " << out[i];
                cout << endl;
            }
        }
    }
}

signed main()
{
    Koying
    sol();
    return 0;
}
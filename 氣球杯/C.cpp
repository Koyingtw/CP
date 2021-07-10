/*
.-..-.             _             
: :' ;            :_;            
:   '  .--. .-..-..-.,-.,-. .--. 
: :.`.' .; :: :; :: :: ,. :' .; :
:_;:_;`.__.'`._. ;:_;:_;:_;`._. ;
             .-. :          .-. :
             `._.'          `._.'
*/

#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define fr(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
const int INF = 0x3f3f3f3f;
using namespace std;

void OUT(string s)
{
    cout << s;
    return;
}
string a = "PSR", b = "RPS"; // a win b
map<char, char> win;
void sol()
{
    int t;
    while (cin >> t)
    {
        while (t--)
        {
            int n;
            bool yes = true;
            cin >> n;
            string s;
            cin >> s;
            map<char, int> m;
            fr(i, 0, 3)
            {
                win[b[i]] = a[i];
            }
            fr(i, 0, n)
            {
                m[s[i]]++;
                if (i && s[i] != s[i - 1])
                    yes = 0;
            }
            if (yes)
            {
                cout << 1 << endl;
                cout << win[s[0]] << endl;
            }
            else if (m.size() == 2)
            {
                cout << 1 << endl;
                if (m['R'] == 0)
                {
                    DB("S");
                }
                else if (m['P'] == 0)
                {
                    DB('R');
                }
                else
                    cout << 'P' << endl;
            }
            else
            {
                if (m['P'] > m['R'])
                {
                    cout << 1 << endl;
                    cout << 'S' << endl;
                }
                else if (m['S'] > m['P'])
                {
                    cout << 1 << endl;
                    cout << 'R' << endl;
                }
                else if (m['R'] > m['S'])
                {
                    cout << 1 << endl;
                    cout << 'P' << endl;
                }
                else
                {
                    string as[6];
                    bool d = 1;
                    as[0] = "RP";
                    as[1] = "RS";
                    as[2] = "PS";
                    as[3] = "PR";
                    as[4] = "SR";
                    as[5] = "SP";
                    fr(i, 0, 6)
                    {
                        int sum = 0;
                        fr(j, 0, n)
                        {
                            if (s[j] == win[as[i][j % 2]])
                                sum--;
                            else if (s[j] != as[i][j % 2])
                                sum++;
                        }
                        if (sum > 0)
                        {
                            cout << 2 << endl;
                            cout << as[i] << endl;
                            d = 0;
                            break;
                        }
                    }
                    if (d == 0)
                        continue;
                    vector<string> ans;
                    fr(i, 0, 3)
                    {
                        fr(j, 0, 3)
                        {
                            fr(k, 0, 3)
                            {
                                string ss;
                                ss += b[i];
                                ss += b[j];
                                ss += b[k];
                                ans.push_back(ss);
                            }
                        }
                    }
                    fr(i, 0, 27)
                    {
                        int sum = 0;
                        fr(j, 0, n)
                        {
                            if (s[j] == win[ans[i][j % 3]])
                                sum--;
                            else if (s[j] != ans[i][j % 3])
                                sum++;
                        }
                        if (sum > 0)
                        {
                            if (ans[i][0] == ans[i][2])
                                continue;
                            cout << 3 << endl;
                            cout << ans[i] << endl;
                            break;
                        }
                    }
                }
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
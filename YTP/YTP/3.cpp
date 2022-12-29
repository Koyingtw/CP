#pragma region
#include <bits/stdc++.h>
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pr pair<int, int>
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define DB(a) cout << a << endl;
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#if ONLINE_JUDGE
#define endl "\n"
#endif
#define lowbit(x) x &(-x)
const int INF = 0x3f3f3f3f;
using namespace std;
#pragma endregion
/******************************************************************************/
const double pi = 3.141592653589793;
void sol()
{
    string s, tmp;
    pair<double, double> ans = {0.0, 0.0};
    int deg = 0;
    while (cin >> tmp && tmp != "quit")
    {
        s = "";
        for (int i = 0; i < tmp.size(); i++)
        {
            if (i && tmp[i - 1] == ',')
                s += " ";
            s += tmp[i];
            if (i != tmp.size() - 1 && tmp[i + 1] == ',')
                s += " ";
        }
        stringstream f("");
        f << s;
        string ss = "";
        int m;
        f >> ss;
        while (f >> tmp)
        {
            if (isdigit(tmp[0]))
                m = stoi(tmp);
        }
        if (ss == "up")
            ans.S += m;
        else if (ss == "down")
            ans.S -= m;
        else if (ss == "left")
            ans.F -= m;
        else if (ss == "right")
            ans.F += m;
        else if (ss == "turnright")
            deg = (deg - m + 360) % 360;
        else if (ss == "turnleft")
            deg = (deg + m) % 360;
        else if (ss == "home")
            ans = {0.0, 0.0};
        else if (ss == "quit")
            break;
        else if (ss == "forward")
        {
            ans.F += m * cos((pi * deg / 180.0));
            ans.S += m * sin((pi * deg / 180.0));
        }
        else if (ss == "backward")
        {
            ans.F -= m * cos((pi * deg / 180.0));
            ans.S -= m * sin((pi * deg / 180.0));
        }
        //cout << deg << " " << ans.F << " " << ans.S << endl;
    }
    cout << fixed << setprecision(2) << ans.F << "," << fixed << setprecision(2) << ans.S << endl;
    //stop
}

signed main()
{
    Koying;
    int t = 1;
    //while (cin >> t)
    while (t--)
    {
        sol();
    }
    return 0;
}
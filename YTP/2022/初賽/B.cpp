#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define F first
#define S second
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define cmax(a, b) a = (a > b ? a : b)
#define cmin(a, b) a = (a < b ? a : b)
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

int dis(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); i++)
        cnt += a[i] != b[i];
    return cnt;
}

void sol() {
	string a, b;
    cin >> a >> b;
    n = a.size(), m = b.size();


    vector<string> ans;

    for (int i = 0; i + n - 1 < m; i++) {
        string tmp = b.substr(i, n);
        if (dis(tmp, a) <= 1) {
            ans.pb(tmp);
        }
    }
    sort(all(ans));

    if (!ans.size())
        cout << "Not found" << endl;
    else
        for (auto x : ans)
            cout << x << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
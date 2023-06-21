#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll long long
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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

void sol() {
    cin >> n;
    string a;
    for (int i = 1; i < n && a.size() <= 30; i++) {
        a += to_string(i);
        string ans = a + to_string(i + 1);
        int nxt = i + 2;
        int now = stoll(ans) % n;
        // cout << stoll(ans) << endl;
        while (now != 1) {
            if (ans.size() > 100)
                break;
            int ten = pow(10, (int)log10(nxt) + 1);
            // cout << ten << endl;
            ans += to_string(nxt);
            now = (now * ten + nxt) % n;
            // cout << ans << ' ' << now << endl;
            nxt++;
        }
        if (now == 1) {
            cout << "YES" << endl;
            cout << a << ' ' << ans << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
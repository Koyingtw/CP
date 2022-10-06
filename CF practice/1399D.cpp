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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
string s;
int pos[MAXN];

void sol() {
    cin >> n >> s;
    set<int, greater<int>> st[2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (st[!(s[i] - '0')].size() == 0) {
            ans++;
            st[s[i] - '0'].insert(ans);
            pos[i] = ans;
        }
        else {
            pos[i] = *st[!(s[i] - '0')].begin();
            st[!(s[i] - '0')].erase(st[!(s[i] - '0')].begin());
            st[s[i] - '0'].insert(pos[i]);
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << pos[i] << ' ';
    cout << endl;
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
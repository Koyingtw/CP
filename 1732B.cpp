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
int cnt[2][MAXN];
int pre[MAXN];

void sol() {
    cin >> n;
    cin >> s;
    s = " " + s;
    
    int need = 1, tmp = 0;
    for (int i = 1; i <= n; i++) {
        cnt[0][i] = cnt[0][i - 1] + ((s[i] - '0') == need);
        if (s[i] - '0' == need) {
            tmp++;
            need ^= 1;
        }
        // cnt[0][i] = tmp;
    }
    need = tmp = 0;
    for (int i = 1; i <= n; i++) {
        cnt[1][i] = cnt[1][i - 1] + ((s[i] - '0') == need);
        if (s[i] - '0' == need) {
            tmp++;
            need ^= 1;
        }
        pre[i] = pre[i - 1] + (s[i] - '0');
    }

    // cout << min(cnt[0][n], cnt[1][n]) << endl;
    // return;

    int ans = INF;

    for (int i = 0; i <= n; i++) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (pre[mid] - pre[i] == mid - i)
                l = mid;
            else
                r = mid - 1;
        }
        cmin(ans, cnt[0][i] + cnt[1][n] - cnt[1][l]);
    }

    cout << ans << endl;
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
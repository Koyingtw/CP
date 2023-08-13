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
const int P = 1010101333;
const int Q = 1e6 + 99;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int pre[MAXN];

void sol() {
    cin >> n >> m;
    string s;
    cin >> s;
    set<int> st0, st1;

    s = " " + s;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '1');
        (s[i] == '0' ? st0.insert(i) : st1.insert(i));            
    }

    set<pii> ans;
    bool same = false;

    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;

        // same with no sort
        int cnt = pre[r] - pre[l - 1];
        if (pre[r] - pre[r - cnt] == cnt) {
            same = true;
            continue;
        }
            

        int L, R;
        bool legal = false;

        L = 1, R = l;
        while (L < R) {
            int mid = (L + R) / 2;
            if (pre[l - 1] - pre[mid - 1] == 0)
                R = mid, legal = true;
            else
                L = mid + 1;
        }
        if (legal)
            l = R;.

        L = r, R = n;
        legal = false;
        while (L < R) {
            int mid = (L + R + 1) / 2;
            if (pre[mid] - pre[r] == mid - r)
                L = mid, legal = true;
            else
                R = mid - 1;
        }
        if (legal)
            r = L;
        ans.insert({l, r});
        // cout << l << ' ' << r << endl;
    }
    
    cout << ans.size() + same << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    cout << "test" << endl;
    return 0;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
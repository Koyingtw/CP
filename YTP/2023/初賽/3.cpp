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
#define MAXN 2000005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int pre[MAXN];
int suf[MAXN];

void sol() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pre[i] = pre[i - 1] + x[i];
        sum += x[i];
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        x[i] = x[i - n];
        pre[i] = pre[i - 1] + x[i];
    }
    suf[2 * n + 1] = 0;
    for (int i = 2 * n; i > 0; i--) {
        suf[i] = suf[i + 1] + x[i];
    }
    deque<pii> mx, mn;
    for (int i = 1; i <= n; i++) {
        while (!mx.empty() && mx.back().F <= suf[i]) {
            mx.pop_back();
        }
        mx.push_back({suf[i], i});
        while (!mn.empty() && mn.back().F >= suf[i]) {
            mn.pop_back();
        }
        mn.push_back({suf[i], i});
    }

    for (int i = n + 1; i <= n * 2; i++) {
        while (!mx.empty() && mx.back().F <= suf[i]) {
            mx.pop_back();
        }
        mx.push_back({suf[i], i});
        while (!mn.empty() && mn.back().F >= suf[i]) {
            mn.pop_back();
        }
        mn.push_back({suf[i], i});


        while (!mx.empty() && mx.front().S < i - n)
            mx.pop_front();
        while (!mn.empty() && mn.front().S < i - n)
            mn.pop_front();
        cout << sum - mx.front().F + suf[i] << ' ' << sum - mn.front().F + suf[i] << endl;
        // cout << mx.front().F << ' ' << mn.front().F << endl;

    }
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
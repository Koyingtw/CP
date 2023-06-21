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
    pii mx(0, 0), mn(INFLL, 0);
    int h;
    cin >> n;
    cin >> h;
    mx = pii(h, 1);
    for (int i = 2, h; i <= n; i++) {
        auto tmpmx = mx, tmpmn = mn;
        cin >> h;
        if (h < tmpmn.F)
            mn.F = h;
        if (h > tmpmx.F)
            mx.F = h;
        if (h < tmpmx.F && tmpmx.S + 1 > tmpmn.S)
            mn = pii(h, tmpmx.S + 1);
        else if (h < tmpmx.F && tmpmx.S + 1 == tmpmn.S && h < tmpmn.F)
            mn = pii(h, tmpmx.S + 1);
        if (h > tmpmn.F && tmpmn.S + 1 > tmpmx.S)
            mx = pii(h, tmpmn.S + 1);
        else if (h > tmpmn.F && tmpmn.S + 1 == tmpmx.S && h > tmpmx.S)
            mx = pii(h, tmpmn.S + 1);
    }
    cout << mx.S << endl;;
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
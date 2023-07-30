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
int x[MAXN], y[MAXN], pre[MAXN];
int times[MAXN], add[MAXN], ans[MAXN];

int getsum(int l, int r) {
    return pre[r] - pre[l - 1];
}


void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        times[i] = add[i] = ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        pre[i] = pre[i - 1] + y[i];
    }
    for (int i = 1; i <= n; i++) {
        if (x[i] <= y[i]) {
            add[i] += x[i];
            continue;
        }

        int l = i, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (getsum(i, mid) <= x[i])
                l = mid;
            else
                r = mid - 1;
        }
        times[i]++;
        times[l + 1]--;
        add[l + 1] += x[i] - getsum(i, l);
    }

    for (int i = 1; i <= n; i++) {
        times[i] = times[i] + times[i - 1];
        ans[i] = times[i] * y[i] + add[i];
        cout << ans[i] << ' ';
    }
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
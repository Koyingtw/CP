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
#define MAXN 20005
#define MAXM 1000005 
int n, m;
int x[MAXN], y[MAXN];

int msort(int l, int r, int k) {
    if (l == r)
        return 0;
    int mid = (l + r) / 2;
    int cnt = msort(l, mid, k) + msort(mid + 1, r, k);

    vector<int> tmp;
    int i = l, j = mid + 1;

    for (; j <= r; j++) {
        while (i <= mid && x[i] <= x[j] - k)
            i++;
        cnt += i - l;
    }

    i = l, j = mid + 1;

    for (; j <= r && i <= mid; j++) {
        while (i <= mid && x[i] <= x[j]) {
            tmp.pb(x[i]);
            i++;
        }
        tmp.pb(x[j]);
    }

    while (j <= r) {
        tmp.pb(x[j]);
        j++;
    }
    while (i <= mid) {
        tmp.pb(x[i]);
        i++;
    }

    for (int i = 0; i < tmp.size(); i++)
        x[i + l] = tmp[i];
    return cnt;
}

void sol() {
    y[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        y[i] = y[i - 1] + y[i];
    }

    // cout << msort(0, n, 15) << endl;

    int l = -INF, r = INF;
    while (l < r) {
        for (int i = 0; i <= n; i++)
            x[i] = y[i];
        int mid = (l + r + 1) / 2;
        int q = msort(0, n, mid);
        if (q >= m)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    //while (cin >> t)
	{
    	while (t--) {
            while (cin >> n >> m && n + m)
                sol();
        }
    }
        
    return 0;
}
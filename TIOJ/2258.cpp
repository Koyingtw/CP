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
#define MAXN 1000005
#define MAXM 1000005 
int n, k, p;
int h[MAXN];
int delta[MAXN];

int ST[25][MAXN];

void build() {
    for (int i = 1; i <= n; i++)
        ST[0][i] = delta[i];
    for (int i = 1; i <= __lg(n); i++) {
        for (int j = 1; j <= n; j++)
            ST[i][j] = max(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
}

int query(int l, int r) {
    int k = __lg(r - l + 1);
    return max(ST[k][l], ST[k][r - (1 << k) + 1]);
}

int cal(int l, int r) {
    int mn = INF;
    int rng = r - l + 1;

    if (rng == 2) 
        return h[r] - h[l];

    if (rng % 2 == 0) {
        int mx = 0;
        cmax(mx, query(l + 2, r));
        // cmax(mx, h[r] - h[r - 1]);
        // cmax(mx, h[l + 1] - h[l]);
        cmin(mn, mx);
    }
    else {
        int mx = 0;
        cmax(mx, query(l + 2, r));
        // cmax(mx, h[r] - h[r - 2]);
        // cmax(mx, h[r] - h[r - 1]);
        // cmax(mx, h[l + 1] - h[l]);
        cmin(mn, mx);
    }
    return mn;
}

bool check(int mid) {
    int last = 0;
    int cnt = 0;
    for (int i = k; i <= n; i++) {
        if (cal(i - k + 1, i) <= mid) {
            i += k - 1;
            cnt++;
        }
    }
    // cout << mid << ' ' << cnt << endl;
    return cnt >= p;
}

void sol() {
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    if (k == 1) {
        cout << 0 << endl;
        return;
    }


    sort(h + 1, h + n + 1);
    for (int i = 3; i <= n; i++)
        delta[i] = h[i] - h[i - 2];
    build();
    // for (int i = 1; i <= n; i++)
    //     cout << h[i] << ' ';
    // cout << endl;

    int l = 0, r = INF;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << endl;
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
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define MAXN 100005
#define MAXM 1000005 
int n, m, sq;
int x[MAXN];
pii ans[MAXM];
array<int, 3> q[MAXM];

bool cmp(array<int, 3> &_a, array<int, 3> &_b) {
    if (_a[0] / sq != _b[0] / sq)
        return _a[0] < _b[0];
    else
        return _a[1] < _b[1];
}

struct Mo_Algo {
    int cnt[MAXN];
    map<int, int, greater<int>> ans;

    void update(int tar, int delta) {
        tar = x[tar];
        if (!(--ans[cnt[tar]])) {
            ans.erase(cnt[tar]);
        }
        cnt[tar] += delta;
        ++ans[cnt[tar]];
    }
} Mo;

void sol() {
    cin >> n >> m;
    sq = sqrt(n);

    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 0; i < m; i++) {
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }

    sort(q, q + m, cmp);

    int l = 0, r = 0;
    for (int i = 0; i < m; i++) {
        while (r < q[i][1]) {
            ++r;
            Mo.update(r, 1);
        }
        while (r > q[i][1]) {
            Mo.update(r, -1);
            --r;
        }
        while (l < q[i][0]) {
            Mo.update(l, -1);
            ++l;
        }
        while (l > q[i][0]) {
            --l;
            Mo.update(l, 1);
        }  
        ans[q[i][2]] = *Mo.ans.begin();
    }

    for (int i = 0; i < m; i++)
        cout << ans[i].F << ' ' << ans[i].S << endl;
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
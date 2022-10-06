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
vector<int> x(MAXN);

bool check(int mid) {
    auto y = x;
    int cnt = m;
    for (auto &it: y) {
        if (it * 2 < mid) {
            cnt--;
            it = 1e9;
        }
    }
    int mx = 0, mn = *min_element(all(y));

    for (int i = 0; i < n - 1; i++) {
        if (cnt == 0)
            cmax(mx, min(min(y[i], y[i + 1]), mn * 2));
        else if (cnt == 1) 
            cmax(mx, min(max(y[i], y[i + 1]), mn * 2));
        else
            cmax(mx, min(mn * 2, 1e9));
    }

    return cnt >= 0 && mx >= mid;
}

void sol() {
	cin >> n >> m;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    int l = 0, r = INF;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
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
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
int n, q;
int x[MAXN];
bitset<MAXN> ans;

int check(int mid) {
    int tmp = q, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i < mid) {
            cnt += (x[i] <= tmp);
            ans[i] = (x[i] <= tmp);
        }
        else {
            cnt++;
            if (tmp <= 0)
                return -1;
            tmp -= (x[i] > tmp);
            ans[i] = 1;
        }
    }
    return cnt;
}

void sol() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r) / 2;

        auto check = []()
        
        if (check(mid) >= 0)
            r = mid;
        else
            l = mid + 1;
    }

    check(r);

    for (int i = 0; i < n; i++)
        cout << ans[i];

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
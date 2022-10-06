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

struct Fenwick_tree {
    int arr[MAXN];

    void init() {
        for (int i = 0; i < MAXN; i++)
            arr[i] = 0;
    }

    void udpate(int i, int val) {
        for (; i < MAXN; i += lowbit(i))
            arr[i] += val;
    }

    int query(int i) {
        int res = 0;
        for (; i; i -= lowbit(i))
            res += arr[i];
        return res;
    }
} x, y;

map<int, int> cntx, cnty;

void sol() {
    cin >> n >> m;
    x.init();
    y.init();

    for (int i = 0, k, x1, y1, x2, y2; i < m; i++) {
        cin >> k;
        if (k == 1) {
            cin >> x1 >> y1;
            if (cntx[x1] == 0) {
                x.udpate(x1, 1);
            }
            if (cnty[y1] == 0) {
                y.udpate(y1, 1);
            }
            cntx[x1]++;
            cnty[y1]++;
        }
        else if (k == 2) {
            cin >> x1 >> y1;
            if (cntx[x1] == 1) {
                x.udpate(x1, -1);
            }
            if (cnty[y1] == 1) {
                y.udpate(y1, -1);
            }
            cntx[x1]--;
            cnty[y1]--;
        }
        else {
            cin >> x1 >> y1 >> x2 >> y2;
            bool ans = (x.query(x2) - x.query(x1 - 1) == (x2 - x1 + 1) || y.query(y2) - y.query(y1 - 1) == (y2 - y1 + 1));
            cout << (ans > 0 ? "Yes" : "No") << endl;
        }
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
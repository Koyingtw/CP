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
const int P = 1e9 + 9;
const int Q = 1e6 + 99;

using namespace std;
/******************************************************************************/
#define MAXN 205
#define MAXM 1000005 
int n, m;

vector<int> x, y;

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) {
            ret *= a;
            ret %= P;
        }
        a *= a;
        a %= P;
        b /= 2;
    }
    return ret;
}

ㄉㄞㄉㄞ

Segment_Tree<Node> seg1, seg2;

void sol() {
    cin >> n >> m;
    x.resize(n + 1), y.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        y[n - i + 1] = x[i];
    }
    reverse(y.begin() + 1, y.end());
    seg1.init();
    seg2.init();
    seg1.build(x);
    seg2.build(y);




    int op, a, b;
    int tmp = 0;
    while (m--) {
        cin >> op >> a >> b;
        a ^= tmp;
        b ^= tmp;
        if (op == 1) {
            seg1.update(a, b);
            seg2.update(n - a + 1, b);
            // x[a] = b;
        }
        else {
            set<int> st;
            int ans;
            for (int i = a; i <= b; i++) {
                for (int j = i; j <= b; j++) {
                    st.insert(((seg1.query(a, i - 1) + seg2.query(n - j + 1, n - i + 1)) + seg1.query(j + 1, b)).hash % P);
                }
            }
            // ans++;
            ans = st.size();
            cout << st.size() << endl;
            tmp = ans % (1 << 20);
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
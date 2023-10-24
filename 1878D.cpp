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
int n, m, q;
string s;
int l[MAXN], r[MAXN], x[MAXN];

map<pii, int> cnt[MAXN];

void sol() {
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        cnt[i].clear();
        l[i]--;
    }
    for (int i = 0; i < m; i++) {
        cin >> r[i];
        r[i]--;
    }
    cin >> q;
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> x[i];
        x[i]--;
        int index = lower_bound(r, r + m, x[i]) - r;
        a = min(x[i], r[index] + l[index] - x[i]), b = max(x[i], r[index] + l[index] - x[i]);
        cnt[index][pii(a, b)]++;        
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        int last = -1;
        for (auto it: cnt[i]) {
            if (sum % 2) {
                for (int j = last; j < it.F.F; j++) {
                    int id = l[i] - j; // count to j from l[i];
                    swap(s[j], s[r[i] + id]);
                }
            }
            sum += it.S;
            last = it.F.F;
        }
        if (sum % 2) {
            for (int j = last; j <= r[i]; j++) {
                int id = l[i] - j;
                if (j >= r[i] + id) break;
                swap(s[j], s[r[i] + id]);
            }
        }
    }

    cout << s << endl;
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
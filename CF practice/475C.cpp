#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];
map<int, int> mp;

struct Sparse_Table { // ST with gcd
    int st[20][MAXN];

    void build() {
        for (int i = 0; i < n; i++) {
            st[0][i] = x[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                st[j][i] = __gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = __lg(r - l + 1);
        int ans = __gcd(st[k][l], st[k][r - (1 << k) + 1]);
        return ans;
    }
} ST;

void sol() {
	cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ST.build();

    for (int i = 0; i < n; i++) {
        int now = i;
        while (now < n) {
            mp[ST.query(i, now)]++;
            for (int j = 20; ~j; j--) {
                if (now + (1 << j) < n) {
                    int gcd = ST.query(i, now + (1 << j));
                    if (gcd == ST.query(i, now)) {
                        mp[gcd] += (1 << j);
                        now += (1 << j);
                    }
                }
            }
            now++;
        }
    }

    cin >> m;
    while (m--) {
        int q;
        cin >> q;
        cout << mp[q] << endl;
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
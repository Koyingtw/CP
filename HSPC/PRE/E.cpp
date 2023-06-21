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
array<int, 4> Q[MAXN];

struct Fenwick_Tree {
    int arr[MAXN];
    void update(int i, int v) {
        for (; i <= n; i += lowbit(i)) {
            arr[i] += v;
        }
    }
    int query(int i) {
        int ans = 0;
        for (; i; i -= lowbit(i)) {
            ans += arr[i];
        }
        return ans;
    }
} BIT1, BIT2, BIT3, BIT4, BIT5, BIT6; // <, >, =

int ans[MAXN];

void sol() {
    cin >> n >> m;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    queue<pii> same;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        BIT2.update(i, a);
        BIT4.update(i, 1);
        pq.push({a, i});
    }

    for (int i = 0; i < m; i++) {
        cin >> Q[i][1] >> Q[i][2] >> Q[i][0];
        Q[i][3] = i;
    }

    sort(Q, Q + m);

    for (int i = 0; i < m; i++) {
        while (same.size() && same.front().F < Q[i][0]) {
            int pos = same.front().S;
            BIT1.update(pos, same.front().F);
            BIT3.update(pos, 1);
            same.pop();
        }

        while (pq.size() && pq.top().F <= Q[i][0]) {
            if (pq.top().F == Q[i][0]) {
                int pos = pq.top().S;
                BIT2.update(pos, -pq.top().F);
                BIT4.update(pos, -1);

                same.push(pq.top());
                pq.pop();
            }
            else {
                int pos = pq.top().S;
                BIT2.update(pos, -pq.top().F);
                BIT4.update(pos, -1);

                BIT1.update(pos, pq.top().F);
                BIT3.update(pos, 1);
                pq.pop();
            }

        }
        int tmp = 0;
        tmp += abs(Q[i][0] * (BIT3.query(Q[i][2]) - BIT3.query(Q[i][1] - 1)) - (BIT1.query(Q[i][2]) - BIT1.query(Q[i][1] - 1)));
        tmp += abs(Q[i][0] * (BIT3.query(Q[i][2]) - BIT3.query(Q[i][1] - 1)) + (BIT1.query(Q[i][2]) - BIT1.query(Q[i][1] - 1)));
        
        tmp += abs(Q[i][0] * (BIT4.query(Q[i][2]) - BIT4.query(Q[i][1] - 1)) - (BIT2.query(Q[i][2]) - BIT2.query(Q[i][1] - 1)));
        tmp += abs(Q[i][0] * (BIT4.query(Q[i][2]) - BIT4.query(Q[i][1] - 1)) + (BIT2.query(Q[i][2]) - BIT2.query(Q[i][1] - 1)));

        ans[Q[i][3]] = tmp;
        // cout << Q[i][0] << ' ' << tmp << endl;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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
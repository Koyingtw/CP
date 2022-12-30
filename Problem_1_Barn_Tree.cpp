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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int in[MAXN], in2[MAXN];
int w[MAXN], sub[MAXN];
vector<int> G[MAXN];
vector<pii> G2[MAXN];


void sol() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
        in[a]++;
        in[b]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) if (in[i] == 1) {
        q.push(i);
    }

    while (q.size()) {
        int now = q.front();
        q.pop();
        in[now] = -1;
        // cout << now << endl;
        for (int e: G[now]) {
            in[e]--;
            if (in[e] == 1) {
                q.push(e);
            }
            if (in[e] >= 0) {
                if (w[now] > sum / n) {
                    G2[now].pb({e, w[now] - sum / n});
                    // cout << now << ' ' << e << ' ' << w[now] - sum / n << endl;
                    in2[e]++;
                    w[e] += w[now] - sum / n;
                    w[now] = sum / n;
                }
                else if (w[now] < sum / n) {
                    G2[e].pb({now, sum / n - w[now]});
                    // cout << e << ' ' << now << ' ' << sum / n - w[now] << endl;
                    in2[now]++;
                    w[e] -= sum / n - w[now];
                    w[now] += sum / n - w[now];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) if (!in2[i]) {
        q.push(i);
    }

    vector<array<int, 3>> ans;
    while (q.size()) {
        int now = q.front();
        q.pop();

        for (auto e: G2[now]) {
            in2[e.F]--;
            if (in2[e.F] == 0) {
                q.push(e.F);
            }
            ans.pb({now, e.F, e.S});
        }
    }
    cout << ans.size() << endl;
    for (auto it: ans) {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
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
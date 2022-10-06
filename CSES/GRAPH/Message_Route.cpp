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
int from[MAXN];
vector<int> G[MAXN];

void sol() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    
    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int e: G[now]) {
            if (from[e] == 0) {
                from[e] = now;
                q.push(e);
            }
        }
    }

    if (from[n] == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;
    int now = n;
    while (now != 1) {
        ans.push_back(now);
        now = from[now];
    }
    ans.push_back(now);
    reverse(all(ans));

    cout << ans.size() << endl;
    for (int e: ans) {
        cout << e << " ";
    }
    cout << endl;
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
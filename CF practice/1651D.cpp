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
// const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
pii point[MAXN];
set<pii> p, vis;
queue<pii> q;
stack<pii> path;
map<pii, pii> ans;

const int P[] = {1, 0, -1, 0, 1};

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void sol() {
	cin >> n;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        p.insert({a, b});
        point[i] = {a, b};
    }

    for (int i = 0; i < n; i++) {
        auto [x, y] = point[i];

        for (int j = 0; j < 4; j++) {
            int xx = x + P[j], yy = y + P[j + 1];
            if (p.count({xx, yy})) 
                continue;
            ans[{x, y}] = {xx, yy};
            q.push({x, y});
        }
    }

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = x + P[i], yy = y + P[i + 1];
            if (!p.count({xx, yy})) 
                continue;
            if (!ans.count({xx, yy})) {
                q.push({xx, yy});
                ans[{xx, yy}] = ans[{x, y}];
            }
        }
    }


    for (int i = 0; i < n; i++)
        cout << ans[point[i]].F << " " << ans[point[i]].S << endl;
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
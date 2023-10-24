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
multiset<int> now;
vector<pair<vector<int>, int>> v;

void dfs(int i, int sum) {
    if (sum == 41) {
        vector<int> tmp;
        int tmp2 = 1;
        for (auto it: now) {
            tmp.pb(it);
            tmp2 *= it;
            // cout << it << ' ';
        }
        // cout << endl;
        v.pb(pair<vector<int>, int>(tmp, tmp2));
    }
    for (int j = i + 1; sum + j <= 41; j++) {
        for (int k = 1; sum + j * k <= 41; k++) {
            for (int l = 0; l < k; l++)
                now.insert(j);
            dfs(j, sum + j * k);
            now.erase(j);
        }
    }
}

void pre() {
    dfs(0, 0);
    sort(all(v), [&](auto &a, auto &b) {
        return a.F.size() < b.F.size();
    });
}

void sol(int id) {
    cout << "Case #" << id + 1 << ": ";
    cin >> n;
    int ans = 0;
    for (int j = 0; j < v.size(); j++) if (v[j].S == n) {
        cout << v[j].F.size() << ' ';
        for (int k = 0; k < v[j].F.size(); k++) {
            cout << v[j].F[k] << " \n"[k == v[j].F.size() - 1];
        }
        ans++;
        break;
    }

    if (ans == 0)
        cout << -1 << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	for (int i = 0; i < t; i++) {
            sol(i);
        }
    }
        
    return 0;
}
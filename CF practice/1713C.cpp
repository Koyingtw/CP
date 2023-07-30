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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
set<int> st[MAXN];
int cnt[MAXN];

void pre() {
    for (int i = 0; i < n; i++)
        st[i].clear(), cnt[i] = 0;
}

void sol() {
	cin >> n;
    pre();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j * j - i <= n; j++) {
            if (j * j - i >= 0) {
                st[j * j - i].insert(i);
                cnt[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ' ' << st[i].size() << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ' ' << cnt[i] << endl;
    }
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
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

map<char, pii> mp;
int dp[MAXN];

pair<int, int> operator +(pii _a, pii _b) {
    return {_a.F + _b.F, _a.S + _b.S};
}

void sol() {
	string s;
    cin >> s;
    set<pii> st;
    pii now(0, 0);
    // pii prev = now;

    mp['A'] = {-1, 1};
    mp['B'] = {0, 2};
    mp['C'] = {1, 1};
    mp['D'] = {1, -1};
    mp['E'] = {0, -2};
    mp['F'] = {-1, -1};

    vector<pii> path;
    vector<char> ans;
    map<pii, int> dis;
    path.pb({0, 0});
    dis[now] = 0;
    st.insert(now);
    MEM(dp, 0x3f);
    dp[0] = 0;

    // int ii = 0;
    for (int ii = 0; ii < (int)s.size(); ii++) {
        char c = s[ii];
        now = now + mp[c];
        st.insert(now);
    }

    queue<pii> q;
    q.push({0, 0});

    while (q.size()) {
        pii cur = q.front();
        q.pop();

        if (cur == now) {
            cout << dis[cur] << endl;
        }

        for (char j = 'A'; j <= 'F'; j++) {
            pii tmp = cur + mp[j];
            if (st.count(tmp) && !dis.count(tmp)) {
                dis[tmp] = dis[cur] + 1;
                q.push(tmp);
            }
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
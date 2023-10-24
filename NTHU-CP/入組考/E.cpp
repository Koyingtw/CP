#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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

void sol() {
    string s;
    cin >> s >> m;
    n = s.size();

    string ans;

    int now = 0;
    multiset<char> st;
    vector<int> pos[10];

    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].pb(i);
    }

    int cnt = 0;

    for (int i = 0; i < n && now < n; i++) {
        for (char c = '0'; c <= '9'; c++) {
            auto it = lower_bound(all(pos[c - '0']), now);
            if (it != pos[c - '0'].end() && cnt + (*it - now) <= m) {
                for (int j = now; j < *it; j++)
                    st.insert(s[j]);
                cnt += *it - now;
                now = *it + 1;
                ans += c;
                break;
            }
            else if (cnt + (n - now) <= m && st.find(c) != st.end()) {
                for (int j = now; j < n; j++)
                    st.insert(s[j]);
                ans += c;
                cnt += n - now;
                now = n;
                st.erase(st.find(c));
                break;
            }
        }
    }

    for (auto &it: st)
        ans += it;
    cout << ans << endl;
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
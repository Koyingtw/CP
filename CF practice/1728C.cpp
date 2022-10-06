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
int x[MAXN], y[MAXN];

void sol() {
    cin >> n;
    multiset<int> st1, st2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        st1.insert(x[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        st2.insert(y[i]);

        if (st1.find(y[i]) != st1.end()) {
            st1.erase(st1.find(y[i]));
            st2.erase(st2.find(y[i]));
        }
    }

    for (int i = 0; i < n; i++) {
        if (st1.find(x[i]) != st1.end() && x[i] >= 10) {
            st1.erase(st1.find(x[i]));
            x[i] = to_string(x[i]).size();
            ans++;
            if (st2.find(x[i]) != st2.end()) {
                st2.erase(st2.find(x[i]));
            }
            else {
                st1.insert(x[i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (st2.find(y[i]) != st2.end() && y[i] >= 10) {
            st2.erase(st2.find(y[i]));
            y[i] = to_string(y[i]).size();
            ans++;
            if (st1.find(y[i]) != st1.end()) {
                st1.erase(st1.find(y[i]));
            }
            else {
                st2.insert(y[i]);
            }
        }
    }

    st1.erase(1);
    st2.erase(1);
    ans += st1.size() + st2.size();
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
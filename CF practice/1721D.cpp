#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
pii a[MAXN], b[MAXN];

map<int, int> operator -(map<int, int> a, map<int, int> b) {
    for (auto i : b) {
        a[i.F] -= i.S;
    }
    return a;
}

void sol() {
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i].F;
        a[i].S = i;
        st.insert(a[i].F);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i].F;
        b[i].S = i;
    }
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int tmp = ans + (1 << i);
        multiset<int> tmpst;
        for (int j = 0; j < n; j++) {
            tmpst.insert(a[j].F & tmp);
        }
        bool legal = true;
        for (int j = 0; j < n; j++) {
            if (tmpst.find(((tmp ^ b[j].F) & tmp)) != tmpst.end()) {
                tmpst.erase(tmpst.find(((tmp ^ b[j].F) & tmp)));
            }
            else
                legal = false;
        }

        if (legal) {
            ans += (1 << i);
        }
    }
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
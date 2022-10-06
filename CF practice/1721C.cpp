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
int x[MAXN];
int y[MAXN];
pii ans[MAXN];

void sol() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    deque<int> dq;
    multiset<int> st;
    st.insert(y[n - 1]);
    dq.push_back(y[n - 1]);
    int choise = n - 1;
    for (int i = n - 1, j = n - 1; i >= 0; i--) {
        while (j - 1 >= 0 && y[j - 1] >= x[i]) {
            j--;
            dq.push_back(y[j]);
            st.insert(y[j]);
        }
        while (*st.begin() < x[choise]) {
            st.erase(st.lower_bound(x[choise]));
            choise--;
        }
        ans[i].F = y[j] - x[i];
        ans[i].S = *st.rbegin() - x[i];
        // cout << y[j + (n - 1 - choise)] << ' ';
    }
    // cout << endl;

    for (int i = 0; i < n; i++)
        cout << ans[i].F << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i].S << ' ';
    cout << endl;
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
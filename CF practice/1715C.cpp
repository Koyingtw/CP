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
set<int> st;

int cal(int l, int r) {
    int res = 0;

    if (l > r)
        return 0;

    res += (l - 1) * (n - r);
    res += (l - 1) * (r - l + 1);
    res += (r - l + 1) * (n - r);
    res += (1 + r - l + 1) * (r - l + 1) / 2;
    return res;
}

int getleft(int i) {
    int prev;
    if (x[i - 1] != x[i])
        prev = *(--st.upper_bound(i));
    else
        prev = *(--st.lower_bound(i));
    return prev;
}

int getright(int i)  {
    int nxt;
    if (x[i + 1] != x[i])
        nxt = *(st.lower_bound(i));
    else
        nxt = *st.upper_bound(i);
    return nxt;
}

void remove(int l, int r) {
    if (l > r)
        return;
    st.erase(l);
    st.erase(r);
}

void add(int l, int r) {
    if (l > r)
        return;
    st.insert(l);
    st.insert(r);
}

void sol() {
    cin >> n >> m;
    st.clear();
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    x[n + 1] = INF;
    st.insert(1);
    int last = 1, ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        if (x[i] != x[i - 1]) {
            st.insert(i - 1);
            st.insert(i);
            ans += cal(last, i - 1);
            
            last = i;
        }
    }
    st.insert(n);
    // cout << ans << endl;

    while (m--) {
        int i, k;
        cin >> i >> k;

        if (k == x[i]) {
            cout << ans << endl;
            continue;
        }

        int prev, nxt;
        
        nxt = getright(i);
        prev = getleft(i);
        ans -= cal(prev, nxt);
        remove(prev, nxt);

        int l, r; //new l, r
        if (prev == i) {
            if (x[i - 1] == k) {
                l = getleft(i - 1);
                ans -= cal(l, i - 1);
                remove(l, i - 1);
            }
            else
                l = i;
        }
        else
            l = i;
        
        if (nxt == i) {
            if (x[i + 1] == k) {
                r = getright(i + 1);
                ans -= cal(i + 1, r);
                remove(i + 1, r);
            }
            else
                r = i;
        }
        else
            r = i;

        ans += cal(l, r);
        ans += cal(prev, l - 1);
        ans += cal(r + 1, nxt);
        add(l, r);
        add(prev, l - 1);
        add(r + 1, nxt);

        x[i] = k;
        cout << ans << endl;
    }
}

signed main() {
    Weakoying;
    int t = 1;
    // while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
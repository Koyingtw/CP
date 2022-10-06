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
const int P = 998244353;
const int Q = 107;

using namespace std;
/******************************************************************************/
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int pre[MAXN], suf[MAXN];

void rolling_hash(string &s) {
    for (int i = 0; i <= n + 1; i++)
        pre[i] = suf[i] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] * Q + s[i];
        pre[i] %= P;
        suf[n - i + 1] = suf[n - i + 2] * Q + s[n - i + 1];
        suf[n - i + 1] %= P;
    }
}

int fastpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % P;
        }
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

int preget(int l, int r) {
    return ((pre[r] - pre[l - 1] * fastpow(Q, r - l + 1) % P) % P + P) % P;
}

int sufget(int l, int r) {
    return ((suf[l] - suf[r + 1] * fastpow(Q, r - l + 1) % P) % P + P) % P;
}


void sol() {
    string s;
    stack<char> st;
    cin >> n;
    cin >> s;
    s = " " + s;
    rolling_hash(s);
    int cnt = 0, ans = n, pos = 1;
    bool legal = true;

    for (int i = 1; i <= n; i++) {
        if (preget(pos, i) == sufget(pos, i) && pos != i) {
            cnt++;
            ans -= i - pos + 1;
            pos = i + 1;
            while (st.size())
                st.pop();
            legal = true;
            continue;
        }
        if (s[i] == '(') {
            st.push(s[i]);

        }
        else {
            if (st.size() && st.top() == '(') {
                st.pop();

                if (st.size() == 0 && legal) {
                    cnt++;
                    ans -= i - pos + 1;
                    pos = i + 1;
                }
            }
            else
                legal = false;
        }
    }
    cout << cnt << ' ' << ans << endl;
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
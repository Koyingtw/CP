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
// bitset<MAXM> b;
// set<int> st;

set<int> st;


int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void pre() {
    long long limit = 1e12;

    for (long long b = 2; b * b <= limit; b++) {
        for (long long n = 3; fpow(b, n) <= limit * (b - 1) + 1; n++) {
            long long num = (fpow(b, n) - 1) / (b - 1);
            st.insert(num);
        }
    }

}



bool isInSequence(long long num) {
    int b = 2;
    long long limit = (fpow(b, 3) - 1) / (b - 1);

    while (limit < num) {
        b++;
        limit = (fpow(b, 3) - 1) / (b - 1);
    }

    return limit == num;
}

// 6, 8, 10, 12, ...
// 25, 45, 65

void sol() {
    cin >> n;
    // cout << (b[n] ? "YES" : "NO") << endl;
    cout << (st.find(n) != st.end() ? "YES" : "NO") << endl;
    // cout << (isInSequence(n) ? "YES" : "NO") << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    pre();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
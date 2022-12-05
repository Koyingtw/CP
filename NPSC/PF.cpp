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

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % P;
        a = a * a % P;
        b >>= 1;
    }
    return ans;
}

void sol() {
    cin >> n;
    int mxlg = 0;
    int xor1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        xor1 ^= x[i];
    }
    mxlg = __lg(xor1);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += (x[i] > (1 << (mxlg)));
    }
    cout << cnt * fpow(n, P - 2) % P << endl;
    
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
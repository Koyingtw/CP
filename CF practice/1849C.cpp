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
const int P = 1010101333;
const int Q = 1e6 + 99;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int prehash[MAXN];
int one[MAXN];
int zero[MAXN];
int pre[MAXN];

int fpow(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1)
            ret = (ret * a) % P;
        a = (a * a) % P;
        b >>= 1;
    }
    return ret;
}

void preexe() {
    one[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        one[i] = one[i - 1] * Q + 1;
        one[i] %= P;
    }
    zero[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        zero[i] = zero[i - 1] * Q + 0;
        zero[i] %= P;
    }
}

void sol() {
    cin >> n >> m;
    string s;
    cin >> s;
    
    
    cout << st.size() << endl;
}

signed main() {
    Weakoying;
    int t = 1;
    preexe();
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
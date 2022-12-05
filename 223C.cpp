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
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 2005
#define MAXM 1000005 
int n, m;
int x[MAXN], ans[MAXN];

int p[MAXN];


int fpow(int a, int b) {
    int res = 1;
    int tmp = min(a, 1);
    while (b) {
        if (b % 2) {
            res *= tmp;
            res %= P;
        }

        a *= a;
        a %= P;
        b %= 2;
    }
    return res;
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    if (m == 0) {
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += (1 + (m - 1) * (i - j)) * x[j];
            sum %= P;
            cout << (1 + (m - 1) * (i - j)) << ' ';
        }
        // cout << sum << ' ';
        cout << endl;
    }
    cout << endl;
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
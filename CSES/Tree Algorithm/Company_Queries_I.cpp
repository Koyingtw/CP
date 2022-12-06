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
#pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;

struct Sparse_Table {
    int arr[20][MAXN];

    void build() {
        arr[0][1] = -1;
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = (arr[i - 1][j] == -1 ? -1 : arr[i - 1][arr[i - 1][j]]);
            }
        }
    }

    int jump(int now, int rng) {
        for (int i = 20; i >= 0; i--) {
            if ((1 << i) <= rng) {
                rng -= (1 << i);
                if (now != -1)
                    now = arr[i][now];
            }
        }
        return now;
    }
} ST;

void sol() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> ST.arr[0][i];
    }
    ST.build();

    int now, rng;
    while (m--) {
        cin >> now >> rng;
        cout << ST.jump(now, rng) << endl;
    }
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
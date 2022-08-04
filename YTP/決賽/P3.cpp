#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 1000005
#define MAXM 1000005 
int n, m;
vector<int> x(MAXN);

template<typename T>
struct RMQ_ST {
    T arr[25][MAXN];

    T pick(int &a, int &b) {
        return min(a, b);
    }

    void build(vector<T> &v, int n) {
        for (int i = 1; i <= n; i++)
            arr[0][i] = v[i];
        for (int i = 1; i <= __lg(n); i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = pick(arr[i - 1][j], arr[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        int rng = (1 << k);
        return pick(arr[k][l], arr[k][r - rng + 1]);
    }
};

RMQ_ST<int> ST;



void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] -= i;   
        // cout << x[i] << " ";
    }
    // cout << endl;

    ST.build(x, n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        while (l < r) {
            int mid = (l + r + 1) / 2;

            if (ST.query(i, mid) + i > 0) 
                l = mid;
            else
                r = mid - 1;
        }
        cmax(ans, l - i + 1);
    }
    cout << ans << endl;
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
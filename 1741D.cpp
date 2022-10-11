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
#define MAXN 300000
#define MAXM 1000005 
int n, m;
int x[MAXN], ans;
bool legal = true;

int f(int l, int r) {
    if (l == r)
        return x[l];
    int mid = (l + r) / 2;
    int ql = f(l, mid), qr = f(mid + 1, r);
    if (abs(ql - qr) != 1 || min(ql, qr) % 2 == 0) 
        legal = false;
    if (ql > qr)
        ans++;
    return max(ql, qr) / 2;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    ans = 0;
    legal = true;
    f(1, n);
    cout << (legal == true ? ans : -1) << endl;
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
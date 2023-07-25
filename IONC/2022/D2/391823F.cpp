#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int unsigned long long
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
#pragma optimize("Ofase", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

int check(int mid) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + x[i] > mid) {
            sum = x[i];
            cnt++;
        } else {
            sum += x[i];
        }
    }
    return cnt;
}

void sol() {
	cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int l = *max_element(x, x + n), r = 1e15;

    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid) <= m)
            r = mid;
        else
            l = mid + 1;
    }

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + x[i] > r) {
            ans += sum * sum;
            sum = x[i];
        } else {
            sum += x[i];
        }
    }
    ans += sum * sum;
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
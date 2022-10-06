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

vector<int> x(MAXN);
vector<int> last_change(MAXN, 0);
vector<pii> change_all;


void sol() {
    int sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    int k, l, r;
    
    for (int i = 1; i <= m; i++) {
        cin >> k;
        if (k == 1) {
            cin >> l >> r;
            if (change_all.size() == 0 || change_all[change_all.size() - 1].F < last_change[l]) {
                sum += r - x[l];
                x[l] = r;
                last_change[l] = i;
            }
            else {
                int idx = change_all.size() - 1;
                sum += r - change_all[idx].S;
                x[l] = r;
                last_change[l] = i;
            }
        }
        else {
            cin >> l;
            sum = l * n;
            change_all.pb({i, l});
        }
        cout << sum << endl;
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
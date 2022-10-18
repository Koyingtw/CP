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
int arr[MAXN];

multiset<int> operator &(multiset<int> _a, multiset<int> _b) {
    multiset<int> res;
    if (_a.size() > _b.size())
        swap(_a, _b);
    for (int it: _a) {
        auto iter = _b.find(it);
        if (iter != _b.end()) {
            res.insert(it);
            _b.erase(iter);
        }
    }
    return res;
}

void sol() {
    cin >> n;
    
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        arr[i] = a;
    }

    int now = 0;
    for (int i = 0; i < n; i++) {
        int add = 0;
        int tmp = 0;
        for (int j = 29; j >= 0; j--) {
            if (now & (1 << j))
                continue;
            for (int k = 1; k <= n; k++) {
                if ((arr[k] & (tmp | (1 << j))) == (tmp | (1 << j))) {
                    add = k;
                    tmp |= (1 << j);
                    break;
                }
            }
        }
        if (!add) {
            for (int j = 1; j <= n; j++)
                if (arr[j])
                    cout << arr[j] << ' ';
            cout << endl;
            return;
        }
        else {
            now |= arr[add];
            cout << arr[add] << ' ';
            arr[add] = 0;
        }
    }
    cout << endl;
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
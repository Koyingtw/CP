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

struct Node {
    int id, l, r;
} x[MAXN];

void sol() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        x[i].id = i;
        x[i].l = i + 1;
    }
    for (int i = 2; i <= n; i++) {
        x[i].id = i;
        x[i].r = i - 1;
    }
    x[1].r = -1;
    x[n].l = -1;


    cin >> m;
    int cnt = n, first = 1;
    int tmp = first;
    first = tmp;
    while (m--) {
        int t, k;
        cin >> t >> k;
        if (t == 0) {
            if (k == first)
                first = x[k].l;

            if (x[k].l != -1)
                x[x[k].l].r = x[k].r;
            if(x[k].r != -1)
                x[x[k].r].l = x[k].l;
            x[k].l = -1;
            x[k].r = -1;
            cnt--;
        }
        if (t == 1 && x[k].r != -1) {
            auto tar = x[x[k].r];
            auto now = x[k];
            int tarid = x[k].r;

            if (x[k].l != -1)
                x[x[k].l].r = tarid;
            if (tar.r != -1)
                x[tar.r].l = k;
            x[k].r = tar.r;
            x[k].l = tarid;
            x[tarid].r = k;
            x[tarid].l = now.l;
            if (tarid == first) {
                first = k;
            }
        }
    }
    
    if (first != -1) {
        cout << first;
    }
    while (1) {
        first = x[first].l;
        if (first == -1)
            break;
        cout << ' ' << first;
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
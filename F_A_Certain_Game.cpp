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
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<pii> rec;
pii x[MAXN];
int num[MAXN];

struct Disjoint_Set {
    int arr[MAXN], cnt[MAXN];
    stack<int> his[MAXN];
    Disjoint_Set() {
        for (int i = 1; i < MAXN * 2; i++)
            arr[i] = i, cnt[i] = 1;
    }

    int find(int i) {
        return (arr[i] == i ? i : arr[i] = find(arr[i]));
    }

    void unite(int i, int j, int id) {
        i = find(i);
        j = find(j);
        if (i == j)
            return;
        rec.pb({cnt[i], cnt[j]});
        if (cnt[j] > cnt[i])
            swap(i, j);

        his[i].push(id);
        his[j].push(id);
        arr[j] = i;
        cnt[i] += cnt[j];
    }
} dsu;

void DC(int l, int r, int i) {
    if (l == r - 1) {
        num[rec[i].F] = l;
        num[rec[i].S] = r;
        return;
    }

}

void sol() {
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> x[i].F >> x[i].S;
        dsu.unite(x[i].F, x[i].S, i);
    }

    reverse(all(rec));

    DC(1, n, 0);
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
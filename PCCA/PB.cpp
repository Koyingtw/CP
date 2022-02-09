#pragma GCC optimize("O3")
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
#define putarr(x) for(int i = 0; i < sizeof(x); i++) cout << x[i] << (" \n")[i == sizeof(x) - 1]; 
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#if !LOCAL
#define endl "\n"
#endif
const int INF = 0x3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int dsu[MAXN], cnt[MAXN];
vector<tuple<int, int, int, int>> x, y;

void init() {
	for (int i = 0; i < MAXN; i++)
		dsu[i] = i, cnt[i] = 1;
}

int find(int i) {
	return (dsu[i] == i ? i : dsu[i] = find(dsu[i]));
}

void unite(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j) return;
	if (cnt [i]  < cnt[j])
		swap(i, j);
	dsu[j] = dsu[i];
	cnt[i] += cnt[j];
}
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<0>(a) < get<0>(b);
}

void sol()
{
	cin >> n >> m;
	int ans = 0;
	for (int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		x.pb({d, c, a, b});
		y.pb({d - c, c, a, b});
		ans += c;
		// cout << d - c << endl;
	}
	
	init();
	sort(all(x));
	sort(all(y), cmp);
	
	for (int i = 0; i < m; i++) {
		auto [d, c, a, b] = y[i];
		// cout << d << endl;
		if (find(a) != find(b) || d <= 0) {
			unite(a, b);
			ans += d;
		}
	}
	cout << ans << endl;
}

signed main()
{
    Weakoying;
    int t = 1;
    //while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}
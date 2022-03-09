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
#define MAXN 500005
#define MAXM 1000005 
int n, m;
int x[MAXN];
int dsu[MAXN << 1], cnt[MAXN << 1], h[5];

void init() {
	for (int i = 1; i <= n; i++)
		dsu[i] = x[i] + n, cnt[x[i] + n]++;
	for (int i = n + 1; i <= 2 * n; i++) {
		dsu[i] = i;
	}
}

int find(int i) {
	return (dsu[i] == i ? dsu[i] : dsu[i] = find(dsu[i]));
}

int Find(int i) {
	return (dsu[i] == i ? dsu[i] : Find(dsu[i]));
}

void unite(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j) return;
	dsu[i] = j;
	cnt[j] += cnt[i];
	cnt[i] = 0;
}

void Unite(int i, int j) {
	i = Find(i);
	j = Find(j);
	if (i == j) return;
	dsu[i] = j;
	cnt[j] += cnt[i];
	cnt[i] = 0;
}

set<int> st[MAXN];
void sol1() {
	for (int i = 1; i <= n; i++)
		st[x[i]].insert(i);
	int k, a, b;
	while (m--) {
		cin >> k;
		if (k == 2) {
			cin >> a >> b;
			st[x[a]].erase(a);
			x[a] = x[b];
			st[x[a]].insert(a);
		}
		if (k == 3) {
			cin >> a >> b;
			st[x[a]].erase(a);
			x[a] = b;
			st[x[a]].insert(a);
		}
		if (k == 4) {
			cin >> a;
			cout << x[a] << " " << st[x[a]].size() << endl;
		}
		if (k == 5) {
			cin >> a;
			cout << st[a].size() << endl;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << x[i] << " ";
	cout << endl;
}

void sol2() {
	int k, a, b;
	init();
	while (m--) {
		cin >> k;
		if (k == 1) {
			cin >> a >> b;
			unite(a, b);
		}
		if (k == 4) {
			cin >> a;
			cout << find(a) - n << " " << cnt[find(a)] << endl;
		}
		if (k == 5) {
			cin >> a;
			cout << cnt[a + n] << endl;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << find(i) - n << " ";
	cout << endl;
}


void sol3() {
	int k, a, b;
	init();
	while (m--) {
		cin >> k;
		if (k == 1) {
			cin >> a >> b;
			Unite(a, b);
		}
		if (k == 2) {
			cin >> a >> b;
			Unite(a, b);
		}
		
		if (k == 4) {
			cin >> a;
			cout << Find(a) - n << " " << cnt[Find(a)] << endl;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << Find(i) - n << " ";
	cout << endl;
}

void sol()
{
	int ouo = 0;
	for (int i = 0; i < 5; i++) {
		cin >> h[i];
		ouo += h[i];
	}
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	if (!h[0]) {
		sol1();
		return;
	}
	if ((!h[1]) && (!h[2])) {
		sol2();
		return;
	}
	
	sol3();
	// init();
	// cout << 123 << endl;
	
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
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
#define MAXN 400005
#define MAXM 1000005 
int n, m;

struct Data {
	int id, h, V, mx;
} x[MAXN];

bool cmp(Data a, Data b) {
	// return a.mx < b.mx;
	if (a.h < b.h + b.V && b.h < a.h + a.V) {
		return a.id < b.id;
	}
	else return (a.h < b.h + b.V);
}

void sol()
{
	cin >> n;
	vector<pii> v;
	multiset<pii> s;
	multiset<pii> can;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		x[i].id = i;
		cin >> x[i].h >> x[i].V;
		x[i].mx = x[i].h + x[i].V;
		v.pb({x[i].mx, i});
		s.insert({x[i].h, i});
	}
	multiset<pii> q;
	sort(all(v));
	
	ans.pb(v[0].S);
	s.erase(s.find(make_pair(x[v[0].S].h, v[0].S)));
	q.insert(v[0]);
	
	while (q.size()) {
		int now = (*q.begin()).F;
		cout << now << endl;
		q.erase(q.begin());
		while (s.size() && (*s.begin()).F < now) {
			can.insert({(*s.begin()).S, (*s.begin()).F});
			s.erase(s.begin());
		}
		if (can.size()) {
			ans.pb((*can.begin()).F);
			q.insert({(*can.begin()).S, (*can.begin()).F});
			can.erase(can.begin());
			
		}
	}
	for (int it: ans)
		cout << it + 1 << " ";
	cout << endl;
	
}

signed main()
{
    Weakoying;
    int t = 1;
    while (cin >> t)
    {
    	while (t--)
        {
            sol();
        }
    }
        
    return 0;
}
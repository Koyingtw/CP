// Problem: C. Constellation
// Contest: Codeforces - Wunder Fund Round 2016 (Div. 1 + Div. 2 combined)
// URL: https://codeforces.com/contest/618/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define pii pair<int, int>
#define pdd pair<double, double>
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
#define MAXN 200005
#define MAXM 1000005 
int n, m;

struct Point {
	int F, S, id;
	
	bool operator <(Point _a) {
		if (F != _a.F)
			return F < _a.F;
		else
			return S < _a.S;
	}
} x[MAXN];


int dis(Point a, Point b) {
	return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}

int cross(pii a, pii b) {
	return abs(a.F * b.S - a.S * b.F);
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i].F >> x[i].S;
		x[i].id = i;
	}
	sort(x, x + n);
	
	int nearest = 1;
	
	// for (int i = 1; i < n; i++)
		// if (dis(x[0], x[i]) < dis(x[0], x[nearest]))
			// nearest = i;
	
	int ans = 0;
	for (int i = 2; i < n; i++) {
		if (i == nearest || i == ans)
			continue;
		pii a = {x[i].F - x[0].F, x[i].S - x[0].S};
		pii b = {x[nearest].F - x[0].F, x[nearest].S - x[0].S};
		pii c = {x[ans].F - x[0].F, x[ans].S - x[0].S};
		int area = cross(a, b);
		if (area != 0 && (area < cross(b, c) || ans == 0))
			ans = i;
	}
	cout << x[0].id + 1 << " " << x[nearest].id + 1 << " " << x[ans].id + 1<< endl;
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
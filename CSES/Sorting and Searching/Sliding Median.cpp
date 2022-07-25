// Problem: Sliding Median
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1076
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")
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
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
int x[MAXN];

void balance(multiset<int, greater<int>> &left, multiset<int, less<int>> &right) {
	while (left.size() > right.size()) {
		right.insert(*left.begin());
		left.erase(left.begin());
	}
	while (right.size() > left.size()) {
		left.insert(*right.begin());
		right.erase(right.begin());
	} 
	return;
}	

void sol() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> x[i];
	
	multiset<int, greater<int>> left;
	multiset<int, less<int>> right;
	
	for (int i = 0; i < n; i++) {
		if (!left.size() || x[i] <= *left.begin())
			left.insert(x[i]);
		else
			right.insert(x[i]);
			
		if (i >= m) {
			if (left.size() && x[i - m] <= *left.begin())
				left.erase(left.find(x[i - m]));
			else
				right.erase(right.find(x[i - m]));
		}
		balance(left, right);
		
		if (i >= m - 1)
			cout << *left.begin() << " ";
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
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
int x[3];

void sol() {
	cin >> x[0] >> x[1] >> x[2];
	if (x[1] < x[2])
		swap(x[1], x[2]);
	if (x[0] < x[1])
		swap(x[0], x[1]);
	if (x[1] < x[2])
		swap(x[1], x[2]);
	
	if (x[0] == x[2])
		cout << 3 << " ";
	else if (x[0] == x[1])
		cout << 2 << " ";
	else if (x[1] == x[2])
		cout << 2 << " ";
	else
		cout << 1 << " ";
	cout << x[0] << " ";
	if (x[1] != x[0])
		cout << x[1] << " ";
	if (x[2] != x[1])
		cout << x[2] << " ";
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
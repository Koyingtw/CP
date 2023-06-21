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

void sol() {
    priority_queue<int, vector<int>, less<int>> L;
    priority_queue<int, vector<int>, greater<int>> R;
    int n;
    while (cin >> n && n) {
        if (L.empty())
            L.push(n);
        else {
            if (n <= L.top())
                L.push(n);
            else
                R.push(n);
        }
        if (L.size() > R.size() + 1) {
            R.push(L.top());
            L.pop();
        }
        else if (R.size() > L.size()) {
            L.push(R.top());
            R.pop();
        }

        if (L.size() == R.size())
            cout << (L.top() + R.top()) / 2 << '\n';
        else
            cout << L.top() << '\n';
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
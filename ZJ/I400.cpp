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
#define MAXN 105
#define MAXM 1000005 
int n, m;
bool odd[MAXN];
string x, s[MAXN];

void sol() {
	cin >> n >> m;
	for (int i = n - 1; i >= 0; i--) {
		cin >> s[i];
		int cnt = 0;
		for (char c: s[i])
			cnt += (c - '0');
		odd[i] = cnt % 2;
	}
	cin >> x;
	deque<char> dq;
	for (char c: x)
		dq.push_back(c);
		
	for (int i = 0; i < n; i++) {
		deque<char> tmp;
		for (int j = m - 1; j >= 0; j--) {
			if (s[i][j] - '0') {
				tmp.push_back(dq.back());
				dq.pop_back();
			}
			else {
				tmp.push_front(dq.back());
				dq.pop_back();
			}
		}
		if (odd[i])
			for (int j = 0; j < m / 2; j++)
				swap(tmp[j], tmp[j + (m + 1) / 2]);
		dq = tmp;
	}
	for (int i = 0; i < m; i++)
		cout << dq[i];
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
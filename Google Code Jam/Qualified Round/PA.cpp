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
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int Case = 0;

void sol() {
	Case++;
	cin >> n >> m;
	cout << "Case #" << Case << ":\n";
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * m + 1; j++) {
			if (i % 2 == 0) {
				if (i < 2 && j < 2) {
					cout << ".";
				}
				else if (j % 2) {
					cout << "-";
				}
				else {
					cout << "+";
				}
			}
			else {
				if (i < 2 && j < 2) {
					cout << ".";
				}
				else if (j % 2) {
					cout << ".";
				}
				else {
					cout << "|";
				}
			}
		}	
		cout << endl;
	}
}

signed main() {
    Weakoying;
    int t = 1;
    while (cin >> t)
	{
    	while (t--) {
            sol();
        }
    }
        
    return 0;
}
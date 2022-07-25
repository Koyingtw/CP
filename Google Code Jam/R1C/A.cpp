// Problem: Letter Blocks
// Contest: Google Coding Competitions - Round 1C 2022 - Code Jam 2022
// URL: https://codingcompetitions.withgoogle.com/codejam/round/0000000000877b42/0000000000afe6a1
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define MAXN 105
#define MAXM 1000005 
int n, m;
string s[MAXN];

bool check(string a) {
	bool yes = 1;
	map<char, int> mp;
	for (int i = 0; i < a.size(); i++) {
		if (i == 0 || a[i] != a[i - 1]) {
			mp[a[i]]++;
			yes &= mp[a[i]] < 2;
		}
	}
	return yes;
}

bitset<MAXN> vis;


int Case = 0;

void sol() {
	cin >> n;
	cout << "Case #" << ++Case << ": ";
	bool yes = 1;
	set<string> st[30], bk[30];
	multiset<string> both[30];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		yes &= check(s[i]);
		if (s[i][0] == s[i].back()) {
			both[s[i][0] - 'A'].insert(s[i]);
		}
		else {
			yes &= !st[s[i][0] - 'A'].size();
			st[s[i][0] - 'A'].insert(s[i]);
			yes &= !bk[s[i].back() - 'A'].size();
			bk[s[i].back() - 'A'].insert(s[i]);
		}
	}
	
	if (!yes) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
		
	string ans;
	for (int i = 0; i < 26; i++) {
		string tmp = "";
		int now = i;
		int cnt = 0;
		if (st[now].size() + both[now].size() == 0)
			continue;
		bitset<26> vis;
		while (cnt < n) {
			if (vis[now])
				break;
			vis[now] = true;
			for (string it: both[now]) {
				tmp += it;
				cnt++;
			}
			if (st[now].size()) {
				tmp += *st[now].begin();
				cnt++;
				now = tmp.back()- 'A';
			}
			else {
				for (int k = 0; k < 26; k++) {
					if (vis[k] == 0 && !bk[k].size()) {
						now = k;
						break;
					}
				}
			}
		}
		// cout << tmp << endl;
		assert(cnt <= n);
		if (cnt == n && check(tmp)) {
			cout << tmp << endl;
			return;
		}
	}
	cout << "IMPOSSIBLE" << endl;
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
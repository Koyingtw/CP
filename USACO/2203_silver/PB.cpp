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
string n, m;

struct Node {
	int l, r;
	bitset<20> st;
} seg[MAXN << 4];

void update(int id, int pos, int val) {
	int l = seg[id].l, r = seg[id].r;
	if (l > pos || r < pos) {
		return;
	}
	if (l == r) {
		seg[id].st[val] = true;
		return;
	}
	update(id * 2, pos, val);
	update(id * 2 + 1, pos, val);
	for (int i = 0; i < 20; i++)
		seg[id].st[i] = (seg[id * 2].st[i] | seg[id * 2 + 1].st[i]);
	return;
}

Node query(int id, int ql, int qr) {
	int l = seg[id].l, r = seg[id].r;
	Node res;
	if (r < ql || l > qr) {
		return res;
	}
	Node q1, q2;
	q1 = query(id * 2, ql, qr);
	q2 = query(id * 2 + 1, ql, qr);
	for (int i = 0; i < 20; i++) {
		res.st[i] = q1.st[i] | q2.st[i];
	}
	return res;
}

int now[20];

void sol() {
	cin >> n >> m;
	vector<int> pos[20];
	for (int i = 0; i < m.size(); i++) {
		pos[m[i] - 'a'].pb(i);
	}
	for (int i = 0; i < 20; i++)
		now[i] = -1;
	set<int> cant[20];
	for (int i = 0; i < n.size(); i++) {
		int awa = n[i] - 'a';
		if (now[awa] + 1 < pos[awa].size()) {
			now[awa]++;
			for (int j = 0; j < 20; j++) {
				if (now[j] > -1 && pos[j][now[j]] > pos[awa][now[awa]]) {
					cant[awa].insert(j);
					// cout << pos[now[j]] << " " << pos[now[awa]] << endl;
				}
			}
		}
		else {
			cant[awa].insert(awa);
		}
	}
	for (int i = 0; i < 20; i++)
		if (now[i] != pos[i].size() - 1)
			cant[i].insert(i);
	int t;
	cin >> t;
	while (t--) {
		string q;
		cin >> q;
		bool yes = 1;
		for (int i = 0; i < q.size();i++) {
			for (int j = 0; j < q.size(); j++) {
				yes &= !(cant[q[i] - 'a'].count(q[j] - 'a'));
			}
		}
		if (yes)
			cout << "Y";
		else
			cout << "N";
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
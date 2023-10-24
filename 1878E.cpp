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

// https://judge.yosupo.jp/problem/staticrmq 214 ms

template<typename T, int RANGE>
struct Sparse_Table {
	struct Node {
		T val;

		Node(): val(INF) {}

		Node operator +(const Node &rhs) {
			Node ret;
			ret.val = val & rhs.val;
			return ret; // 視情況修改
		}
	};
	vector<vector<Node>> arr;

	Sparse_Table() {
		arr.resize(__lg(RANGE) + 1, vector<Node>(RANGE, Node()));
	}

	void build(vector<T> &v) {
		for (int i = 1; i <= n; i++) {
			arr[0][i].val = v[i];
		}
		for (int i = 1; i <= __lg(n); i++)
			for (int j = 1; j + (1 << (i - 1)) <= n; j++)
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j + (1 << (i - 1))];
	}

	Node query(int ql, int qr) {
		int lg = __lg(qr - ql + 1);
		return arr[lg][ql] + arr[lg][qr - (1 << lg) + 1];
	}
};

Sparse_Table<int, 200005> ST;
vector<int> x(MAXN);

void sol() {
    cin >> n;
    x.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    ST.build(x);

    cin >> m;
    int L, k;
    while (m--) {
        cin >> L >> k;
        int l = L, r = n;
        bool legal = false;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (ST.query(L, mid).val >= k)
                l = mid, legal = true;
            else
                r = mid - 1;
        }
        cout << (ST.query(L, l).val >= k ? l : -1) << ' ';
    }
    cout << endl;
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
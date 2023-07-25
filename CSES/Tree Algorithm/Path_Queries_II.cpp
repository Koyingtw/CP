#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// #define int long long
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
#define cmax(a, b) if (b > a) a = b
#define cmin(a, b) if (b < a) a = b
#define put(x) cout << x << endl;
#define DB(x) cerr << #x << " " << x << endl
#define all(v) v.begin(), v.end()
#define stop system("pause");
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x &(-x)
#define SZ(v) ((int)v.size())
#if !LOCAL
#define endl "\n"
// #pragma GCC optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;
vector<int> x(MAXN), y(MAXN);
vector<vector<int>> G(MAXN, vector<int>());

template<typename T, int RANGE>
struct Segment_Tree {
	struct Node {
		T val;

		Node (): val(0) {} // mx: -INF, mn: INF, sum: 0, gcd: 1, lcm: 1

		Node operator +(const Node &rhs) {
			Node ret;
			ret.val = max(val, rhs.val); // 對應不同操作修改

			return ret;
		}

		void update(int _val) {
			val = _val;
		}
	};

	vector<Node> arr;

	Segment_Tree() {
		arr.resize(RANGE << 2);
	}

	void build(vector<int> &v, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].val = v[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}

	void update(int pos, int val, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].update(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, val, i << 1, l, mid);
		else update(pos, val, i << 1 | 1, mid + 1, r);
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}

	Node query(int ql, int qr, int i = 1, int l = 1, int r = n) {
		if (l > qr || r < ql)
			return Node();
		if (ql <= l && r <= qr)
			return arr[i];
		int mid = (l + r) >> 1;
		return query(ql, qr, i << 1, l, mid) + query(ql, qr, i << 1 | 1, mid + 1, r);
	}
};

Segment_Tree<int, MAXN> seg;

struct HLD {
    struct Info {
        int sub, mxsub, dep, fa, root, id;
    } arr[MAXN];

    int index = 0;

    void find_son(int i, int fa) {
        pii mx(0, i);
        arr[i].sub = 1;
        for (auto it: G[i]) if (it != fa) {
            arr[it].dep = arr[i].dep + 1;
            arr[it].fa = i;
            find_son(it, i);
            if (arr[it].sub > mx.F)
                mx = pii(arr[it].sub, it);
            arr[i].sub += arr[it].sub;    
        }
        arr[i].mxsub = mx.S;
    }

    void build(int i, int root) {
        arr[i].root = root;
        arr[i].id = ++index;
        y[arr[i].id] = x[i];
        
        if (arr[i].mxsub != i) {
            build(arr[i].mxsub, root);
        }
        
        for (auto it: G[i]) if (it != arr[i].fa && it != arr[i].mxsub) {
            build(it, it);
        }
    }

    int jump(vector<pii> &ret, int a, int b) { // from a to b (dep(a) > dep(b))
        int mx = 0;

        while (arr[a].root != arr[b].root) {
            if (arr[arr[a].root].dep < arr[arr[b].root].dep) {
                swap(a, b);
            }
            int qq = seg.query(arr[arr[a].root].id, arr[a].id).val;
            a = arr[arr[a].root].fa;
            cmax(mx, qq);
        }

        if (arr[a].dep < arr[b].dep) {
            swap(a, b);
        }

        int qq = seg.query(arr[b].id, arr[a].id).val;
        cmax(mx, qq);
        return mx;
    }
} HLD;


void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }

    HLD.find_son(1, 1);
    HLD.build(1, 1);
    seg.build(y);


    int op, a, b;
    vector<pii> v;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b;
            seg.update(HLD.arr[a].id, b);
        }
        else if (op == 2) {
            cin >> a >> b;
            cout << HLD.jump(v, a, b) << ' ';
        }
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
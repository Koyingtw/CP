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

struct Line {
    int a, b;

    int operator() (int x) {
        return a * x + b;
    }

    Line(): a(-INF), b(-INF) {};
    Line(int _a, int _b): a(_a), b(_b) {}
};

struct Lee_Chao {
    struct Node {
        Line L;
        int rhs, lhs;
        Node(): L(Line()), rhs(-1), lhs(-1) {}
        Node(int l, int r): L(Line(l, r)), rhs(-1), lhs(-1) {}
    };

    vector<Node> arr;
    int freespace = 2;

    int newNode() {
        return freespace++;
    }

    void checkNode(int i, char pos) {
        if (pos == 'l') {
            if (arr[i].lhs == -1)
                arr[i].lhs = newNode();
        }
        else {
            if (arr[i].rhs == -1)
                arr[i].rhs = newNode();
        }

    }

    void update(int i, int l, int r, Line li) {
        // cout << "update: " << l << ' ' << r << endl;
        if (l == r) {
            if (li(l) > arr[i].L(l)) {
                arr[i].L = li;
            }
            return;
        }

        int mid = (l + r) / 2;

        bool swp = false;

        if (arr[i].L.a > li.a) {
            swap(arr[i].L, li);
            swp ^= true;
        }

        if (arr[i].L(mid) >= li(mid)) {
            checkNode(i, 'r');
            update(arr[i].rhs, mid + 1, r, li);
        }
        else {
            swp ^= true;
            swap(arr[i].L, li);
            checkNode(i, 'l');
            update(arr[i].lhs, l, mid, li);
        }
    }

    int query(int i, int l, int r, int x) {
        if (l == r)
            return arr[i].L(x);
        int mid = (l + r) / 2;
        if (x <= mid) {
            if (arr[i].lhs != -1)
                return min(arr[i].L(x), query(arr[i].lhs, l, mid, x));
            else
                return arr[i].L(x);
        }
        else {
            if (arr[i].rhs != -1)
                return min(arr[i].L(x), query(arr[i].rhs, mid + 1, r, x));
            else
                return arr[i].L(x);
        }

    }
} seg;

void sol() {
    cin >> n >> m;
    seg.arr.resize(MAXN << 2);
    seg.update(1, 1, 1e9, Line(INF, INF));
    int a, b;
    while (n--) {
        cin >> a >> b;
        Line li(a, b);
        seg.update(1, 1, 1e9, li);
    }
    while (m--) {
        cin >> a;
        cout << seg.query(1, 1, 1e9, a) << endl;
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
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int> 
#define all(v) v.begin(), v.end()
#define lowbit(x) (x & (-x))
#define MEM(x, n) memset(x, n, sizeof(x))
#define Koying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F first
#define S second

#if !LOCAL
#define endl '\n'
#pragma GCC optimize("Ofast, unroll-all-loops")
#endif 
using namespace std;

const int INF = 0x3f3f3f3f;

#define MAXN 200005

signed n;
struct Line {
    signed a, b;
    signed live, dead;

    int operator() (int x) {
        return a * x + b;
    }

    Line(): a(-INF), b(-INF), live(-1), dead(INF) {};
    Line(int _a, int _b): a(_a), b(_b) {}
    Line(int _a, int _b, int _live, int _dead): a(_a), b(_b), live(_live), dead(_dead) {}
};

struct Data {
    signed type, a, b;
    int ans;
    Line L;
} input[MAXN];

vector<vector<pair<int, Line>>> upd_stk; // first: whitch node, second: change which line (update from what)

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

    void update(int i, int l, int r, Line &li) {
        // cout << "update: " << l << ' ' << r << endl;
        if (l == r) {
            if (li(l) > arr[i].L(l)) {
                upd_stk.back().emplace_back(i, arr[i].L);
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
            if (swp)
                upd_stk.back().emplace_back(i, li);
            checkNode(i, 'r');
            update(arr[i].rhs, mid + 1, r, li);
        }
        else {
            swp ^= true;
            swap(arr[i].L, li);
            if (swp)
                upd_stk.back().emplace_back(i, li);
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
                return max(arr[i].L(x), query(arr[i].lhs, l, mid, x));
            else
                return arr[i].L(x);
        }
        else {
            if (arr[i].rhs != -1)
                return max(arr[i].L(x), query(arr[i].rhs, mid + 1, r, x));
            else
                return arr[i].L(x);
        }

    }
} lee_chao_seg;

struct Time_SegTree {
    vector<Line> arr[MAXN << 2];

    void insert(signed i, signed l, signed r, signed ql, signed qr, Line &li) {
        // cout << "insert:" << l << ' ' << r << ' ' << ql << ' ' << qr << endl;
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            arr[i].emplace_back(li);
            return;
        }

        int mid = (l + r) / 2;

        insert(i * 2, l, mid, ql, qr, li);
        insert(i * 2 + 1, mid + 1, r, ql, qr, li);
    }

    void undo() {
        while (upd_stk.back().size()) {
            auto top = upd_stk.back().back();
            upd_stk.back().pop_back();
            lee_chao_seg.arr[top.F].L = top.S;
            // cout << top.F << ' ' << top.S.a << ' ' << top.S.b << endl;
        }
        upd_stk.pop_back();
    }

    void traverse(signed i, signed l, signed r) {
        // cout << "traverse" << ' ' << l << ' ' << r << endl;
        int cnt = 0;

        for (auto &it: arr[i]) {
            // cout << l << ' ' << r << ' ' << it.a << ' ' << it.b << ' ' << it.live << ' ' << it.dead << endl;
            upd_stk.emplace_back(vector<pair<int, Line>>());
            lee_chao_seg.update(1, 1, (int)1e9, it);
            cnt++;
        }


        if (l == r) {
            if (input[l].type == 0) {
                input[l].ans = lee_chao_seg.query(1, 1, (int)1e9, input[l].a);
            }
        }
        else {
            int mid = (l + r) / 2;
            traverse(i * 2, l, mid);
            traverse(i * 2 + 1, mid + 1, r);
        }

        while (cnt--)
            undo();
    }
} time_seg;

inline void init() {
    upd_stk.emplace_back(vector<pair<int, Line>> ());
    cin >> n;
    lee_chao_seg.arr.resize(1000000);

    signed lineID = 0;
    signed id[MAXN];

    for (signed i = 1; i <= n; i++) {
        cin >> input[i].type;

        if (input[i].type == 0) {
            cin >> input[i].a;
        }
        else if (input[i].type == 1) {
            cin >> input[i].a;
            cin >> input[i].b;
            input[i].L = Line(input[i].a, input[i].b, i, n);
            id[lineID++] = i;
        }
        else {
            cin >> input[i].a;
            input[i].a = id[input[i].a];
            input[input[i].a].L.dead = i;
        }
    }

    for (signed i = 1; i <= n; i++) {
        if (input[i].type == 1) {
            time_seg.insert(1, 1, n, input[i].L.live, input[i].L.dead, input[i].L);
        }
        
    }
    // cout << "OWO" << endl;
}

void sol() {
    time_seg.traverse(1, 1, n);

    for (signed i = 1; i <= n; i++) {
        if (input[i].type == 0) {
            if (input[i].ans <= -INF)
                cout << "double is good at problem setting" << endl;
            else
                cout << input[i].ans << endl;
        }
    }
}

signed main() {
    Koying;
    init(); // input
    sol();
}
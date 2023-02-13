#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define endl '\n'
#define _ << ' ' <<

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
// #pragma GCC optimize("inline")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int maxn = 2e5 + 5;
const int maxc = 1e6 + 5;
const ll INF = 2e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;

const int mod = 10007;


int q, qN = 0;
vector<ll> qry_elem;
vector<ll> ask;
vector<ll> ans;


struct line {
    ll m = 0, k = -LINF;
    ll operator()(ll x) {
        return m * x + k;
    }
};
line st[maxn*4];
int xid(ll x) {
    return lower_bound(qry_elem.begin(), qry_elem.end(), x) - qry_elem.begin();
}

vector<vector<pair<int, line> > > stk;  // int: idx on st

void output_stk() {
    for (auto& i : stk) {
        for (auto& j : i) {
            cout << j.first << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void insert(int l, int r, int idx, line L) {
    if (l == r) {
        if (L(qry_elem[l]) > st[idx](qry_elem[l])) {
            // need undo
            // cout << "COVER:" _ idx _ st[idx].m _ st[idx].k << endl;
            stk.back().emplace_back(make_pair(idx, st[idx]));
            // output_stk();
            st[idx] = L;
        }
        return;
    }
    int mid = (l+r) >> 1, cl = idx<<1, cr = idx<<1|1;
    int swapped = false;
    if (st[idx].m > L.m) {
        swap(st[idx], L);
        swapped = true;
    }

    if (st[idx](qry_elem[mid]) < L(qry_elem[mid])) {
        swap(st[idx], L);
        swapped ^= true;
        if (swapped) stk.back().emplace_back(make_pair(idx, L));
        insert(l, mid, cl, L);
    }
    else {
        if (swapped) stk.back().emplace_back(make_pair(idx, L));
        insert(mid+1, r, cr, L);
    }
}
ll query(int qid, int l, int r, int idx) {
    // if (qid == 2) {
    //     cout << "QRY: " << st[idx](qry_elem[qid]) << endl;
    // }
    if (l == r) return st[idx](qry_elem[qid]);
    int mid = (l+r) >> 1, cl = idx<<1, cr = idx<<1|1;
    if (qid <= mid) return max(st[idx](qry_elem[qid]), query(qid, l, mid, cl));
    else return max(st[idx](qry_elem[qid]), query(qid, mid+1, r, cr));
}




vector<line> tr[maxn*4];
void undo() {
    while (!stk.back().empty()) {
        pair<int, line> op = stk.back().back();
        stk.back().pop_back();
        // cout << "UNDO: " << op.first << ": " << op.second.m _ op.second.k << endl;
        st[op.first] = op.second;
    }
    stk.pop_back();
}
void insert_event(int ql, int qr, line e, int l, int r, int idx) {
    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        // cout << l << ' ' << r << " -> " << e.m _ e.k << endl;
        tr[idx].emplace_back(e);
        return;
    }
    int mid = (l+r) >> 1, cl = idx<<1, cr = idx<<1|1;
    insert_event(ql, qr, e, l, mid, cl);
    insert_event(ql, qr, e, mid+1, r, cr);
}
void traverse(int l, int r, int idx) {
    int cnt = 0;
    for (auto& e : tr[idx]) {
        // cout << "EVENT:" _ l _ r << ": " << e.m _ e.k << endl;
        stk.emplace_back(vector<pair<int, line> >());
        insert(0, qN-1, 1, e);
        // cout << "EVENT FINISH\n";
        cnt++;
    }
    if (l == r) {
        // record ans;
        if (ask[l] != INF) {
            // cout << ask[l] << ' ' << xid(ask[l]) << ", t =" _ l << endl;
            ans[l] = query(xid(ask[l]), 0, qN-1, 1);
        }
    } else {
        int mid = (l+r) >> 1, cl = idx<<1, cr = idx<<1|1;
        traverse(l, mid, cl);
        traverse(mid+1, r, cr);
    }
    while (cnt--) {
        undo();
    }
}



vector<int> live, dead;
vector<line> Lines;

void init() {
    cin >> q;
    qry_elem.clear();
    ask.assign(q, INF);
    live.assign(q, -1);
    dead.assign(q, q-1);
    ans.assign(q, 0);

    for (int t = 0; t < q; t++) {
        int type; cin >> type;
        if (type == 0) {
            ll x; cin >> x;
            qry_elem.emplace_back(x);
            ask[t] = x;
        }
        else if (type == 1) {
            ll m, k; cin >> m >> k;
            Lines.emplace_back(line{m, k});
            live[(int)Lines.size()-1] = t;
        }
        else {
            int k; cin >> k;
            dead[k] = t;
        }
    }

    sort(qry_elem.begin(), qry_elem.end());
    qry_elem.resize(unique(qry_elem.begin(), qry_elem.end()) - qry_elem.begin());
    qN = (int)qry_elem.size();

    for (int i = 0; i < (int)Lines.size(); i++) {
        if (live[i] == -1) continue;
        // cout << "LINE: " << Lines[i].m _ Lines[i].k _ ":" _ live[i] _ dead[i] << endl;
        insert_event(live[i], dead[i], Lines[i], 0, q-1, 1);
    }
}

void solve() {

    // "double is good at problem setting\n"

    if (qN == 0) return;

    traverse(0, q-1, 1);

    for (int i = 0; i < q; i++) {
        if (ask[i] == INF) continue;
        if (ans[i] == -LINF) cout << "double is good at problem setting\n";
        else cout << ans[i] << endl;
    }

}

int main() {
    fastio

int T = 1;
// cin >> T;
while (T--) {
    init();
    solve();
}

    return 0;
}
message.txt
6 KB
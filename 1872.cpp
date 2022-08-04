#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define Weakoying ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long
#define ll __int128
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
const int P = 1000000007;

using namespace std;
/******************************************************************************/
#define MAXN 100005
#define MAXM 1000005 
int n, m;
int x[MAXN];

bitset<MAXM> not_prime;
vector<int> prime;

void make_prime() {
    // int sq = sqrt(MAXN);
    for (int i = 2; i < MAXM; i++) {
        if (!not_prime[i]) {
            prime.pb(i);
            for (int j = i * i; j < MAXM; j += i) {
                not_prime[j] = 1;
            }
        }
    }
    // cout << prime.back() << endl;
}

struct Node {
    int l, r;
    map<int, int> mp;

    Node operator +(Node _a) {
        Node res;
        res.l = 0, res.r = 0;
        res.mp.clear();
        for (auto& [a, b] : mp) {
            cmax(res.mp[a], b);
        }
        for (auto& [a, b] : _a.mp) {
            cmax(res.mp[a], b);
        }
        return res;
    }
};

struct seg_tree {
    Node seg[MAXN << 2];
    Node tmp;

    void build(int i, int l, int r) {
        seg[i].l = l;
        seg[i].r = r;
        if (l == r) {
            int tmp = x[l];
            seg[i].mp.clear();
            for (int j = prime.size() - 1; j >= 0 && tmp > 1; j--) {
                while (tmp % prime[j] == 0) {
                    tmp /= prime[j];
                    seg[i].mp[prime[j]]++;
                }
            }
            return;
        }
        int mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        seg[i].mp = (seg[i << 1] + seg[i << 1 | 1]).mp;
    }

    Node query(int i, int ql, int qr) {
        int l = seg[i].l, r = seg[i].r;
        if (l > qr || r < ql) 
            return tmp;
        if (ql <= l && r <= qr)
            return seg[i];
        return query(i << 1, ql, qr) + query(i << 1 | 1, ql, qr);
    }
} seg;

int fpow(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int res = fpow(a, b >> 1);
    res = (res * res) % P;
    if (b & 1) res = (res * a) % P;
    return res;
}

void sol() {
    make_prime();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    seg.build(1, 1, n);
    seg.tmp.mp.clear();

    int l, r;
    while (m--) {
        cin >> l >> r;
        auto mp = seg.query(1, l, r).mp;

        int ans = 1;

        for (auto [a, b]: mp) {
            ans *= fpow(a, b);
            ans %= P;
        }
        cout << ans << endl;
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

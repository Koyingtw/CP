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
#pragma optimize("Ofast", "unroll-all-loops")
#endif
const int INF = 0x3f3f3f3f3f3f3f3f;
const int P = 1e9+7;

using namespace std;
/******************************************************************************/
#define MAXN 200005
#define MAXM 1000005 
int n, m;


struct Treap {
    int key, pri, size;
    Treap *l, *r;
    Treap(int k) : key(k), pri(rand()), size(1), l(NULL), r(NULL) {}

    void pull() {
        size = 1;
        if (l != nullptr) size += l->size;
        if (r != nullptr) size += r->size;
    }
};

Treap *root;

int size(Treap *a) {
    return a == nullptr ? 0 : a->size;
}

Treap *merge(Treap *a, Treap *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->pri < b->pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split(Treap *p, Treap *&a, Treap *&b, int k) {
    if (!p) {
        a = p;
        b = p;
        return;
    }
    if (p->key < k) {
        a = p;
        split(p->r, p->r, b, k);
        a->pull();
    } else {
        b = p;
        split(p->l, a, p->l, k);
        b->pull();
    }
}

void split2(Treap *p, Treap *&a, Treap *&b, int k) {
    if (!p) {
        a = p;
        b = p;
        return;
    }
    if (size(p->l) < k) {
        a = p;
        split2(p->r, a->r, b, k - size(p->l) - 1);
        a->pull();
    }
    else {
        b = p;
        split2(p->l, a, b->l, k);
        b->pull();
    }
}

void insert(Treap *&root, int k) {
    if (!root) {
        root = new Treap(k);
        return;
    }
    Treap *a = NULL, *b = NULL;
    split(root, a, b, k);
    root = merge(merge(a, new Treap(k)), b);
}

void erase(Treap *&root, int k) {
    Treap *a, *b, *c;
    split(root, a, b, k);
    split(b, b, c, k + 1);
    delete b;
    root = merge(a, c);
}

int rankof(Treap *&root, int k) {
    Treap *a, *b;
    split(root, a, b, k);
    int ret = size(a);
    root = merge(a, b);
    return ret;
}

int kthof(Treap *&root, int k) {
    Treap *a, *b, *c;
    split2(root, a, b, k);
    split2(b, b, c, k + 1);
    int ret = b->key;
    merge(merge(a, b), c);
    return ret;
}


void sol() {
    insert(root, 10);
    insert(root, 20);
    cout << kthof(root, 1) << endl;
    erase(root, 10);
    cout << size(root) << endl;
    erase(root, 20);
    cout << size(root) << endl;
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
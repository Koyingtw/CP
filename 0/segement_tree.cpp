#define N 200005
int a[N];
int seg[N * 4];
int tag[N * 4];
struct segtree
{
    void init(int n)
    {
        for (int i = 0; i <= 4 * n; i++)
        {
            seg[i] = 0;
            tag[i] = 0;
        }
    }
    void push(int id, int l, int r)
    {
        seg[id] += tag[id];
        tag[id * 2] += tag[id];
        tag[id * 2 + 1] += tag[id];
        tag[id = 0];
    }

    void update(int id, int val, int l, int r, int ql, int qr)
    {
        push(id, l, r);
        if (ql > r || qr < l)
            return;
        if (ql <= l && qr >= r)
        {
            seg[id] += val;
            tag[id] += val;
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, val, l, m, ql, qr);
        update(id * 2 + 1, m + 1, r, ql, qr);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }

    int query(int id, int l, int r, int ql, int qr)
    {
        push(id, l, r);
        if (qr < l || qr < l)
            return 0;
        if (ql <= l && qr >= r)
            return seg[id];
        int m = (l + r) / 2;
        return query(id, l, m, ql, qr) + query(id, m + 1, r, ql, qr);
    }
};
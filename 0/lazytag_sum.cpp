struct Node
{
    int l, r, tag, sum;
    void update(int val) { sum += (r - l + 1) * val, tag += val; }
};

int a[MAXN];
Node seg[MAXN * 4];

void build(int id, int l, int r)
{
    seg[id].l = l, seg[id].r = r;
    if (seg[id].l == seg[id].r)
    {
        seg[id].sum = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(id * 2, l, m), build(id * 2 + 1, m + 1, r);
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}
void pull(int id)
{
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}
void push(int id)
{
    int tag = seg[id].tag;
    seg[id * 2].update(tag), seg[id * 2 + 1].update(tag);
    seg[id].tag = 0;
}
int query(int id, int ql, int qr)
{
    int l = seg[id].l, r = seg[id].r;
    if (ql <= l && r <= qr)
        return seg[id].sum;
    push(id);
    int m = (l + r) / 2, ans = 0;
    if (ql <= m)
        ans += query(id * 2, ql, qr);
    if (qr > m)
        ans += query(id * 2 + 1, ql, qr);
    return ans;
}
void update(int id, int ql, int qr, int val)
{
    int l = seg[id].l, r = seg[id].r;
    if (ql <= l && r <= qr)
        seg[id].update(val);
    else
    {
        push(id);
        int m = (l + r) / 2;
        if (ql <= m)
            update(id * 2, ql, qr, val);
        if (qr > m)
            update(id * 2 + 1, ql, qr, val);
        pull(id);
    }
}
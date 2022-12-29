struct Segment_Tree {
    struct Node {
        int mx, tag;

        void update(int val) {
            tag += val;
            mx += val;
        }

        Node operator +(Node _a) {
            cmax(_a.mx, mx);
            return _a;
        }

        Node() {
            mx = 0;
            tag = 0;
        }
    };
    Node arr[MAXN << 2];

    void push(int i, int l, int r) {
        int tag = arr[i].tag;
        arr[i].tag = 0;
        if (l == r)
            return;

        arr[i * 2].update(tag);
        arr[i * 2 + 1].update(tag);
    }

    void build(int i, int l, int r) {
        arr[i] = Node();
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
    }

    void update(int i, int l, int r, int ql, int qr, int val) { 
        if (ql > r || qr < l)
            return;
        if (ql <= l && r <= qr) {
            arr[i].update(val);
            return;
        }

        int mid = (l + r) / 2;
        push(i, l, r);
        update(i * 2, l, mid, ql, qr, val);
        update(i * 2 + 1, mid + 1, r, ql, qr, val);
        arr[i].mx = (arr[i * 2] + arr[i * 2 + 1]).mx;
    }

    Node query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (ql > r || qr < l) 
            return Node();
        if (ql <= l && r <= qr)
            return arr[i];
        
        int mid = (l + r) / 2;
        push(i, l, r);
        return query(i * 2, l, mid, ql, qr) + query(i * 2 + 1, mid + 1, r, ql, qr);
    }
} seg;
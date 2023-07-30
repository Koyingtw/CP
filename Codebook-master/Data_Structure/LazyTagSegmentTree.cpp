struct Node {
    int sum, tag;
    Node(): sum(0), tag(0) {}

    void update(int val, int l, int r) {
        sum += (val) * (r - l + 1);
        tag += val;
    }
    Node operator +(const Node rhs) {
        Node ret;
        ret.sum = sum + rhs.sum;
        return ret;
    }
    void operator *=(const Node rhs) {
        sum = rhs.sum;
    }
};

template<typename T>
struct Segment_Tree {
    vector<T> arr;

    void init() {
        arr.resize(MAXN << 2, Node()); 
    }

    void push(int i, int l, int r) {
        if (l == r || arr[i].tag == 0)
            return;
        int mid = (l + r) / 2;
        arr[i * 2].update(arr[i].tag, l, mid);
        arr[i * 2 + 1].update(arr[i].tag, mid + 1, r);
        arr[i].tag = 0;
    }

    void update(int ql, int qr, int val, int i = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr) {
            arr[i].update(val, l, r);
            return;
        }
        if (l > qr || r < ql)
            return;
        int mid = (l + r) / 2;
        push(i, l, r);
        update(ql, qr, val, i * 2, l, mid);
        update(ql, qr, val, i * 2 + 1, mid + 1, r);
        arr[i].sum = (arr[i * 2] + arr[i * 2 + 1]).sum;
    }

    T query(int ql, int qr, int i = 1, int l = 1, int r = n) {
        if (ql <= l && r <= qr)
            return arr[i];
        if (l > qr || r < ql)
            return T();
        push(i, l, r);
        int mid = (l + r) / 2;
        auto q1 = query(ql, qr, i * 2, l, mid);
        auto q2 = query(ql, qr, i * 2 + 1, mid + 1, r);
        return q1 + q2;
    }
};
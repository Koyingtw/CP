template<typename T>
struct LiChao_SegTree {
    T arr[MAXM << 2];

    void init() {
        for (int i = 0; i < (MAXM << 2); i++) {
            arr[i] = {m, 0};
        }
    }

    void insert(int i, int l, int r, T x) {
        if (l == r) {
            if (x(l) < arr[i](l)) {
                arr[i] = x;
            }
            return;
        }

        if (arr[i].a > x.a) {
            swap(arr[i], x);
        }

        int mid = (l + r) / 2;

        if (x(mid) > arr[i](mid)) {
            insert(i * 2, l, mid, x);
        }
        else {
            swap(arr[i], x);
            insert(i * 2 + 1, mid + 1, r, x);
        }
    }

    int query(int i, int l, int r, int pos) {
        if (l == r)
            return arr[i](pos);
        int mid = (l + r) / 2;
        int res;
        if (pos <= mid) {
            res = query(i * 2, l, mid, pos);
        }
        else {
            res = query(i * 2 + 1, mid + 1, r, pos);
        }
        return min(res, arr[i](pos));
    }
};
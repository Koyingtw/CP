//  https://cses.fi/problemset/task/1137/

struct HLD {
    struct Info {
        int sub, mxsub, dep, fa, root, id;
    } arr[MAXN];

    int index = 0;

    void find_son(int i, int fa) {
        pii mx(0, i);
        arr[i].sub = 1;
        for (auto it: G[i]) if (it != fa) {
            arr[it].dep = arr[i].dep + 1;
            arr[it].fa = i;
            find_son(it, i);
            cmax(mx, pii(arr[it].sub, it));
            arr[i].sub += arr[it].sub;    
        }
        arr[i].mxsub = mx.S;
    }

    void build(int i, int root) {
        arr[i].root = root;
        arr[i].id = ++index;
        y[arr[i].id] = x[i];
        
        if (arr[i].mxsub != i) {
            build(arr[i].mxsub, root);
            y[arr[i].id] += y[arr[arr[i].mxsub].id];
        }
        
        for (auto it: G[i]) if (it != arr[i].fa && it != arr[i].mxsub) {
            build(it, it);
            y[arr[i].id] += y[arr[it].id];
        }
    }

    void jump(int a, int b) { // from a to b (dep(a) > dep(b))
        while (arr[a].root != arr[b].root) {
            if (arr[arr[a].root].dep < arr[arr[b].root].dep)
            a = arr[arr[a].root].fa;
        }

        if (arr[a].dep < arr[b].dep)
            swap(a, b);

        return mx;
    }
} HLD;
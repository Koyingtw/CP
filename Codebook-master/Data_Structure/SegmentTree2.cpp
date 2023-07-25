// https://judge.yosupo.jp/problem/point_add_range_sum 331 ms
// https://judge.yosupo.jp/problem/staticrmq 359 ms
template<typename T, int RANGE>
struct Segment_Tree {
	struct Node {
		T val;

		Node (): val(0) {} // mx: -INF, mn: INF, sum: 0, gcd: 1, lcm: 1

		Node operator +(const Node &rhs) {
			Node ret;
			ret.val = val + rhs.val; // 對應不同操作修改

			return ret;
		}

		void update(int _val) {
			val += _val;
		}
	};

	vector<Node> arr;

	Segment_Tree() {
		arr.resize(RANGE << 2);
	}

	void build(vector<int> &v, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].val = v[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}

	void update(int pos, int val, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].update(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, val, i << 1, l, mid);
		else update(pos, val, i << 1 | 1, mid + 1, r);
		arr[i] = arr[i << 1] + arr[i << 1 | 1];
	}

	Node query(int ql, int qr, int i = 1, int l = 1, int r = n) {
		if (l > qr || r < ql)
			return Node();
		if (ql <= l && r <= qr)
			return arr[i];
		int mid = (l + r) >> 1;
		return query(ql, qr, i << 1, l, mid) + query(ql, qr, i << 1 | 1, mid + 1, r);
	}
};
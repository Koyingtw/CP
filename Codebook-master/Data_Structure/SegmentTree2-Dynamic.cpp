template<typename T, int RANGE>
struct Segment_Tree {
	struct Node {
		T val;
		int lch, rch;

		Node (): val(0), lch(-1), rch(-1) {} // mx: -INF, mn: INF, sum: 0, gcd: 1, lcm: 1

		Node operator +(const Node &rhs) {
			Node ret;
			ret.val = val + rhs.val; // 對應不同操作修改

			return ret;
		}

		void operator =(const Node &rhs) {
			val = rhs.val;
			return;
		}

		void update(int _val) {
			val += _val;
		}
	};

	vector<Node> arr;
	int nodecnt = 1;

	Segment_Tree() {
		arr.resize(RANGE << 2);
	}

	int newNode() {
		return ++nodecnt;
	}

	bool checkNode(char c, int i, bool flag = false) {
		if (c == 'l' && arr[i].lch == -1) {
			if (flag) arr[i].lch = newNode();
			return false;
		}
		if (c == 'r' && arr[i].rch == -1) {
			if (flag) arr[i].rch = newNode();
			return false;
		}
		return true;
	}

	void build(vector<T> &v, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].val = v[l];
			return;
		}
		int mid = (l + r) >> 1; 
		build(v, arr[i].lch = newNode(), l, mid);
		build(v, arr[i].rch = newNode(), mid + 1, r);
		arr[i] = arr[arr[i].lch] + arr[arr[i].rch];
	}

	void update(int pos, int val, int i = 1, int l = 1, int r = n) {
		if (l == r) {
			arr[i].update(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) checkNode('l', i, true), update(pos, val, arr[i].lch, l, mid);
		else checkNode('r', i, true), update(pos, val, arr[i].rch, mid + 1, r);

		arr[i] = arr[arr[i].lch] + arr[arr[i].rch];
	}

	Node query(int ql, int qr, int i = 1, int l = 1, int r = n) {
		if (l > qr || r < ql)
			return Node();
		if (ql <= l && r <= qr)
			return arr[i];
		int mid = (l + r) >> 1;
		auto q1 = (checkNode('l', i) ? query(ql, qr, arr[i].lch, l, mid) : Node());
		auto q2 = (checkNode('r', i) ? query(ql, qr, arr[i].rch, mid + 1, r) : Node());
		return q1 + q2;
	}
};
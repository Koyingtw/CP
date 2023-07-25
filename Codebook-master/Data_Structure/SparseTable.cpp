// https://judge.yosupo.jp/problem/staticrmq 214 ms

template<typename T, int RANGE>
struct Sparse_Table {
	struct Node {
		T val;

		Node(): val(INF) {}

		Node operator +(const Node &rhs) {
			Node ret;
			ret.val = min(val, rhs.val);
			return ret; // 視情況修改
		}
	};
	vector<vector<Node>> arr;

	Sparse_Table() {
		arr.resize(__lg(RANGE) + 1, vector<Node>(RANGE, Node()));
	}

	void build(auto &v) {
		for (int i = 1; i <= n; i++) {
			arr[0][i].val = v[i];
		}
		for (int i = 1; i <= __lg(n); i++)
			for (int j = 1; j + (1 << (i - 1)) <= n; j++)
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j + (1 << (i - 1))];
	}

	Node query(int ql, int qr) {
		int lg = __lg(qr - ql + 1);
		return arr[lg][ql] + arr[lg][qr - (1 << lg) + 1];
	}
};
#define OPTIMIZE 0
#define Interactive 0

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e9;
const int INF = 0x3f3f3f3f; // INF = 0x3f3f3f3f, INT_MAX
const int MOD = 1e6+7; // MOD = 1e9+7, 1e8+7, 998244353
const long long LINF = 1e18;
#define INIT(arr, val) fill(arr, arr+(int)(sizeof(arr)/sizeof(arr[0])), val)
#define REP(i, lb, rb, inc) for(int i = (lb); i < (rb); i += inc)
#define RREP(i, rb, lb, dec) for(int i = (rb)-1; i >= (lb); i -= dec)
#define REPN(i, s, n) for(int i = s; i < n; ++i)
#define RREPN(i, n, s) for(int i = n-1; i >= s; --i)
typedef long long ll;
typedef queue<int> QI;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<string> VSTR;
#define pb push_back
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<ll, ll> PLL;
#define mp make_pair
#define mt make_tuple
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
#define endl '\n'
#if !Interactive
#	define Foxyy cin.tie(0); cout.sync_with_stdio(0); cout.tie(0);
#else
#	define Foxyy ;
#endif
#define I_Suck_At_Coding signed main()

#if IDE
#	pragma GCC optimize ("trapv")
#endif

#if OPTIMIZE
#	pragma GCC optimize ("Ofast")
#	pragma GCC target ("avx,avx2,fma")
#endif

class dummy_ostream : public std::ostream {
	public:
		dummy_ostream():
			std::ostream(&m_sb) {}
	private:
		class NullBuffer : public std::streambuf {
			public:
				int overflow(int c) { return c; }
		} m_sb;
};
class redirect_ostream {
	public:
		redirect_ostream(ostream &_os):
			os(_os) {}
		
		template<class T>
		redirect_ostream& operator << (const T &x) {
			os << x;
			return *this;
		}
	private:
		ostream &os;
};
class dual_ostream {
	public:
		dual_ostream(ostream &_os1, ostream &_os2):
			os1(_os1), os2(_os2) {}
		
		template<class T>
		dual_ostream& operator << (const T &x) {
			os1 << x;
			os2 << x;
			return *this;
		}
	private:
		ostream &os1, &os2;
};

#if IDE && !Interactive
	ifstream fin("cin.in");
	ofstream fout("cout.out");
	ofstream ferr("cerr.out");
	dual_ostream Output(fout, cout);
	dual_ostream Error(ferr, cerr);
#	define Input fin
#else
#	define Input cin
	redirect_ostream Output(cout);
#	if IDE
		redirect_ostream Error(cerr);
#	else
		dummy_ostream Error;
#	endif
#endif

#define READ(a, t) static t a; Input >> a
#define READARR(arr, n) REP(___i, 0, (n), 1) Input >> arr[___i];
#define PRINTARR(arr, n) { REP(___i, 0, (n), 1) Output << arr[___i] << " "; Output << endl; }

#define RI(a) READ(a, int)
#define RD(a) READ(a, double)
#define RC(a) READ(a, char)
#define RLL(a) READ(a, ll)
#define RSTR(a) READ(a, string)
#define RVI(__a, n) VI __a(n); READARR(__a, n)
#define RVLL(__a, n) VLL __a(n); READARR(__a, n)
#define RVSTR(__a, n) VSTR __a(n); READARR(__a, n)

#define randInt(l, r) uniform_int_distribution<int>(l, r-1)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int N, A, B;
string S;
void init() {
	Input >> N >> A >> B;
	Input >> S;
}

void solve() {
	int ans = N*A;
	if (B < 0) {
		int cnt = 1;
		char ch = S[0];
		REPN(i, 1, S.size())
			if (S[i] != ch)
				ch = S[i], cnt++;
		ans += (cnt/2+1)*B;
	} else {
		ans += N*B;
	}
	Output << ans << endl;
}

I_Suck_At_Coding {
	Foxyy
	
	int T = 1;
	Input >> T;
	while(T--) {
		init();
		solve();
	}
}
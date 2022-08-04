#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e9+7;
template<class T>struct segment_tree{
	int n;
	struct node{
		int l,r;
		T sum,mx,mn;
		T lz;
		node(){
			l = r = sum = 0,mx = 0,mn = 0;
			lz = 0;
		}
		friend bool operator ==(node a,node b){
			return (a.l==b.l and a.r==b.r);
		}
	};
	vector<node>arr;
	void init(int _n){
		n = _n;
		arr.assign(n<<2,node());
	}
	void pull(node &ans,node left,node right){
		if(left==node()){
			ans = right;
			return;
		}
		if(right==node()){
			ans = left;
			return;
		}
		ans.mn = min(left.mn,right.mn);
		ans.mx = max(left.mx,right.mx);
		ans.sum = left.sum+right.sum;
		ans.l = left.l,ans.r = right.r;
	}void pull(int idx){
		pull(arr[idx],arr[idx<<1],arr[idx<<1|1]);
	}
	void push(int idx){
		if(arr[idx].lz==0)return;
		arr[idx<<1].mn = arr[idx].lz;
		arr[idx<<1].mx = arr[idx].lz;
		arr[idx<<1].sum = arr[idx].lz*(arr[idx<<1].r-arr[idx<<1].l+1);
		arr[idx<<1].lz = arr[idx].lz;
		arr[idx<<1|1].mn = arr[idx].lz;
		arr[idx<<1|1].mx = arr[idx].lz;
		arr[idx<<1|1].sum = arr[idx].lz*(arr[idx<<1|1].r-arr[idx<<1|1].l+1);
		arr[idx<<1|1].lz = arr[idx].lz;
		arr[idx].lz = 0;
	}
	void build(const vector<T>&v,int l,int r,int idx){
		if(l==r){
			arr[idx].sum = arr[idx].mx = arr[idx].mn = v[l];
			arr[idx].l = arr[idx].r = l;
			arr[idx].lz = 0;
			return;
		}
		int m = (l+r)>>1;
		build(v,l,m,idx<<1);
		build(v,m+1,r,idx<<1|1);
		pull(idx);
	}void build(const vector<T>&v,int r){
		build(v,0,r,1);
	}
	void update(int l,int r,T y,int idx = 1){
		if(l<=arr[idx].l and arr[idx].r<=r){
			arr[idx].mn = y;
			arr[idx].mx = y;
			arr[idx].sum = y*(arr[idx].r-arr[idx].l+1);
			arr[idx].lz = y;
			return;
		}
		push(idx);
		int m = (arr[idx].l+arr[idx].r)>>1;
		if(l<=m)update(l,r,y,idx<<1);
		if(r>m)update(l,r,y,idx<<1|1);
		pull(idx);
	}
	node query(int l,int r,int idx = 1){
		if(l<=arr[idx].l and arr[idx].r<=r){
			return arr[idx];
		}
		push(idx);
		int m = (arr[idx].l+arr[idx].r)>>1;
		node ans,left = node(),right = node();
		if(l<=m)left = query(l,r,idx<<1);
		if(r>m)right = query(l,r,idx<<1|1);
		pull(ans,left,right);
		return ans;
	}
	node search(int val,int idx = 1){
		if(arr[idx].l==arr[idx].r)return arr[idx];
		if(arr[idx<<1].mx>val){
			return search(val,idx<<1);
		}
		return search(val,idx<<1|1);
	}
};
signed main(){
	int n,m;
	cin>>n>>m;
	segment_tree<int>seg;
	seg.init(200010);
	vector<int>v(n+5),ans(n+5),tmp(200010,-inf);
	vector<tuple<int,int,int>>q;
	int mx = 0;
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		v[i]++;
		mx = max(mx,v[i]);
	}
	seg.build(tmp,200005);
	for(int i = 0;i<m;i++){
		int l,r;
		cin>>l>>r;
		q.emplace_back(l,r,i);
	}
	sort(q.begin(),q.end());
	reverse(q.begin(),q.end());
	int now = n;
	for(auto [l,r,id]:q){
		while(now>=l){
			seg.update(v[now],v[now],now);
			now--;
		}
		ans[id] = seg.search(r).mx;
	}
	for(int i = 0;i<m;i++){
		if(ans[i]==-inf){
			cout<<mx<<endl;
		}
		else{
			cout<<v[ans[i]]<<endl;
		}
	}
}
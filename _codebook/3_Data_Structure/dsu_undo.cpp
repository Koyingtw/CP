struct dsu_undo{
	static const int NN=3E5+5;
	int n,g;
	int f[N],h[N];
	stack<pair<pii,pii>> stk;
	void init(int nn){
		n=g=nn;clear(stk);
		for(int i=0;i<=n;++i)
			h[i]=1,f[i]=i;
	}
	int fa(int x){
		return x==f[x]?x:fa(f[x]);
	}
	bool Union(int x,int y){
		x=fa(x),y=fa(y);
		if(x==y) return false;
		assert(x!=y);
		if(h[x]>h[y]) swap(x,y);
		stk.push({{x,f[x]},{y,h[y]}});
		if(h[x]==h[y]) ++h[y];
		f[x]=y;
		--g;
		return true;
	}
	void undo(int  times){
		for(int _=0;_<times;++_){
			pair<pii,pii> x=stk.top();stk.pop();
			f[x.Fi.Fi]=x.Fi.Se;
			h[x.Se.Fi]=x.Se.Se;
			++g;
		}
	}
}dsu;

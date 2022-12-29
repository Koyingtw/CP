struct seg{
	int m=INF_32,c=INF_32;
	seg(int m_,int c_){
		m=m_,c=c_;
	}
	seg(){}
	int val(int  x){
		return m*x+c;
	}
	bool operator == (const seg b){
		return m==b.m&&c==b.c;
	}
};
seg NUL=seg();
struct Node{
	seg L;
	int lc=0,rc=0;
}tr[4*N];
int ptr=0;
int ceil2(int x){
	return x>0?x/2:-((-x+1)/2);
}
void add(int& id,int l,int r,int id2){
	if(!id) return tr[id=id2]={tr[id2].L,0,0},void();
	if(l==r){
		if(tr[id].L.val(l)>tr[id2].L.val(l)) swap(tr[id].L,tr[id2].L);
		return;
	}
	if(tr[id2].L.m>tr[id].L.m) swap(tr[id2].L,tr[id].L);
	int mid=ceil2(l+r);
	if(tr[id2].L.val(mid)<tr[id].L.val(mid)){
		swap(tr[id2].L,tr[id].L);
		add(tr[id].lc,l,mid,id2);
	}else{
		add(tr[id].rc,mid+1,r,id2);
	}
}
int merge(int a,int b,int l,int r){
	//cerr<<a<<" "<<b<<" "<<l<<" "<<r<<"\n";
	if(!a||!b) return a+b;
	if(l==r) return tr[a].L.val(l)<tr[b].L.val(l)?a:b;
	int mid=ceil2(l+r);
	tr[a].lc=merge(tr[a].lc,tr[b].lc,l,mid);
	tr[a].rc=merge(tr[a].rc,tr[b].rc,mid+1,r);
	add(a,l,r,b);
	return a;
}
int ask(int id,int l,int r,int x){
	if(!id) return INF_64;
	if(l==r)
		return tr[id].L.val(x);
	int mid=ceil2(l+r);
	if(x<=mid) return min(tr[id].L.val(x),ask(tr[id].lc,l,mid,x));
	else return min(tr[id].L.val(x),ask(tr[id].rc,mid+1,r,x));
}

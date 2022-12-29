// degree sequence d1>=d2>=...>=dn
// check if d is a d.s of a simple graph 
if (sum_of_d%2==1) return 0;
for (int k=1;k<=n;k++){
	int sum1=0,sum2=0;
	for (int i=1;i<=k;i++) sum1+=d[i];
	for (int i=k+1;i<=n;i++) sum2+=min(d[i],k);
	if (sum1>k*(k-1)+sum2) return 0;
}


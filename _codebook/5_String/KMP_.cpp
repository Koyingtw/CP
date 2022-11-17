void build(){
	dp[0][s[0]-'a']=1;
	x=0;
	for (int j=1;j<n;j++)
	{
		for (int k=0;k<26;k++) dp[j][k]=dp[x][k];
 
		dp[j][s[j]-'a']=j+1;
		//if (dp[j][s[j]-'a']==n) dp[j][s[j]-'a']=dp[x][s[j]-'a'];
		x=dp[x][s[j]-'a'];
        if (x==n) x=dp[x][s[j]-'a'];
	}
    /*for (int i=0;i<n;i++){
        for (int j=0;j<3;j++)
            cout <<dp[i][j]<<" ";
        cout <<"\n";}*/
}

#include <bits/stdc++.h>
#define N 3005
using namespace std;
int n,f[N][N],ans;
char a[N],b[N];
int main() {
	int que;
	scanf("%d",&que);
	while(que--){
		memset(f,0x7f,sizeof(f));
		cin>>b;n=strlen(b);
		for(int i=1;i<=n;i++)a[i]=b[i-1];
		if(a[1]==a[n])f[1][n]=0;
		else f[1][n]=1;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				f[i][j]=min(f[i][j],f[i-1][j]+1);
				f[i][j]=min(f[i][j],f[i][j+1]+1);
				if(a[i]==a[j])f[i][j]=min(f[i][j],f[i-1][j+1]);
				f[i][j]=min(f[i][j],f[i-1][j+1]+1);
			}
		}
		ans=n-1;
		for(int i=1;i<n;i++)ans=min(ans,f[i][i+1]);
		for(int i=1;i<=n;i++)ans=min(ans,f[i][i]);
		printf("%d\n",ans);
	}
	return 0;
}

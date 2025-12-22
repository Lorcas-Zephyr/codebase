#include<bits/stdc++.h>
const int mod=998244353;
const int MAXN=1e5+10;
using namespace std;
long long n,k,deep[MAXN],ma[MAXN],b[MAXN][100],head[MAXN],t,po[MAXN],cnt,ans;
struct Node
{
	int v,lk;
}a[MAXN];
long long d(long long id,long long de)
{
	deep[id]=de;
	long long maxx=0;
	//cout<<id<<endl;
	if(head[id]==-1)
	{
		ma[id]=de;
		return de;
	}
	for(int i=head[id];i!=-1;i=a[i].lk)
		maxx=max(maxx,d(a[i].v,de+1));
	ma[id]=maxx;
	t=max(maxx,t);
}
long long che(long long x,long long k)
{
	return (long long)(po[x]/po[x-k]);
}
int main()
{
	cin>>n>>k;
	po[0]=1;
	for(int i=1;i<=n;i++) po[i]=po[i-1]*i,po[i]%=mod;
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n-1;i++)
	{
		int x;
		cin>>x;
		a[++cnt].v=i+1;
		a[cnt].lk=head[x];
		head[x]=cnt;
	}
	d(1,1);
	for(int i=1;i<=n;i++)
	{
		//cout<<deep[i]<<' '<<b[deep[i]][0]<<' ';
		b[deep[i]][0]++;
		b[deep[i]][b[deep[i]][0]]=ma[i];
		//cout<<b[deep[i]][0]<<' '<<b[deep[i]+1][0]<<endl;
	}
//	for(int i=1;i<=t;i++)
//	{
//		for(int j=1;j<b[i][0];j++)
//			for(int k=b[i][0];k>j;j++)
//			{
//				if(b[i][j]<b[i][j-1])
//				{
//					b[i][j],b[i][j-1]=b[i][j-1],b[i][j];
//				}
//			}
//	}
	for(int i=1;i<=t;i++)
		sort(b[i]+1,b[i]+1+b[i][0]);
	for(int i=1;i<=t;i++)
	{
//		for(int j=0;j<=b[i][0];j++) cout<<b[i][j]<<" ";
//		cout<<endl;
		if(b[i][0]<=k) continue;
		{
			int cnt=0;
			for(int j=2;j<=b[i][0];j++)	
			{
				if(b[i][j]==b[i][j-1]) cnt++;
				else cnt=0;
				if(j>k&&b[i][j]==b[i][j-1])
				{
					while(b[i][j]==b[i][j-1]) j++,cnt++;
					//cout<<j-2<<' '<<k-1<<' '<<che(j-2,k-1)<<' '<<cnt<<endl;
					ans+=che(j-2,k-1)*cnt;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

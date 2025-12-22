#include<bits/stdc++.h>
const int MAXN=5e5+10;
using namespace std;
int T,n,b[MAXN],m;
struct Node
{
	int v,id;
}a[MAXN];
bool cmp(Node a,Node b)
{
	return a.v<b.v;
}
bool cmp1(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].v;
			a[i].id=i;
			b[i]=i-1;
		}
		sort(a+1,a+1+n,cmp);
		int l=0;
		int r=0;
		int sum=0;
		int maxr=0,maxl=0,maxx=0;
		while(r<=n && l<=r)
		{
			while(r<n && sum+a[r+1].v<=m) r++;
			int len=r-l;
//			cout<<l<<' '<<r<<endl;
			if(len>=maxx)
			{
				maxx=len;
				maxl=l;
				maxr=r;
			}
			l++;
			sum-=a[l].v;
		}
//		for(int i=maxl+1;i<=maxr;i++)
//			b[i]++;
		for(int i=1;i<=maxl;i++)  b[i]++;
		for(int i=maxr+1;i<=n;i++) b[i]++;
//		int sum=0;
//		int cnt=0;
//		int t=n+1;
//		for(int i=1;i<=n;i++)
//		{
////			cout<<a[i].v+sum<<' ';
//			if(a[i].v+sum<=m)
//			{
//				sum+=a[i].v;
//				cnt++;
//			}else
//			{
//				t=i;
//				break;
//			}
//		}
//		for(int i=t;i<=n;i++)
//			b[i]++;
		sort(b+1,b+1+n,cmp1);
		int rk=0;
		bool f=0;
//		cout<<maxx<<endl;
		for(int i=1;i<=n;i++)
		{
			rk=i;
			if(b[i]!=b[i-1])
				if(maxx>b[i])
				{
					f=1;
					break;
				}
		}
		if(f) cout<<rk<<endl;
		else 
			if(maxx>b[n])
				cout<<rk<<endl;
		else cout<<rk+1<<endl;
	}
	return 0;
}


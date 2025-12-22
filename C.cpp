#include<bits/stdc++.h>
#define mod 998244353
int n,ans[510];
using namespace std;
struct Node
{
	int v,id;
}l[510];
bool cmp(Node a,Node b)
{
	return a.v>b.v;
}
bool check(int xx,int ll,int rr)
{
	cout<<"? "<<xx<<' '<<rr-ll+2<<' ';
	for(int i=ll;i<=rr;i++) cout<<l[i].id<<' ';
	cout<<xx;
	cout<<endl;
	fflush(stdout);
	int x;
	cin>>x;
	if(x>1) return 1;
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cout<<"? "<<i<<' '<<n<<' ';
			for(int j=1;j<=n;j++) cout<<j<<' ';
			cout<<endl;
			fflush(stdout);
			cin>>l[i].v;
			l[i].id=i;
		}
		sort(l+1,l+1+n,cmp);
		int id=1;
		int len=l[1].v;
		ans[1]=l[1].id;
		for(int i=l[1].v-1;i>=1;i--)
		{
			while(id<n && l[id].v>i) id++;
			int r=id;
			while(r<=n && l[r].v==i) r++;
			r--;
			int ll=id;
			id=r;
//			cout<<len-i<<endl;
			while(ll<r)
			{
				int mid=(ll+r)/2;
				if(check(ans[len-i],ll,mid)) r=mid;
				else if(check(ans[len-i],mid+1,r)) ll=mid+1;
			}
			ans[len-i+1]=l[r].id;
		}
		cout<<"! "<<len<<' ';
		for(int i=1;i<=len;i++) cout<<ans[i]<<' ';
		cout<<endl;
		fflush(stdout);
		
	}
	return 0;
}


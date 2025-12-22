#include<bits/stdc++.h>
const int MAXN=1e5+10;
using namespace std;
int n,ans[MAXN][2];
struct Node
{
	int v,id,nxt,pre;
}a[MAXN],b[MAXN];
bool cmp(Node a,Node b)
{
	return a.v<b.v;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		b[a[i].id]=a[i];
		b[a[i].id].nxt=a[i+1].id;
		b[a[i].id].pre=a[i-1].id;
	}
	//for(int i=1;i<=n;i++) cout<<b[i].id<<b[i].pre<<b[i].nxt<<endl;
	b[a[n].id].nxt=-1;
	b[a[1].id].pre=-1;
	for(int i=n;i>1;i--)
	{
		int ans1=-1,ans2=-1;
		//cout<<b[i].nxt<<endl;
		if(b[i].pre!=-1)
			ans1=b[i].v-b[b[i].pre].v;
		if(b[i].nxt!=-1)
			ans2=b[b[i].nxt].v-b[i].v;
		if(ans2==-1 || (ans1!=-1 && ans1<=ans2)) ans[i-1][0]=ans1,ans[i-1][1]=b[i].pre;
		else ans[i-1][0]=ans2,ans[i-1][1]=b[i].nxt;
		b[b[i].pre].nxt=b[i].nxt;
		b[b[i].nxt].pre=b[i].pre;
	//for(int i=1;i<=n;i++) cout<<b[i].id<<b[i].pre<<b[i].nxt<<endl;
	}
	for(int i=1;i<n;i++) cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
	return 0;
}

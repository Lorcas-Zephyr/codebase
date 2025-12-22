#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		long long n,x,ans=0,y;
		cin>>n;
		cin>>ans;
		y=ans;
		long long id=1;
		for(int i=2;i<=n;i++)
		{
			cin>>x;
			if(x>y) ans+=x-y,id=i;
			else ans+=max(0ll,x-1);
//			ans+=max(0ll,x-y); 
		}
		cout<<ans<<endl;
	 } 
	return 0;
}


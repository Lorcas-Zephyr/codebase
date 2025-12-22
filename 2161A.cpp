#include<bits/stdc++.h>
using namespace std;
int T,r0,x,d,n,ans;
string s;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>r0>>x>>d>>n;
		cin>>s;
		if(r0<x) ans=n;
		else
		{
			int t=0;
			int id=0;
			while(r0>=x && id<n)
			{
				if(s[id]=='1') r0-=d,t++;
				id++;
			}
			ans=n-id+t;
		}
		cout<<ans<<endl;
	}
	return 0;
}

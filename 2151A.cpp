#include<bits/stdc++.h>
using namespace std;
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
			int id=0;
			while(r0>=x && id<n)
			{
				if(s[i]=='1') r0-=d;
				id++;
			}
			if(r0<x) ans=n-id;
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int T,n,a[110];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
		bool t=0;
		for(int i=1;i<=100;i++)
		{
			if(a[i]>1)
			{
				t=1;
				break;
			}
		}
		if(t) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}


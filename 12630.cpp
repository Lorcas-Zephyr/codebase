#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[100010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>a[i-1]) ans+=a[i]-a[i-1]+1;
	}
	cout<<ans;
	return 0;
}

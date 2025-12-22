#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[200010];
int T;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		long long sum=0;
		for(int i=n;i>=1;i-=2) sum+=a[i];
//		if(n%2==1) sum+=a[1];
		cout<<sum<<endl;
	}
	return 0;
}


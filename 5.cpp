#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
const int MAXN=100;
int T,n,a[MAXN][MAXN];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int x=1;
		int y=1;
		int minn=1;
		int maxx=n*n;
		int t=0;
		while(1)
		{
//			cout<<x<<' '<<y<<' '<<minn<<' '<<maxx<<endl;
			if(!t)a[x][y]=minn++;
			if(t) a[x][y]=maxx--;
			t=1-t;
			if(x%2==1&&x==n&&y==n) break;
			if(x%2==0&&x==n&&y==1) break;
			if((x%2==1&&y==n)) x++;
			else if(x%2==0 && y==1) x++;
			else if(x%2==1) y++;
			else if(x%2==0) y--;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
	return 0;
}


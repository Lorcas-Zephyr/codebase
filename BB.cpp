#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e6+10;
int T,x,y;
bool b[MAXN];
void prime()
{
	b[1]=1;
	for(int i=2;i<=1000;i++)
	{
		if(b[i]) continue;
		for(int j=2;j<=1000000/i+1;j++)
			b[i*j]=1;
	}
}
int main()
{
	prime();
	cin>>T;
	while(T--)
	{
		cin>>x>>y;
		if(abs(x-y)!=2)
		{
			cout<<"N\n";
			continue;
		}
		if(b[x]==0 && b[y]==0)
		{
			cout<<"Y\n";
		}else cout<<"N\n";
	}
	return 0;
}

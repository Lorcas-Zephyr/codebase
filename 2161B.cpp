#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int dic[4][2]={1,0,0,1,-1,0,0,-1};
int n,T;
bool b[MAXN][MAXN];
string s[MAXN];
void check(int x,int y)
{
	if(x<n && s[x+1][y]!='#' && ((y<n-1 && s[x+1][y+1]=='#')||(y>0 && s[x+1][y-1]=='#')||(x<n-1 && s[x+2][y]=='#')))
	if(x>1 && x<n-1)
		if(s[x-1][y]!='#' && s[x+2][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#') && !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(x<n && s[x+1][y]!='#' && ((y<n-1 && s[x+1][y+1]=='#')||(y>0 && s[x+1][y-1]=='#')||(x<n-1 && s[x+2][y]=='#')))
	if(x==1)
		if(s[x+2][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#') && !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(x<n && s[x+1][y]!='#' && ((y<n-1 && s[x+1][y+1]=='#')||(y>0 && s[x+1][y-1]=='#')||(x<n-1 && s[x+2][y]=='#')))
	if(x==n-1)
		if(s[x-1][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#') && !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y-1]==s[x+1][y-2]&&s[x+1][y-2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x+1][y+1]==s[x+1][y+2]&&s[x+1][y+2]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x+1][y-1]==s[x+1][y+1]&&s[x+1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(x>1 && s[x-1][y]!='#' && ((y<n-1 && s[x-1][y+1]=='#')||(y>0 && s[x-1][y-1]=='#')||(x>1 && s[x-2][y]=='#')))
	if(x>2 && x<n)
		if(s[x-2][y]!='#' && s[x+1][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&&!(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#') && !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&& !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x-1][y-1]==s[x-1][y-1]&&s[x-1][y-1]=='#')&& !(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(x>1 && s[x-1][y]!='#' && ((y<n-1 && s[x-1][y+1]=='#')||(y>0 && s[x-1][y-1]=='#')||(x>1 && s[x-2][y]=='#')))
	if(x==2)
		if(s[x+1][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&&!(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#') && !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&& !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x-1][y-1]==s[x-1][y-1]&&s[x-1][y-1]=='#')&& !(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(x>1 && s[x-1][y]!='#' && ((y<n-1 && s[x-1][y+1]=='#')||(y>0 && s[x-1][y-1]=='#')||(x>1 && s[x-2][y]=='#')))
	if(x==n)
		if(s[x-2][y]!='#')
		{
			if(y>1 && y<n-2)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&&!(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#') && !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#')&& !(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-2)
				if( !(s[x-1][y-1]==s[x-1][y-1]&&s[x-1][y-1]=='#')&& !(s[x-1][y-1]==s[x-1][y-2]&&s[x-1][y-2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==0)
				if(!(s[x-1][y+1]==s[x-1][y+2]&&s[x-1][y+2]=='#'))
				{
					s[x-1][y]='#';
					return ;
				}else ;
			else if(y==n-1)
				if( !(s[x-1][y-1]==s[x-1][y+1]&&s[x-1][y+1]=='#'))
				{
					s[x+1][y]='#';
					return ;
				}
		}
	if(y<n-1 && s[x][y+1]!='#' && ((x<n && s[x+1][y+1]=='#')||(x>0 && s[x-1][y+1]=='#')||(y<n-2 && s[x][y+2]=='#')))
	if(y>0 && y<n-2)
		if(s[x][y-1]!='#' && s[x][y+2]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#') && !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}
		}
	if(y<n-1 && s[x][y+1]!='#' && ((x<n && s[x+1][y+1]=='#')||(x>0 && s[x-1][y+1]=='#')||(y<n-2 && s[x][y+2]=='#')))
	if(y==0)
		if(s[x][y+2]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#') && !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}
		}
	if(y<n-1 && s[x][y+1]!='#' && ((x<n && s[x+1][y+1]=='#')||(x>0 && s[x-1][y+1]=='#')||(y<n-2 && s[x][y+2]=='#')))
	if(y==n-2)
		if(s[x][y-1]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&&!(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#') && !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y+1]==s[x+1][y+1]&&s[x+1][y+1]=='#')&& !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y+1]==s[x+2][y+1]&&s[x+2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y+1]==s[x-2][y+1]&&s[x-2][y+1]=='#'))
				{
					s[x][y+1]='#';
					return ;
				}
		}
	if(y>0 && s[x][y-1]!='#' && ((x<n && s[x+1][y-1]=='#')||(x>0 && s[x-1][y-1]=='#')||(y>1 && s[x][y-2]=='#')))
	if(y>1 && y<n-1)
		if(s[x][y-2]!='#' && s[x][y+1]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&&!(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#') && !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}
		}
	if(y>0 && s[x][y-1]!='#' && ((x<n && s[x+1][y-1]=='#')||(x>0 && s[x-1][y-1]=='#')||(y>1 && s[x][y-2]=='#')))
	if(y==1)
		if(s[x][y+2]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&&!(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#') && !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}
		}
	if(y>0 && s[x][y-1]!='#' && ((x<n && s[x+1][y-1]=='#')||(x>0 && s[x-1][y-1]=='#')||(y>1 && s[x][y-2]=='#')))
	if(x==n)
		if(s[x-2][y]!='#')
		{
			if(x>2 && x<n)
				if( !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&&!(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#') && !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n-1)
				if(  !(s[x-1][y-1]==s[x+1][y-1]&&s[x+1][y-1]=='#')&& !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==0)
				if( !(s[x+1][y-1]==s[x+2][y-1]&&s[x+2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}else ;
			else if(x==n)
				if( !(s[x-1][y-1]==s[x-2][y-1]&&s[x-2][y-1]=='#'))
				{
					s[x][y-1]='#';
					return ;
				}
		}
}
void dfs(int x,int y)
{
	b[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dic[i][0];
		int yy=y+dic[i][1];
		if(b[xx][yy]==0 && s[xx][yy]=='#') 
		{
			dfs(xx,yy);
		}
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		memset(b,false,sizeof(b));
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		int x=-1,y=-1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<n;j++)
			{
				if(s[i][j]=='#')
				{
					x=i,y=j,check(i,j);
					cout<<i<<j<<endl;	
					for(int i=1;i<=n;i++)
					{
						for(int j=0;j<n;j++)
						{
							cout<<s[i][j];
						}
						cout<<endl;
					}
				}
			}
		if(x==-1)
		{
			cout<<"YES\n";
			continue;
		}
		dfs(x,y);
		bool t=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<n;j++)
			{
				if(s[i][j-2]==s[i][j] && s[i][j]==s[i][j-1] && s[i][j]=='#')
				{
					t=1;
					break;
				}
			}
			if(t) break;
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[i-1][j]==s[i][j] && s[i][j]==s[i-2][j] && s[i][j]=='#')
				{
					t=1;
					break;
				}
			}
			if(t) break;
		}	
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(s[i][j]=='#' && b[i][j]==0)
				{
					t=1;
					break;
				}
			}
			if(t) break;
		}
		if(t) cout<<"NO\n";
		else cout<<"YES\n";
	}
			
	return 0;
}

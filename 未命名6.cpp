#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
	cin>>t;
    while(t--)
    {
        long long n,x;
		cin>>n>>x;
	    vector<long long>num(n+1);
	    long long sum=0;
		long long maxx=0;
		long long tt;
		vector<long long>a;
	    for(long long i=1;i<=n;i++)
	    {
	        cin>>num[i];
	        sum+=num[i];
	        if(num[i]==x)
	        {
	            maxx++;a.push_back(num[i]);
	        }
	    }
	    sort(num.begin()+1,num.end());
	    tt=sum/x;
	    long long res=0;
	    res+=maxx*x;
	    long long l=1,r=n-maxx;long long lev=maxx;long long z=0;
	    while(lev<tt)
	    {
	        while(z+num[r]<x)
	        {
	            a.push_back(num[l]);
	            z+=num[l];
	            l++;
	        }
	        a.push_back(num[r]);res+=num[r];
	        z+=num[r];
	        z%=x;
	        r--;
	        lev++;
	    }
	    if(a.size()<n)
	    {
	        for(long long i=l;i<=r;i++)
	        {
	            if(a.size()<n)a.push_back(num[i]);
	        }
	    }
	    cout<<res<<endl;
	    for(auto&w:a)
	    {
	        cout<<w<<' ';
	    }
	    cout<<endl;
    }
}

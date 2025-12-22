#include <bits/stdc++.h>

using namespace std;
long long xl,yl,xr,yr,xdl,ydl,xdr,ydr;
bool pdx(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4) {
	if(y1==y3&&y1==y4){
		if((x3>x1&&x3>x2)&&(x4>x1&&x4>x2))return 0;
		if((x3<x1&&x3<x2)&&(x4<x1&&x4<x2))return 0;
		return 1;
	}
	long long xx=x1,yy=y1;
	x1-=xx;x2-=xx;x3-=xx;x4-=xx;
	y1-=yy;y2-=yy;y3-=yy;y4-=yy;
	if(y3*y4>0)return 0;
	long long x=x3*(y3-y4)-y3*((x3-x4));
	if(y3-y4>0)
		if(x>x2*(y3-y4))return 0;else;
	else 
		if(x<x2*(y3-y4))return 0;
	if(x<0)return 0;
	return 1;
}
bool pdy(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4) {
	if(x1==x3&&x1==x4){
		if((y3>y1&&y3>y2)&&(y4>y1&&y4>y2))return 0;
		if((y3<y1&&y3<y2)&&(y4<y1&&y4<y2))return 0;
		return 1;
	}
	long long xx=x1,yy=y1;
	x1-=xx;x2-=xx;x3-=xx;x4-=xx;
	y1-=yy;y2-=yy;y3-=yy;y4-=yy;
	if(x3*x4>0)return 0;

	long long y=-1.0*x3*(y3-y4)+y3*(x3-x4);
	//cout<<y<<endl;
	if(x3-x4>0)
		if(y>y2*(x3-x4))return 0; else;
	else
		if(y<y2*(x3-x4))return 0;
	if(y<0)return 0;
	return 1;
}

int main() {
	int que;
	scanf("%d",&que);
	while(que--){
		scanf("%lld %lld %lld %lld",&xl,&yl,&xr,&yr);
		scanf("%lld %lld %lld %lld",&xdl,&ydl,&xdr,&ydr);
		if((xdl>=xl&&xdl<=xr)&&(ydl>=yl&&ydl<=yr)){printf("STOP\n");continue;}
		if((xdr>=xl&&xdr<=xr)&&(ydr>=yl&&ydr<=yr)){printf("STOP\n");continue;}
		if(pdx((long long)xl,(long long)yr,(long long)xr,(long long)yr,(long long)xdl,(long long)ydl,(long long)xdr,(long long)ydr)){printf("STOP\n");continue;}
		if(pdx((long long)xl,(long long)yl,(long long)xr,(long long)yl,(long long)xdl,(long long)ydl,(long long)xdr,(long long)ydr)){printf("STOP\n");continue;}
		if(pdy((long long)xl,(long long)yl,(long long)xl,(long long)yr,(long long)xdl,(long long)ydl,(long long)xdr,(long long)ydr)){printf("STOP\n");continue;}
		if(pdy((long long)xr,(long long)yl,(long long)xr,(long long)yr,(long long)xdl,(long long)ydl,(long long)xdr,(long long)ydr)){printf("STOP\n");continue;}
		printf("OK\n");
	}
	
	return 0;
}

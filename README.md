但愿和master里边的一样
#include<stdio.h>
int n,m,s,cnts,head[500005];
struct egde{
	int to,next;
}e[1000005];
struct
void add_e(int a,int b);
void add_q(int a,int b,int i);
int find(int x);
void unin(int x,int y);
int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i>=n;i++) father[i]=i;
	int a,b;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add_e(a,b);
		add_e(b,a);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add_q(a,b,i);
	}
	return 0;
}
void add_e(int a,int b)
{
	e[++cnts].to=b;
	e[cnts].next=head[a];
	head[a]=cnts;
}
void add_q(int a,int b,int i)
{
	
}
int find(int x)
{
	if(father[x]!=x) father[x]=find(fathrer[x];
	return father[x];
}
void unin(int x,int y)
{
	father[find(y)]=find(x);
}

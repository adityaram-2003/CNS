#include<stdio.h>
#include<conio.h>
#include<string.h>

int n,s,nb,nbs[15],snbs[15],delay[15][15],i,j,temp[15],ze=0;
void min();
void main()
{
//clrscr();
printf("Enter the no.of nodes:");
scanf("%d",&n);
printf("\nEnter the source node:");
scanf("%d",&s);
printf("\nEnter the no.of Neighbours to %d:",s);
scanf("%d",&nb);
printf("\nEnter the Neighbours:");
for(i=1;i<=nb;i++)
scanf("%d",&nbs[i]);
printf("\nEnter the timedelay form source to nbs:");
for(i=1;i<=nb;i++)
scanf("%d",&snbs[i]);
for(i=1;i<=nb;i++)
{
printf("\nEnter the timedelay of %d: ",nbs[i]);
for(j=1;j<=n;j++)
scanf("%d",&delay[i][j]);
}
for(i=1;i<=nb;i++)
{
printf("\nThe timedelays of %d: ",nbs[i]);
for(j=1;j<=n;j++)
printf("%3d",delay[i][j]);
}
min();
getch();
}
void min()
{
int sum,k,y=1,store=1;
printf("\n\t\t\tnew- rout");
printf("\n\t\t\ttime-");
printf("\n\t\t\tdelay");
printf("\n");
for(i=1;i<=n;i++)
{
sum=0;
k=1;
for(j=1;j<=nb;j++)
{
temp[k++]=delay[j][i];
}

sum=temp[1]+snbs[1];
for(y=2;y<=nb;y++)
{
if(sum>temp[y]+snbs[y])
{

sum=temp[y]+snbs[y];
store=y;
}
}

if(s==i)
printf("\n\t%d+\t%d =\t%d --",ze,ze,ze);
else
printf("\n\t%d +\t%d =\t%d\t%d",temp[store],snbs[store],sum,nbs[store]);
}
}


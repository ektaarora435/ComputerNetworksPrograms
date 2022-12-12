#include<iostream>
 #include<conio.h>

using namespace std;
 struct node
{
unsigned dist[20]; unsigned from[20];
}dvr[10]; int main()
{
int cost[20][20];
int i,j,k,nodes,count=0; cout<<"\nEnter the number of nodes: "; cin>>nodes;
cout<<"\nEnter the cost matrix: \n"; for(i=0;i<nodes;i++)
{
for(j=0;j<nodes;j++)
{
cin>>cost[i][j];
cost[i][i]=0; dvr[i].dist[j]=cost[i][j];//initializing distance
dvr[i].from[j]=j;
}
}

do
{
count=0; for(i=0;i<nodes;i++)
for(j=0;j<nodes;j++) for(k=0;k<nodes;k++)
if(dvr[i].dist[j]>cost[i][k]+dvr[k].dist[j])
{//calculate the minimum distance


dvr[i].dist[j]=dvr[i].dist[k]+dvr[k].dist[j];
dvr[i].from[j]=k; count++;
}
}while(count!=0); for(i=0;i<nodes;i++)
{
cout<<"\nFor router: "<<i+1; for(j=0;j<nodes;j++)
{
cout<<"\t\n node "<<j+1<<" via "<<dvr[i].from[j]+1<<" Distance "<<dvr[i].dist[j];
}
}
cout<<endl; getch();
}


#include<iostream>
#include<conio.h>
#include<time.h>
#include<math.h>
#define TOT_FRAMES 500
#define FRAMES_SEND 10
using namespace std;
class SelRepeat
{
private:
int frames;
int arr[TOT_FRAMES];
int send[FRAMES_SEND];
int rcvd[FRAMES_SEND];
char rcvd_ack[FRAMES_SEND];
int sw;
int rw;
public:
void input()
{
int m,n,i;
cout<<"Enter the number of bits: ";
cin>>n;
m=pow(2,n);
int t=0;
frames=(m/2);
for(i=0;i<TOT_FRAMES;i++)
{
arr[i]=t;
t=(t+1)%m;
}
for(i=0;i<frames;i++)
{
send[i]=arr[i];
rcvd[i]=arr[i];
rcvd_ack[i]='n';
}
rw=sw=frames;

sender(m);
}
void sender(int m)
{
for(int i=0;i<frames;i++)
{
if(rcvd_ack[i]=='n')
cout<<"SENDER : Frame "<<send[i]<<" is sent\n";
}
receiver(m);
}
void receiver(int m)
{
time_t t;
int f;
int j;
int f1;
int a1;
char ch;
srand((unsigned)time(&t));
for(int i=0;i<frames;i++)
{
if(rcvd_ack[i]=='n')
{
f=rand()%10;
if(f!=5)//if f=5 frame is discarded for some reason
//else frame is correctly recieved
{
for(int j=0;j<frames;j++)
{
if(rcvd[j]==send[i])

{
cout<<"RECEIVER:Frame "<<rcvd[j]<<" recieved correctly\n";

rcvd[j]=arr[rw];
rw=(rw+1)%m;
break;}
}
}
int j;
if(j==frames)
cout<<"RECEIVER:Duplicate Frame "<<send[i]<<"discarded\n";
a1=rand()%5;
if(a1==3)//if al==3 then ack is lost
//else recieved
{
cout<<"(Acknowledgement "<<send[i]<<" lost)\n";
cout<<"(sender timeouts-->Resend the frame)\n";

rcvd_ack[i]='n';
}
else
{
cout<<"(Acknowledgement "<<send[i]<<" recieved)\n"; rcvd_ack[i]='p';
}
}
else
{
int ld=rand()%2;
//if =0 then frame damaged
//else frame lost
if(ld==0)
{
cout<<"RECEIVER : Frame "<<send[i]<<" is damaged\n";
cout<<"RECEIVER : Negative Acknowledgement "<<send[i]<<" sent\n";
}
else
{
cout<<"RECEIVER : Frame "<<send[i]<<" is lost\n";
cout<<"SENDER TIMEOUT-->RESEND THE FRAME\n";
}
rcvd_ack[i]='n';
}
}
}
for(int j=0;j<frames;j++)
{
if(rcvd_ack[j]=='n')
break;
}
int i=0;
for(int k=j;k<frames;k++)
{
send[i]=send[k];
if(rcvd_ack[k]=='n')
rcvd_ack[i]='n';
else
rcvd_ack[i]='p';
i++;
}
if(i!=frames)
{
for(int k=i;k<frames;k++)
{
send[k]=arr[sw];
sw=(sw+1)%m;
rcvd_ack[k]='n';
}

}
cout<<"Want to continue?";
cin>>ch;
cout<<"\n";
if(ch=='y')
sender(m);
else
exit(0);
}};
int main()
{
SelRepeat obj;
obj.input();
}

#include <iostream>
 #include<stdio.h>
 using namespace std;

int main()
{
int msg[20],gr[20];
int m,n;
cout<<"Enter the range of the message: ";
cin>>n;
cout<<"Enter the message: ";
 for(int i=0;i<n;i++)

cin>>msg[i];
cout<<"Enter the range of generator polynomial: ";
 cin>>m;
cout<<"Enter the generator polynomial: "; for(int i=0;i<m;i++)
cin>>gr[i]; cout<<"Message\n"; for(int i=0;i<n;i++)
cout<<msg[i]; for(int i=0;i<m;i++)
cout<<gr[i];


int codeword[n+(m-1)]; for(int i=0;i<n;i++)
codeword[i]=msg[i]; for(int i=n;i<n+(m-1);i++)
codeword[i]=0; int temp[n+(m-1)];
for(int i=0;i<n+(m-1);i++) temp[i]=codeword[i];
for(int i=0;i<n;i++)
{
int j=0,k=i; if(temp[k]>=gr[j])
while(j<m) temp[k++]^=gr[j++];
}

int crc[20];
for(int i=0,j=n;i<(m-1);i++,j++) crc[i]=temp[j];
cout<<"\ncrc: \n"; for(int i=0;i<(m-1);i++)
cout<<crc[i]; cout<<"\n";
for(int i=0,j=n;i<(m-1);i++,j++) codeword[j]=crc[i];
cout<<"\nTransmitted Message: "; for(int i=0;i<n+(m-1);i++)
cout<<codeword[i]; cout<<"\n";

//FOR NOISY CHANNEL
int nbits,pos;
cout<<"Enter number of bits to flip: "; cin>>nbits;
for(int i=0;i<nbits;i++)
{
cout<<"Enter the position to flip: "; cin>>pos;
codeword[pos-1]=codeword[pos-1]==0?1:0;
}


cout<<"------- AT RECEIVER	\n";
for(int i=0;i<n+(m-1);i++) cout<<codeword[i];

cout<<"\n"; int temp2[n+(m-1)];
for(int i=0;i<n+(m-1);i++) temp2[i]=codeword[i];
for(int i=0;i<n;i++)
{
int j=0,k=i; if(temp2[k]>=gr[j])
while(j<m) temp2[k++]^=gr[j++];
}
int rem[20];
for (int i = n, j = 0; i < n + (m - 1); i++, j++) rem[j] = temp2[i];

cout << "Remainder: "; for (int i=0;i<(m-1);i++)
cout<<rem[i]; cout<<"\n"; int flag = 0;
for (int i = 0; i < (m - 1); i++)
if (rem[i] != 0) flag = 1;
cout <<"\n"; if (flag==0)
cout << "NO ERROR\n"; else
cout << "ERROR DETECTED DURING TRANSMISSION\n";

}

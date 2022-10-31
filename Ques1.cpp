#include<iostream>
#include <ctime>

using namespace std;

void normal(int a[],int n)
{
 int max1=a[0];
 int min1=a[0];
 for(int i=0;i<n;i++)
 {
  if(a[i]>max1)
  {
   max1=a[i];
  }
  if(a[i]<min1)
  {
   min1=a[i];
  }
 }
 cout<<"\n Max in normal "<<max1;
 cout<<"\n Min in normal "<<min1;
}

void divide(int a[],int start,int End,int &maxd,int &mind)
{
   int maxdd=0;
   int mindd=0;
 if(start==End)
 {
  maxd=a[start];
  mind=a[start];
 }

 else if(start==(End-1))
 {
  if(a[start]>a[End])
  {
   maxd=a[start];
   mind=a[End];
  }
  else{
   mind=a[start];
   maxd=a[End];
  }
 }
 else
  {
   int mid=(start+End)/2;
   divide(a,start,mid,maxd,mind);
   divide(a,mid+1,End,maxdd,mindd);
   if(maxd<maxdd)
   {
    maxd=maxdd;
   }
   if(mind>mindd)
   {
    mind=mindd;
   }

  }

}

int main()
{
clock_t start1,end1;
 int n;
 cout<<"\n Enter the size of an array ";
 cin>>n;
 int a[n];
 cout<<" ";
 for(int i=0;i<n;i++){
    a[i]=rand()%100;

 }
 for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
 int maxd=a[0];
 int mind=a[0];
 int start=0;
 int End=n-1;
 start1 = clock();
 normal(a,n);
  end1 = clock();
cout<<"\n Total time taken in sec "<<double(end1-start1)/double(CLOCKS_PER_SEC);
 start1 = clock();
 divide(a,start,End,maxd,mind);
 end1 = clock();
 cout<<"\n Max in divide "<<maxd;
  cout<<"\n Min in divide "<<mind;
  cout<<"\n Total time taken is "<<double(end1-start1)/double(CLOCKS_PER_SEC);
 return 0;
}

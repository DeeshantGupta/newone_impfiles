#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int main(){
    int M;

   int n;
   cout<<"\n Enter the no. of elements : ";
   cin>>n;
    double p[n];
    double w[n];
    cout<<"\n Enter the profit of element : \n";
   for(int i=1; i<=n; i++){
       cout<<" "<<i<<": ";
       cin>>p[i];
   }
   cout<<"\n Enter the weight of element : \n";
   for(int i=1; i<=n; i++){
     cout<<" "<<i<<" : ";
       cin>>w[i];
   }
   cout<<"\nEnter the Maximum Weight of knapsack: ";
   cin>>M;
   int P=0;
   double r[n];
   for(int i=1; i<=n; i++){
        r[i]=p[i]/w[i];
   }
   for(int i=1; i<=n; i++){
       if(M>0 && w[i]<=M){
           M=M-w[i];
           P=P+p[i];

       }
       else{
          double fraction=M/w[i];
          P=P+(fraction*p[i]);
       }
   }
   cout<<"\nTotal profit: "<<P<<"\n";


   return 0;
}

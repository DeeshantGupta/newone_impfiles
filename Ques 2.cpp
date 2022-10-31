#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

void merge_sort(int arr[],int,int);
void merg(int arr[],int,int ,int);

int main(){
    clock_t start,start1;
    double run_time;
    int arr[100000];
    int s;
    cout<<"Enter the size of an array : ";
    cin>>s;
    srand(time(0));
    for(int i = 0; i < s; i++){
        arr[i]=rand()%100;
    }

    cout<<"\n\n Array is:\n[ ";
    for(int i = 0; i<s; i++){
        cout<<arr[i]<<" , ";
    }
    cout<<"]";
    start = clock();
    merge_sort(arr,0,s-1);
    start = clock()-start;
    cout<<"\n\n Sorted Linked List using Merge Sort : \n\n";
    cout<<"[[";
    for(int j=0;j<s;j++){
        cout<<arr[j]<<"  ";
    }


    run_time = float(start)/CLOCKS_PER_SEC;
    cout << "\nTime taken by sorting procedure is : " <<run_time;
    cout << " sec " << endl;
    cout<<"\n Best cases ";
    start1 = clock();
    merge_sort(arr,0,s-1);
    start1 = clock()-start1;

    run_time = float(start1)/CLOCKS_PER_SEC;
    cout << "\nTime taken by sorting procedure is : " <<run_time;
    cout << " sec " << endl;
    return 0;
}

//Recursive function to perform Merge Sort
void merge_sort(int arr[],int beg,int end1){
    if(beg < end1){
        int mid =(beg+end1)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end1);
        merg(arr,beg,mid,end1);
    }
    return;
}
//Merg function to perform Merge Sort
void  merg(int arr[],int beg,int mid,int end1){
    int C[10000],i,j,k;
    i= beg;
    j=mid+1;
    k=0;
    while((i<=mid)&&(j<=end1)){
        if(arr[i]<=arr[j]){
            C[k] =arr[i];
            i++;
            k++;
        }
        else{
            C[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        C[k] = arr[i];
        i++;
        k++;
    }
    while(j<=end1){
        C[k]= arr[j];
        j++;
        k++;
    }
    for(i=beg;i<=end1;i++){
        arr[i] = C[i-beg];
    }
}

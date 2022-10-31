#include <iostream>
#include <time.h>
using namespace std;

void Shell_sort(int arr[],int n){
    for(int g=n/2;g>0;g=g/2){
        for(int i=g;i<n;i=i+1){
            int ins_val = arr[i];
            int j;
            for (j=i;j>=g && arr[j-g]>ins_val;j=j-g){
                arr[j] = arr[j - g];
            }
            arr[j] = ins_val;
        }
    }
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
}

// Driver code
int main() {
    int s,arr[100000];
    clock_t start,start1;
    double run_time;
    cout<<"Enter the size of an array : ";
    cin>>s;
    cout<<"Enter the Elements of an array ";
    srand(time(0));
    for(int i = 0; i < s; i++){
        arr[i]=rand()%100;
    }

    cout<<"Array is:\n[ ";
    printArray(arr,s);
    cout<<"]";
    start = clock();
    Shell_sort(arr,s);
    start = clock()-start;
    run_time = float(start1)/CLOCKS_PER_SEC;
    cout << "\nTime taken by sorting procedure is : " <<run_time;
    cout << " sec " << endl;

    cout << "\n\nSorted array using Shell Sort: \n";
    cout<<"[";
    printArray(arr,s);
    cout<<"]\n\n";
     cout<<"\n Best Case ";
    start = clock();
    Shell_sort(arr,s);
    start = clock()-start;
    run_time = float(start1)/CLOCKS_PER_SEC;
    cout << "\nTime taken by sorting procedure is : " <<run_time;
    cout << " sec " << endl;
}


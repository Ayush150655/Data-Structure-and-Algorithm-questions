#include<iostream>
using namespace  std;

void bubbleSort(int *arr,int n)
{
    if(n==0 || n==1)
        return ;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    bubbleSort(arr,n-1);
}

int main()
{
    int arr[]={2,6,4,3,9,7,25,40,13};
    bubbleSort(arr,9);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

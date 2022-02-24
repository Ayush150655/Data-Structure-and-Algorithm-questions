// BUBBLE SORT


#include<iostream>
using namespace  std;

void bubbleSort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
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

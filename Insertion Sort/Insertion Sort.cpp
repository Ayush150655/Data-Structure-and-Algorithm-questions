#include<iostream>
using namespace std;

void insertionSort(int *arr,int n)
{
    int j;
    for(int i=1;i<n;i++)
    {
        int temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int arr[]={3,5,1,7,4,2,0,9,6,8};
    insertionSort(arr,10);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

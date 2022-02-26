#include<iostream>
using namespace std;

int partition(int *arr,int s,int e)
{
    int pivot=arr[s];
    int c=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
            c++;
    }
    int newpivot=s+c;
    swap(arr[newpivot],arr[s]);

    int i=s,j=e;
    while(i<newpivot && newpivot<j)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        
        if(i<newpivot && newpivot<j)
            swap(arr[i++],arr[j--]);
    }
    return newpivot;
}

void quickSort(int *arr, int s ,int e)
{
    if(s>=e)
        return;
    
    int p=partition(arr,s,e);

    quickSort(arr,0,p-1);
    quickSort(arr,p+1,e);
}

int main()
{
    int arr[]={7,6,10,9,1,5,3};
    int n=7;
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

//SELECTION SORT


#include<iostream>
using namespace std;

void selectionSort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(arr[min],arr[i]);
    }
}

int main()
{
    int arr[]={5,3,9,4,7,1};
    selectionSort(arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

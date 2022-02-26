#include<iostream>
using namespace std;

void merge(int *arr,int s, int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;           //length of first array
    int len2=e-mid;             //length of second array

    int *a= new int[len1];      //creating first array
    int *b=new int [len2];      //creating second array

    int k=s;
    for(int i=0;i<len1;i++)     //copying array elements to first array
    {
        a[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++)     //copying array elements to second array
    {
        b[i]=arr[k++];
    }

    //Merging two arrays
    int i=0;
    int j=0;
    k=s;
    while(i<len1 && j<len2)
    {
        if(a[i]<b[j])
            arr[k++]=a[i++];
        else    
            arr[k++]=b[j++];
    }
    while(i<len1)
    {
        arr[k++]=a[i++];
    }
    while(j<len2)
    {
        arr[k++]=b[j++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    if(s>=e)
        return;
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);       //left array 
    mergeSort(arr,mid+1,e);     //right array
    merge(arr,s,e);             //merging two arrays
}

int main()
{
    int arr[]={38,27,43,3,9,82,10};
    int s=0;
    int e=6;
    mergeSort(arr,s,e);

    for(int i=0;i<7;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

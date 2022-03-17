#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[0] = -1;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i + 1;

    if(leftchild < n && arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }

    if(rightchild < n && arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }

    if(largest != i)               //checking if largest is updated or not
    {
        swap(arr[largest],arr[i]);
        heapify(arr, n, largest);       //for checking and placing correctly its child nodes
    }        

}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[1],arr[size]);
        size--;
        heapify(arr, size, 1);
    }
}


int main()
{
    int arr[8]={-1,23,25,12,63,52,97,20};
    int n = 7;
    //Heap Creation
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }
    //Printing 
    cout<<"Before Sorting : ";
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //Sorting
    heapSort(arr, n);
    cout<<"After Sorting : ";
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

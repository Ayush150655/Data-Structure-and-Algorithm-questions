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

    void insert(int val)
    {
        size+=1;
        int index = size;
        arr[index]=val;
        while(index > 1)
        {
            int parentindex = index/2;
            if(arr[parentindex] < val)
            {
                swap(arr[parentindex],arr[index]);
                index = parentindex;
            }
            else{
                return;
            }
        }
    }

    void deleteHeap()
    {
        if(size == 0)
        {
            cout<<"Heap is empty"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        
        int i=1;
        while(i < size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            int largechild = max(leftindex , rightindex);
            if(largechild < size)
            {
                swap(arr[largechild],arr[i]);
                i=largechild;
            }
            else{
                return;
            }
        }
    }



    void print()
    {
        for(int i=1;i<=size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};


//HEAPIFY ALGORITHM

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


int main()
{
    heap h;
    h.insert(60);
    h.insert(20);
    h.insert(10);
    h.insert(15);
    h.insert(72);
    h.insert(30);
    h.insert(75);
    h.print();
    h.deleteHeap();
    h.print();
    int arr[8]={-1,23,25,12,63,52,97,20};
    int n = 7;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

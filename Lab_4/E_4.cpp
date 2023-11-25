#include <iostream>
using namespace std;


void siftDown(int *a, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        siftDown(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        siftDown(a, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(a[0], a[i]);
        siftDown(a, i, 0);
    }
}


int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for (int i=0; i<n; ++i)
        cin>>a[i];

    heapSort(a, n);

    for (int i=0; i<n; ++i)
        cout << a[i] << " ";
}
#include <iostream>
using namespace std;
void quicksort(int *a, int l, int r)
{
    int i = l;
    int j = r;
    int mid = a[(l + r + 1) / 2];

    while (i <= j)
    {
        while (a[i] < mid)
        {
            i++;
        }
        while (a[j] > mid)
        {
            j--;
        }
        if (i <= j)
        {
            if (a[i] > a[j])
            {
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
            }
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quicksort(a, i, r);
    }
    if (l < j)
    {
        quicksort(a, l, j);
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int arr[n];
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = a[i];
    }
    cin >> k;
    int itog[k];
    int i;
    int count;
    for (i = 0; i < k; i++)
    {
        int x, y, tmp;
        int x_index = 0;
        int y_index = 0;
        cin >> x >> y;
        count = 0;
        tmp = 0;

        int l = -1;
        int r = n;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (arr[m] < x)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }

        x_index = r;

        l = -1;
        r = n;
        while (l < r - 1)
        {
            int m = (l + r) / 2;
            if (arr[m] <= y)
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }

        y_index = l;

        itog[i] = y_index - x_index + 1;
    }
    for (i = 0; i < k; i++)
    {
        cout << itog[i] << ' ';
    }
}
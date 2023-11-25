#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int k=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (2*i <= n && a[i] > a[2*i]) {
            k=0;
        }

        if (2*i+1 <= n && a[i] > a[2*i+1]) {
            k=0;
        }
    }
    if (k==1)
        cout<<"YES";
    else
        cout<<"NO";
}
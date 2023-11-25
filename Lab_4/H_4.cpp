#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    const int base = 1000*1000*1000;
    cin>>n;
    vector<int> sum;
    for(int p=0;p<n;p++)
    {
        string s;
        cin>>s;
        vector<int> a;
        for(int i= int(s.length());i>0;i-=9)
        {
                if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
                else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
        }
        while (a.size() > 1 && a.back() == 0)
	        a.pop_back();

        int carry = 0;
        for (size_t i=0; i<max(a.size(),sum.size()) || carry; ++i) {
            if (i == sum.size())
                sum.push_back (0);
            sum[i] += carry + (i < sum.size() ? a[i] : 0);
            carry = sum[i] >= base;
            if (carry)  sum[i] -= base;
        }

    }
    printf ("%d", sum.empty() ? 0 : sum.back());
    for (int i=(int)sum.size()-2; i>=0; --i)
	    printf ("%09d", sum[i]);
}
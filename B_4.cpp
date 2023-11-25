#include <iostream>
#include <vector>
using namespace std;

class VectorOfVectors
{
private:
    vector<vector<int>> data;

public:
    void getelement(int k)
    {
        cout << data[k][0] << "\n";
    }

    void addVector(vector<int> &ver)
    {
        
        data.push_back(ver);
    }

    void removeElement(long long verIndex, long long elementIndex)
    {
        if (verIndex >= 0 && verIndex < data.size())
        {
            vector<int> &ver = data[verIndex];
            if (elementIndex >= 0 && elementIndex < ver.size())
            {
                ver.erase(ver.begin() + elementIndex);
            }
        }
    }
    long long parent(long long i) { return (i - 1) / 2; }
    long long leftChild(long long i) { return 2 * i + 1; }
    long long rightChild(long long i) { return 2 * i + 2; }

    void heapify(long long k, long long i)
    {
        long long smallest = i;
        long long left = 2 * i + 1;
        long long right = 2 * i + 2;

        if (left < data[k].size() && data[k][left] < data[k][smallest])
            smallest = left;
        if (right < data[k].size() && data[k][right] < data[k][smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(data[k][i], data[k][smallest]);
            heapify(k, smallest);
        }
    }

    void arrCout(long long k)
    {
        for (long long i = 0; i < data[k].size(); i++)
        {
            cout << data[k][i] << ' ';
        }
        cout << endl;
    }

    void deleteMin(long long k)
    {

        data[k][0] = data[k][data[k].size() - 1];
        data[k].pop_back();
        heapify(k, 0);
    }

    void insert(long long k, long long value)
    {
        data[k].push_back(value);
        int n = data[k].size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(k, i);
        }
    }

    bool getempty(long long k)
    {
        return data[k].empty();
    }

    void merge(long long k, long long m, long long counter)
    {
        counter = data.size() - 1;
        for (long long i = 0; i < data[k].size(); i++)
        {
            data[counter].push_back(data[k][i]);
        }
        for (long long i = 0; i < data[m].size(); i++)

        {
            data[counter].push_back(data[m][i]);
        }
        for (long long i = data[counter].size() / 2 - 1; i >= 0; i--)
            siftDown(counter, i);
    }
    void decrease(long long k, long long x, long long y)
    {
        long long tmp=-1;
        for (long long i = 0; i < data[k].size(); i++)
        {
            if (data[k][i] == x)
            {
                tmp = i;
            }
        }
        if (tmp != -1)
        {
            removeElement(k, tmp);
            insert(k, y);
        }
    }
    void siftDown(long long k, long long i)
    {
        long long left;
        long long right;
        long long j;
        while (2 * i + 1 < data[k].size())
        {
            left = 2 * i + 1;
            right = 2 * i + 2;
            j = left;
            if (right < data[k].size() and data[k][right] < data[k][left])

                j = right;

            if (data[k][i] <= data[k][j])
                break;
            swap(data[k][i], data[k][j]);
            i = j;
        }
    }

};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a;
    VectorOfVectors qq;
    long long counter = -1;
    while (cin >> a)
    {

        if (a == "create")
        {
            vector<int> new_vec{-1};
            qq.addVector(new_vec);
            counter++;
        }
        else if (a == "insert")
        {
            long long k, x;
            cin >> k >> x;
            qq.insert(k, x);
        }
        else if (a == "extract-min")
        {

            long long k;
            cin >> k;

            if (qq.getempty(k))
            {
                cout << "*"<<'\n';
            }
            else
            {
                qq.getelement(k);
                qq.deleteMin(k);
            }
        }
        else if (a == "merge")
        {
            long long k;
            long long m;
            cin >> k;
            cin>>m;
            k=0;
            m=0;
            vector<int> new_vec;
            qq.addVector(new_vec);
            counter++;

            qq.merge(k, m, counter);
        }
        else if (a == "decrease-key")
        {
            long long k, x, y;
            cin >> k >> x >> y;
            qq.decrease(k, x, y);
        }
        else if (a == "ar")
        {
            long long k;
            cin >> k;
            qq.arrCout(k);
        }
    }
}
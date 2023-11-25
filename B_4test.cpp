#include <iostream>
#include <vector>

using namespace std;

class VectorofVectors
{
private:
    vector<vector<int>> data;
    int cnt = 0;

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

    void makeHeap(int k)
    {
        int n = data[k].size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(k, i);
        }
    }

public:
    void deleteMin(long long k)
    {

        data[k][0] = data[k][data[k].size() - 1];
        data[k].pop_back();
        heapify(k, 0);
    }
    bool getempty(long long k)
    {
        return data[k].empty();
    }
    void getelement(int k)
    {
        cout << data[k][0] << "\n";
    }

    void create()
    {
        data.push_back(vector<int>());
        cnt++;
    }

    void insert(int k, int x)
    {
        if (k < cnt)
        {
            data[k].push_back(x);
            makeHeap(k);
        }
    }

    int extractMin(int k)
    {
        if (k >= cnt or data[k].empty())
        {
            return -1;
        }
        int root = data[k][0];
        data[k][0] = data[k].back();
        data[k].pop_back();
        heapify(k, 0);
        return root;
    }
    void merge(int k, int m)
    {
        data.push_back(vector<int>());
        for (int i = 0; i < data[k].size(); i++)
        {
            data[cnt].push_back(data[k][i]);
        }
        for (int i = 0; i < data[m].size(); i++)
        {
            data[cnt].push_back(data[m][i]);
        }
        makeHeap(cnt);
        cnt++;
    }

    void decreaseKey(int k, int oldValue, int newValue)
    {
        for (int i = 0; i < data[k].size(); i++)
        {
            if (data[k][i] == oldValue)
            {
                data[k][i] = newValue;
                break;
            }
        }
        makeHeap(k);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    VectorofVectors qq;
    string a;
    while (cin >> a)
    {
        if (a == "create")
        {
            qq.create();
        }
        else if (a == "insert")
        {
            int k, x;
            cin >> k >> x;
            qq.insert(k, x);
        }
        else if (a == "extract-min")
        {
            long long k;
            cin >> k;

            if (qq.getempty(k))
            {
                cout << "*";
            }
            else
            {
                qq.getelement(k);
                qq.deleteMin(k);
            }
        }
        else if (a == "merge")
        {
            int k, m;
            cin >> k >> m;
            qq.merge(k, m);
        }
        else if (a == "decrease-key")
        {
            int k, x, y;
            cin >> k >> x >> y;
            qq.decreaseKey(k, x, y);
        }
    }
}
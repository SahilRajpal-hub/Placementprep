#include <bits/stdc++.h>
using namespace std;

// *** All sorting algos implemented
// ? https://leetcode.com/problems/sort-an-array/discuss/1401412/C%2B%2B-Clean-Code-Solution-or-Fastest-or-All-(15%2B)-Sorting-Methods-or-Detailed

int cnt = 0;
void printVector(vector<int> v);
void merge(vector<int> &v, int s, int m, int e)
{
    int i = s, j = m + 1, idx = s;
    vector<int> va(v.size());
    while (i <= m && j <= e)
    {
        if (v[i] < v[j])
        {
            va[idx++] = v[i++];
        }
        else
        {
            va[idx++] = v[j++];
            cnt += m - i + 1;
        }
    }
    while (i <= m)
        va[idx++] = v[i++];
    while (j <= e)
        va[idx++] = v[j++];
    for (int i = s; i <= e; i++)
    {
        v[i] = va[i];
    }
    va.clear();
}
void mergeSort(vector<int> &v, int s, int e)
{
    if (s >= e)
        return;
    int m = (s + e) / 2;
    mergeSort(v, s, m);
    mergeSort(v, m + 1, e);
    merge(v, s, m, e);
}

// *** quick sort
int partititon(vector<int> &v, int s, int e)
{
    int pivot = v[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (v[i] <= pivot)
            cnt++;
    }

    int pivotIdx = s + cnt;
    swap(v[pivotIdx], v[s]);

    int i = s, j = e;
    while (i < pivotIdx && j > pivotIdx)
    {
        while (v[i] < v[pivotIdx])
        {
            i++;
        }
        while (v[j] > v[pivotIdx])
        {
            j--;
        }
        if (i < pivotIdx && j > pivotIdx)
        {
            swap(v[i], v[j]);
        }
    }
    return pivotIdx;
}
void quickSort(vector<int> &v, int s, int e)
{
    if (s >= e)
        return;

    int pivotIdx = partititon(v, s, e);

    quickSort(v, s, pivotIdx - 1);
    quickSort(v, pivotIdx + 1, e);
}

// *** Print the vector
void printVector(vector<int> v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> v{3, 5, 6, 1, 2, 4};
    mergeSort(v, 0, v.size() - 1);
    printVector(v);
    cout << cnt << endl;
    return 0;
}
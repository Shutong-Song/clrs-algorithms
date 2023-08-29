/*
sorting algorithms
*/
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>



//insertion sort: inplace sorting with time complexity: O(n^2)
void insertionsort(std::vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>-1 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//addtion of two n-bit binary integers
std::vector<int> binary_add(std::vector<int>& arr1, std::vector<int>& arr2)
{
    //two arrays: for example 1 2 3 + 9 0 7 = 1 0 3 0
    std::vector<int> res(arr1.size()+1,0);
    int n = arr1.size();
    int carry = 0;
    for(int i = n-1; i > -1; i--)
    {
        carry += arr1[i] + arr2[i];
        res[i+1] = carry%10;
        carry /= 10;
    }
    res[0] = carry;
    return res;
}


//selection sort
void selectionsort(std::vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int smallest_idx = i;
        for(int j = i+1; j < arr.size(); j++)
        {
            if(arr[smallest_idx] > arr[j])
                smallest_idx = j;
        }
        std::swap(arr[smallest_idx], arr[i]);
    }
}


//mergesort: divide and conquer
void merge_(std::vector<int>& arr, int low, int mid, int high)
{
    std::vector<int> left(arr.begin()+low, arr.begin()+mid);
    std::vector<int> right(arr.begin()+mid, arr.begin()+high);
    int i = 0, j = 0;
    int k = low;
    while(i < left.size() && j < right.size())
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < left.size())
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < right.size())
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(std::vector<int>& arr, int low, int high)
{
    int n = arr.size();
    if(low < high - 1)
    {
        int mid = (low + high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid, high);
        merge_(arr, low, mid, high);
    }
}

int main()
{
    std::vector<int> arr = {19, 7, 1, 8, 2, 2, 13, 7};
    mergesort(arr, 0, arr.size());
    //std::vector<int> test(arr.begin()+2, arr.begin()+5); //intialize with subset of another vector like python
    //selectionsort(arr);
    std::for_each(arr.begin(), arr.end(), [](const int x){std::cout << x << "\n";});

    //std::vector<int> arr1 = {1, 2, 3}, arr2 = {9, 0, 7};
    //std::vector<int> res = binary_add(arr1, arr2);
    //std::for_each(res.begin(), res.end(), [](const int x){std::cout << x << "\n";});


    //std::vector<int> arr = {19, 7, 1, 8, 2, 2, 13, 7};
    //insertionsort(arr);
    //std::for_each(arr.begin(), arr.end(), [](const int x){std::cout << x << "\n";});
}
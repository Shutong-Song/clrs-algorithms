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

int main()
{
    std::vector<int> arr1 = {1, 2, 3}, arr2 = {9, 0, 7};
    std::vector<int> res = binary_add(arr1, arr2);
    std::for_each(res.begin(), res.end(), [](const int x){std::cout << x << "\n";});


    //std::vector<int> arr = {19, 7, 1, 8, 2, 2, 13, 7};
    //insertionsort(arr);
    //std::for_each(arr.begin(), arr.end(), [](const int x){std::cout << x << "\n";});
}
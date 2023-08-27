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


int main()
{
    std::vector<int> arr = {19, 7, 1, 8, 2, 2, 13, 7};
    insertionsort(arr);
    std::for_each(arr.begin(), arr.end(), [](const int x){std::cout << x << "\n";});
}
/*
binary search
*/
#include<iostream>
#include<vector>
#include<string>



//binary search for sorted list
int binary_search(std::vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size();
    while(low < high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}


int binary_search_recursive(std::vector<int>& arr, int target, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            return binary_search_recursive(arr, target, low, mid);
        else
            return binary_search_recursive(arr, target, mid+1, high);
    }
    return -1;
}


int main()
{
    std::vector<int> arr = {1, 2, 7, 12, 21};
    int i = arr.size();
    int x = binary_search_recursive(arr, 29, 0, i);
    std::cout << x << std::endl;
    //std::for_each(arr.begin(), arr.end(), [](const int x){std::cout << x << "\n";});
}
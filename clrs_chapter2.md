### chaper 2


2.1-1 Using Figure 2.2 as a model, illustrate the operation of INSERTION SORT on the array [31; 41; 59; 26; 41; 58].  
```cpp
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
```

2.1-2 Rewrite the INSERTION SORT procedure to sort into nonincreasing instead of nondecreasing order.  
```cpp
void insertionsort(std::vector<int>& arr)
{
    for(int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>-1 && key > arr[j]) //change key < arr[j]
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

2.1-4 Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A and B. The sum of the two integers should be stored in binary form in an (n+1) array. State the problem formally and write pseudocode for adding the two integers.  
```cpp
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
```
### chapter 2


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


2.2-2 selection sort  
```cpp
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
```


2.2-4 How can we modify almost any algorithm to have a good best-case running time?  
Answer: check if the input is already satisfy the output condition, for example, for sort, check if the input array is already sorted, if yes, return the results


2.3-1 Using Figure 2.4 as a model, illustrate the operation of merge sort.  
```cpp
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
```

2.3-3 Use mathematical induction to show that when n is an exact power of 2, the solution of the recurrence  



$$
T(n) = \begin{cases} 2,\text{ if n= 2}\\\\2T(n/2)+n, \text{ if n = $2^k$} \end{cases}
$$


is $T(n) = nlgn$  
Answer: 
Known that $T(n) = nlg(n)$, prove that $T(2n) = 2nlg(2n)$  
Known that $T(2^k) = 2^klg(2^k)$  
we have:  






$$

2^{k+1}lg(2^{k+1}) = 2*2^k(lg2^k + lg2)  
\Rightarrow 2*2^k(lg2^k + 1)  
\Rightarrow 2T(2n/2) + 2n  

$$



we have proved that $T(2n) = 2T(2n/2) + 2n$  




2.3-4 We can express insertion sort as a recursive procedure as follows. In order to sort $A[1..n]$, we recursively sort $A[1...n-1]$ and then insert $A[n]$ into the sorted array $A[1...n-1]$. Write a recurrence for the running time of this recursive version of insertion sort.  
```cpp
void insert_kth(std::vector<int>& arr, int k)
{
    int key = arr[k+1];
    while(k>-1 && key < arr[k])
    {
        arr[k+1] = arr[k];
        k--;
    }
    arr[k+1] = key;
}

void insertionsort_recursive(std::vector<int>& arr, int n)
{
    if(n > 0)
    {
        insertionsort_recursive(arr, n-1);
        insert_kth(arr, n-1);
    }
}
```


2.3-5 binary search  
```cpp
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

```


2.3-6 Observe that the while loop of lines 5–7 of the insertion sort procedure in Section 2.1 uses a linear search to scan (backward) through the sorted subarray $A[1...n-1]$. Can we use a binary search (see Exercise 2.3-5) instead to improve the overall worst-case running time of insertion sort to $\Theta(nlgn)$  
Answer: binary search will not improve the worst-case because sort insertion sort involves move the elements not just look up.




2.3-7 Describe a $\Theta(nlgn)$ time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.  
Answer: first sort the array S,  and use two pointers from begin and end of the array, if the addition of two pointers values are greater than x, move higher value pointer down, otherwise move lower value pointer up, util two pointers meet, if still no result, it doesn't exist, otherwise exit.
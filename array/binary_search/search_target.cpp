#include <iostream>
#include <algorithm>
#include <vector>
//Athor:zhangzb
//Date:2020/12/30
/*****************************************************************************************************
*Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*You are given a target value to search. If found in the array return its index, otherwise return -1.
*You may assume no duplicate exists in the array
******************************************************************************************************/
int binary_search(std::vector<int> sorted_vector, int length, int target)
{
    int low = 0, high = length - 1;
    while(low < high)
    {
        int middle = (low+high)/2;
        if(target == sorted_vector[middle])
        {
            return middle;
        } 
        if(sorted_vector[low] <= sorted_vector[middle])
        {
            if(sorted_vector[middle] > target && sorted_vector[low] < target)
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        else
        {
            if(sorted_vector[middle] < target && target < sorted_vector[high]) 
            {
                low = middle + 1;
            }      
            else
            {
                high = middle -1;
            }
        }
        
    }  
}

int main()
{
    int array[] = {5,6,7,8,9,0,1,2,3,4};
    std::vector<int> sorted_array(array,array+sizeof(array)/sizeof(int));
    int index = binary_search(sorted_array, sorted_array.size(), 2);
    printf("%s %d %d \n", __FUNCTION__, __LINE__, index);
    return 0;    
}

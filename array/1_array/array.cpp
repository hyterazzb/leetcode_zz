//Athor:zhangzb
//date: 2020/12/28
/********************************************************************************************
*Given a sorted array, remove the duplicates in place such that each element appear only once
*and return the new length.
*Do not allocate extra space for another array, you must do this in place with constant memory.
*For example, Given input array A = [1,1,2],
*Your function should return length = 2, and A is now [1,2].
*********************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
/*
*Remove duplicates element form array
*时间复杂度0(n) 空间复杂度0(1)
*/
class Solution
{
public:
    int RemoveDuplicateElement(std::vector<int>& numbers)
    {
        auto temp = std::unique(numbers.begin(), numbers.end());
        numbers.erase(temp, numbers.end());
        return std::distance(numbers.begin(), numbers.end());
    }
};

int main()
{
    Solution solution;
    std::vector<int> number;
    number.push_back(1);
    number.push_back(1);
    number.push_back(3);
    number.push_back(3);
    number.push_back(5);
    printf("out_num:%d\n",solution.RemoveDuplicateElement(number));
    for(auto iter = number.begin(); iter != number.end(); iter++)
    {
        std::cout << "out:" << *iter << std::endl;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
//Athor:zhangzb
//Date:2020/12/28
/********************************************************************************** 
* 
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note:
* 
* Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
* The solution set must not contain duplicate triplets.
* 
*     For example, given array S = {-1 0 1 2 -1 -4},
* 
*     A solution set is:
*     (-1, 0, 1)
*     (-1, -1, 2)
* 
*               
**********************************************************************************/
std::vector<std::vector<int>> CalculateSum(std::vector<int> &input_vector)
{
    std::vector<std::vector<int>> result;
    if(input_vector.size() < 2)
    {
        return result;
    }
    std::sort(input_vector.begin(), input_vector.end());
    size_t length = input_vector.size();
    for(size_t i = 0; i < input_vector.size()-2; i++)
    {
        if(i > 0 && input_vector[i -1] == input_vector[i])continue;
        int a = input_vector[i];
        int low = i + 1;
        int high = length - 1;
        while(low < high)
        {
            int b = input_vector[low];
            int c = input_vector[high];
            if(0 == a+b+c)
            {
                std::vector<int> temp_result;
                temp_result.push_back(a);        
                temp_result.push_back(b);
                temp_result.push_back(c);
                result.push_back(temp_result);
                while(low < length - 1 && input_vector[low-1] == input_vector[low])low++;
                while(high > 0 && input_vector[high-1] == input_vector[high])high++;
                low++;
                high--;
            }
            else if(a+b+c > 0)
            {
                while(high > 0 && input_vector[high-1] == input_vector[high])high--;
                high--;
            }
            else
            {
                while(low < length-1 && input_vector[low-1] == input_vector[low])low++;
                low++;
            }
        }
        
    }
    return result; 
}
int PrintResult(std::vector<std::vector<int>>&result)
{
    for(size_t i = 0; i < result.size(); i++)
    {
        printf("{");
        for(size_t j = 0; j < result[i].size(); j++)
        {
            printf("%d, ", result[i][j]);
        }
        printf("}");
    }
    return 0;
}
int main()
{
    int a[] = {1,2,3,4,5,6,-1,-2,-3,-4,-5,-6};
    //int a[] = { -1, 1, 1, 1, -1, -1, 0,0,0 };
    std::vector<int> temp_vector(a, a+sizeof(a)/sizeof(int));
    std::vector<std::vector<int>> result = CalculateSum(temp_vector);
    PrintResult(result);
    return 0;
}

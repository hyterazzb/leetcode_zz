//athor:zz
//data:20210225
/****************************************************************************************************************
****给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

***请你将两个数相加，并以相同形式返回一个表示和的链表。

***你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**********************************************************************************************************************/
// input   1 > 2 > 3 4 > 5 > 6
// output  5 > 7 > 9
#include <iostream>
#include <stdio.h>
#include <sys/time.h>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode *AddTwoNumber(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head = nullptr, *end = nullptr;
        while(l1 || l2)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            if(!head)
            {
                head = end = new ListNode(sum % 10);
            }   
            else
            {
                end->next = new ListNode(sum % 10);
                end = end->next;
            }
            carry = sum/10;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        } 
        if(carry > 0)
        {
            end->next = new ListNode(carry);
        }
        return head;
    }

    void TimeTIC(void)
    {
        struct timeval time_v = {0};
        gettimeofday(&time_v, NULL);
        __retina_tic = (double)(time_v.tv_sec * 1000 + time_v.tv_usec / 1000.0);
    }

    void TimeTOC(const char* func_name)
    {
        struct timeval time_v = {0};
        gettimeofday(&time_v, NULL);
        __retina_toc = (double)(time_v.tv_sec * 1000 + time_v.tv_usec / 1000.0);
        printf("%s take %.2f ms\n", func_name, __retina_toc - __retina_tic);
    }
private:
    double __retina_tic = 0.0;                     // 计时，滴
    double __retina_toc = 0.0;                     // 计时，
};

int main()
{
    Solution solution;
    solution.TimeTIC();
    ListNode *l1_head = nullptr, *l1_end = nullptr;
    l1_head = l1_end = new ListNode(2);
    l1_end->next = new ListNode(4);
    l1_end->next->next = new ListNode(3);
    ListNode *l2_head = nullptr, *l2_end = nullptr;
    l2_head = l2_end = new ListNode(5);
    l2_end->next = new ListNode(6);
    l2_end->next->next = new ListNode(4);
    ListNode *new_list = solution.AddTwoNumber(l1_head, l2_head);
    solution.TimeTOC("run");
    while(new_list)
    {
        printf("value:%d\n", new_list->val);
        new_list = new_list->next;
    }
    return 0;
}

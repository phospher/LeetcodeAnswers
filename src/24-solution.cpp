#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *l1 = head;
        ListNode *l2 = head == nullptr ? nullptr : l1->next;
        if (l2 == nullptr)
        {
            return l1;
        }

        l1->next = l2->next;
        l2->next = l1;
        ListNode *result = l2;

        l2 = l1->next;
        ListNode *l3 = l2 == nullptr ? nullptr : l2->next;
        while (l3 != nullptr)
        {
            l1->next = l3;
            l2->next = l3->next;
            l3->next = l2;

            l1 = l2;
            l2 = l1->next;
            l3 = l2 == nullptr ? nullptr : l2->next;
        }

        return result;
    }
};

ListNode *initListNodes(vector<int> values)
{
    ListNode *result = nullptr;
    ListNode *current = nullptr;
    for (int item : values)
    {
        if (result == nullptr)
        {
            result = new ListNode(item);
            current = result;
        }
        else
        {
            current->next = new ListNode(item);
            current = current->next;
        }
    }
    return result;
}

void printListNode(ListNode *result)
{
    ListNode *current = result;
    while (current != nullptr)
    {
        cout << current->val << ",";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    ListNode *input = initListNodes({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    Solution solution;
    ListNode *result = solution.swapPairs(input);
    printListNode(result);
}
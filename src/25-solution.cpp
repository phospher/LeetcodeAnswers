#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *groupPrev = new ListNode(-1, head);
        ListNode *result = head;
        ListNode *groupNext;
        bool isFirstGroup = true;
        while (groupPrev->next != nullptr)
        {
            ListNode *groupCurrent = groupPrev->next;
            stack<ListNode *> groupStack;
            while (groupCurrent != nullptr && groupStack.size() < k)
            {
                groupStack.push(groupCurrent);
                groupCurrent = groupCurrent->next;
            }
            if (groupStack.size() < k)
            {
                break;
            }

            ListNode *stackItem = groupStack.top();
            groupStack.pop();
            groupPrev->next = stackItem;
            groupNext = stackItem->next;

            ListNode *stackPrev = stackItem;
            while (!groupStack.empty())
            {
                stackItem = groupStack.top();
                groupStack.pop();
                stackPrev->next = stackItem;
                stackPrev = stackItem;
            }

            stackItem->next = groupNext;

            if (isFirstGroup)
            {
                result = groupPrev->next;
                isFirstGroup = false;
            }

            groupPrev = stackItem;
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
    ListNode *input = initListNodes({1, 2});
    Solution solution;
    ListNode *result = solution.reverseKGroup(input, 5);
    printListNode(result);
}
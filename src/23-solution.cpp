#include <vector>
#include <iostream>

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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = nullptr;
        for (ListNode *item : lists)
        {
            result = addNodeToHeadSortedList(result, item);
        }

        return result;
    }

    ListNode *addNodeToHeadSortedList(ListNode *sortedList, ListNode *list)
    {
        ListNode *listCurr = list;
        ListNode *result = sortedList;
        ListNode *sortedListCurr = sortedList;
        ListNode *sortedListPrev = nullptr;
        while (listCurr != nullptr)
        {
            ListNode *next = listCurr->next;
            listCurr->next = nullptr;
            if (sortedListCurr == nullptr)
            {
                result = listCurr;
                sortedListCurr = result;
            }
            else
            {
                while (sortedListCurr != nullptr)
                {
                    if (listCurr->val <= sortedListCurr->val)
                    {
                        if (sortedListPrev == nullptr)
                        {
                            result = listCurr;
                            result->next = sortedListCurr;
                            sortedListCurr = result;
                            sortedListPrev = nullptr;
                        }
                        else
                        {
                            ListNode *temp = listCurr;
                            listCurr->next = sortedListCurr;
                            sortedListPrev->next = temp;
                            sortedListCurr = temp;
                        }
                        break;
                    }
                    sortedListPrev = sortedListCurr;
                    if (sortedListCurr != nullptr)
                    {
                        sortedListCurr = sortedListCurr->next;
                    }
                }
                if (sortedListCurr == nullptr)
                {
                    sortedListCurr = listCurr;
                    sortedListPrev->next = sortedListCurr;
                }
            }
            listCurr = next;
        }
        return result;
    }
};

ListNode *initList(vector<int> values)
{
    ListNode *header = new ListNode(values[0]);
    ListNode *current = header;
    for (int i = 1; i < values.size(); i++)
    {
        ListNode *node = new ListNode(values[i]);
        current->next = node;
        current = node;
    }
    return header;
}

int main()
{
    vector<ListNode *> input;
    input.push_back(initList({1, 4, 5}));
    input.push_back(initList({2, 6}));
    input.push_back(initList({1, 3, 4}));

    Solution soluction;
    ListNode *result = soluction.mergeKLists(input);
    ListNode *current = result;
    while (current != nullptr)
    {
        cout << current->val << ",";
        current = current->next;
    }
    cout << endl;
    return 0;
}
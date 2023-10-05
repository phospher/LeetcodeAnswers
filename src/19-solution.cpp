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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> index;
        ListNode *current = head;
        while (current != nullptr)
        {
            index.push_back(current);
            current = current->next;
        }

        if (n >= index.size())
        {
            return head->next;
        }

        index[index.size() - n - 1]->next = n == 1 ? nullptr : index[index.size() - n + 1];

        return head;
    }
};

int main()
{
    return 0;
}
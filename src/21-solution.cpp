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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *current1 = list1;
        ListNode *current2 = list2;
        ListNode *result = nullptr;
        ListNode *currentResult;
        while (current1 != nullptr || current2 != nullptr)
        {
            int val1 = current1 == nullptr ? 1000 : current1->val;
            int val2 = current2 == nullptr ? 1000 : current2->val;

            ListNode *temp;
            if (val1 <= val2)
            {
                temp = new ListNode(val1);
                current1 = current1->next;
            }
            else
            {
                temp = new ListNode(val2);
                current2 = current2->next;
            }
            if (result == nullptr)
            {
                result = temp;
                currentResult = temp;
            }
            else
            {
                currentResult->next = temp;
                currentResult = temp;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
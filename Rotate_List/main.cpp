#include <iostream>
using namespace std;
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.
struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k) {

		if (!head)
				return head;
		int  length = 0;
		ListNode* cur = head;
		while(cur)
		{
				length++;
				cur = cur->next;
		}
		k = k % length;
		if (k == 0)
				return head;
		// find the n from last
		cur = head;
		int n = length - k;
		while(n > 1)
		{
				n--;
				cur = cur->next;
		}

		ListNode* result = cur->next;
		cur->next = NULL;
		cur = result;
		while(cur->next)
		{
				cur = cur->next;
		}
		cur->next = head;
		return result;
}

void printList(ListNode* head)
{
		while(head)
		{
				cout << head->val << "->";
				head = head->next;
		}

		cout << "NULL" << endl;
}

int main()
{

		ListNode* head = new ListNode(1);
		head->next = new ListNode(2);
		head->next->next = new ListNode(3);
		head->next->next->next = new ListNode(4);
		head->next->next->next->next = new ListNode(5);

		printList(head);

		printList(rotateRight(head,2));
		return 0;
}

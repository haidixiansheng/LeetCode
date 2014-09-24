#include <iostream>
#include <map>
using namespace std;
struct RandomListNode {
		int label;
		RandomListNode *next, *random;
		RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

typedef map<RandomListNode*, RandomListNode*> NodeMap;

RandomListNode* copyHelper(RandomListNode* head, NodeMap& nodeMap)
{
	if (!head) return head;
	RandomListNode* newHead ;
	if (nodeMap.find(head) == nodeMap.end())
	{
		newHead = new RandomListNode(head->label);
		nodeMap[head] = newHead;
		newHead->next = copyHelper(head->next, nodeMap);
		newHead->random = copyHelper(head->random, nodeMap);
	}
	else
			newHead = nodeMap[head];
	
	
	return newHead;
}

RandomListNode *copyRandomList(RandomListNode *head) {
	NodeMap nodeMap;

	return copyHelper(head, nodeMap);
}


int main()
{

		return 0;
}

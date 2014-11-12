#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTreeHelper(vector<int>& inorder, int startIn, int endIn, vector<int>& postorder, int startPost, int endPost)
{
	if(startPost > endPost)
		return NULL;
	TreeNode* head = new TreeNode(postorder[endPost]);
	int i;
	for (i = startIn; i < endIn; ++i)
	{
		if (inorder[i] == postorder[endPost])
			break;
	}

	head->left = buildTreeHelper(inorder, startIn, i-1, postorder, startPost, startPost + i-1 - startIn);
	head->right =  buildTreeHelper(inorder, i + 1, endIn, postorder, startPost + i - startIn, endPost -1);

	return head;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

	return buildTreeHelper(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
}



int main ()
{
	
	return 0;
}

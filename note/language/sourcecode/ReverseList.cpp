#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): next(NULL) { }
};

ListNode* genList() {
	ListNode *root = new ListNode();
	root->val = 0;
	ListNode *pre = root;
	for (int i = 1; i < 10; ++i) {
		ListNode *node = new ListNode();
		node->val = i;
		pre->next = node;
		pre = node;
	}
	return root;
}

void traverseList(ListNode *root) {
	while (root != NULL) {
		std::cout << root->val << "->";
		root = root->next;
	}
	std::cout << "NULL" << std::endl;
}

void reverseList(ListNode *&root) {
	ListNode *preNode = NULL;
	ListNode *node = root;
	while (node != NULL) {
		ListNode *next = node->next;
		node->next = preNode;
		preNode = node;
		node = next;
	}
	root = preNode;
}

int main(int argc, char *argv[]) {
	ListNode* root = genList();
	traverseList(root);
	reverseList(root);
	traverseList(root);
	return 0;
}


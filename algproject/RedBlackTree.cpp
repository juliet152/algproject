#include "RedBlackTree.h"
#include <stdio.h>
#include <math.h>

const int MIN_INT = -MAX_INT;

RedBlackTreeNode::RedBlackTreeNode(){
};

RedBlackTreeNode::RedBlackTreeNode(RedBlackEntry * newEntry)
	: storedEntry(newEntry), key(newEntry->GetKey()) {
};

RedBlackTreeNode::~RedBlackTreeNode(){
};

RedBlackEntry * RedBlackTreeNode::GetEntry() const { return storedEntry; }

RedBlackEntry::RedBlackEntry(){
};
RedBlackEntry::~RedBlackEntry(){
};
void RedBlackEntry::Print() const {
	cout << "No Print Method defined. Using Default: " << GetKey() << endl;
}

RedBlackTree::RedBlackTree()
{
	nil = new RedBlackTreeNode;
	nil->left = nil->right = nil->parent = nil;
	nil->red = 0;
	nil->key = MIN_INT;
	nil->storedEntry = NULL;

	root = new RedBlackTreeNode;
	root->parent = root->left = root->right = nil;
	root->key = MAX_INT;
	root->red = 0;
	root->storedEntry = NULL;
}

void RedBlackTree::LeftRotate(RedBlackTreeNode* x) {
	RedBlackTreeNode* y;

	y = x->right;
	x->right = y->left;

	if (y->left != nil) y->left->parent = x;

	y->parent = x->parent;

	if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;

}

void RedBlackTree::RightRotate(RedBlackTreeNode* y) {
	RedBlackTreeNode* x;

	x = y->left;
	y->left = x->right;

	if (nil != x->right)  x->right->parent = y; 

	x->parent = y->parent;
	if (y == y->parent->left) {
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	x->right = y;
	y->parent = x;

}

void RedBlackTree::TreeInsertHelp(RedBlackTreeNode* z) {
	/*  This function should only be called by RedBlackTree::Insert */
	RedBlackTreeNode* x;
	RedBlackTreeNode* y;

	z->left = z->right = nil;
	y = root;
	x = root->left;
	while (x != nil) {
		y = x;
		if (x->key > z->key) {
			x = x->left;
		}
		else { /* x->key <= z->key */
			x = x->right;
		}
	}
	z->parent = y;
	if ((y == root) ||
		(y->key > z->key)) {
		y->left = z;
	}
	else {
		y->right = z;
	}

}

RedBlackTreeNode * RedBlackTree::Insert(RedBlackEntry * newEntry)
{
	RedBlackTreeNode * y;
	RedBlackTreeNode * x;
	RedBlackTreeNode * newNode;

	x = new RedBlackTreeNode(newEntry);
	TreeInsertHelp(x);
	newNode = x;
	x->red = 1;
	while (x->parent->red) { /* use sentinel instead of checking for root */
		if (x->parent == x->parent->parent->left) {
			y = x->parent->parent->right;
			if (y->red) {
				x->parent->red = 0;
				y->red = 0;
				x->parent->parent->red = 1;
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->right) {
					x = x->parent;
					LeftRotate(x);
				}
				x->parent->red = 0;
				x->parent->parent->red = 1;
				RightRotate(x->parent->parent);
			}
		}
		else { /* case for x->parent == x->parent->parent->right */
			/* this part is just like the section above with */
			/* left and right interchanged */
			y = x->parent->parent->left;
			if (y->red) {
				x->parent->red = 0;
				y->red = 0;
				x->parent->parent->red = 1;
				x = x->parent->parent;
			}
			else {
				if (x == x->parent->left) {
					x = x->parent;
					RightRotate(x);
				}
				x->parent->red = 0;
				x->parent->parent->red = 1;
				LeftRotate(x->parent->parent);
			}
		}
	}
	root->left->red = 0;
	return(newNode);

}

RedBlackTreeNode * RedBlackTree::GetSuccessorOf(RedBlackTreeNode * x) const
{
	RedBlackTreeNode* y;

	if (nil != (y = x->right)) { /* assignment to y is intentional */
		while (y->left != nil) { /* returns the minium of the right subtree of x */
			y = y->left;
		}
		return(y);
	}
	else {
		y = x->parent;
		while (x == y->right) { /* sentinel used instead of checking for nil */
			x = y;
			y = y->parent;
		}
		if (y == root) return(nil);
		return(y);
	}
}

RedBlackTreeNode * RedBlackTree::GetPredecessorOf(RedBlackTreeNode * x) const {
	RedBlackTreeNode* y;

	if (nil != (y = x->left)) { /* assignment to y is intentional */
		while (y->right != nil) { /* returns the maximum of the left subtree of x */
			y = y->right;
		}
		return(y);
	}
	else {
		y = x->parent;
		while (x == y->left) {
			if (y == root) return(nil);
			x = y;
			y = y->parent;
		}
		return(y);
	}
}

void RedBlackTreeNode::Print(RedBlackTreeNode * nil,
	RedBlackTreeNode * root) const {
	storedEntry->Print();
	printf(", key=%i ", key);
	printf("  l->key=");
	if (left == nil) printf("NULL"); else printf("%i", left->key);
	printf("  r->key=");
	if (right == nil) printf("NULL"); else printf("%i", right->key);
	printf("  p->key=");
	if (parent == root) printf("NULL"); else printf("%i", parent->key);
	printf("  red=%i\n", red);
}

void RedBlackTree::TreePrintHelper(RedBlackTreeNode* x) const {

	if (x != nil) {
		TreePrintHelper(x->left);
		x->Print(nil, root);
		TreePrintHelper(x->right);
	}
}

RedBlackTree::~RedBlackTree() {
	RedBlackTreeNode * x = root->left;
	stack<RedBlackTreeNode *> stuffToFree;

	if (x != nil) {
		if (x->left != nil) {
			stuffToFree.push(x->left);
		}
		if (x->right != nil) {
			stuffToFree.push(x->right);
		}
		// delete x->storedEntry;
		delete x;
		while (!stuffToFree.empty()) {
			x = stuffToFree.top();
			stuffToFree.pop();
			if (x->left != nil) {
				stuffToFree.push(x->left);
			}
			if (x->right != nil) {
				stuffToFree.push(x->right);
			}
			// delete x->storedEntry;
			delete x;
		}
	}
	delete nil;
	delete root;
}

void RedBlackTree::Print() const {
	TreePrintHelper(root->left);
}

void RedBlackTree::DeleteFixUp(RedBlackTreeNode* x) {
	RedBlackTreeNode * w;
	RedBlackTreeNode * rootLeft = root->left;

	while ((!x->red) && (rootLeft != x)) {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->red) {
				w->red = 0;
				x->parent->red = 1;
				LeftRotate(x->parent);
				w = x->parent->right;
			}
			if ((!w->right->red) && (!w->left->red)) {
				w->red = 1;
				x = x->parent;
			}
			else {
				if (!w->right->red) {
					w->left->red = 0;
					w->red = 1;
					RightRotate(w);
					w = x->parent->right;
				}
				w->red = x->parent->red;
				x->parent->red = 0;
				w->right->red = 0;
				LeftRotate(x->parent);
				x = rootLeft; /* this is to exit while loop */
			}
		}
		else { /* the code below is has left and right switched from above */
			w = x->parent->left;
			if (w->red) {
				w->red = 0;
				x->parent->red = 1;
				RightRotate(x->parent);
				w = x->parent->left;
			}
			if ((!w->right->red) && (!w->left->red)) {
				w->red = 1;
				x = x->parent;
			}
			else {
				if (!w->left->red) {
					w->right->red = 0;
					w->red = 1;
					LeftRotate(w);
					w = x->parent->left;
				}
				w->red = x->parent->red;
				x->parent->red = 0;
				w->left->red = 0;
				RightRotate(x->parent);
				x = rootLeft; /* this is to exit while loop */
			}
		}
	}
	x->red = 0;
}

RedBlackEntry * RedBlackTree::DeleteNode(RedBlackTreeNode * z){
	RedBlackTreeNode* y;
	RedBlackTreeNode* x;
	RedBlackEntry * returnValue = z->storedEntry;

	y = ((z->left == nil) || (z->right == nil)) ? z : GetSuccessorOf(z);
	x = (y->left == nil) ? y->right : y->left;
	if (root == (x->parent = y->parent)) { /* assignment of y->p to x->p is intentional */
		root->left = x;
	}
	else {
		if (y == y->parent->left) {
			y->parent->left = x;
		}
		else {
			y->parent->right = x;
		}
	}
	if (y != z) { /* y should not be nil in this case */

		/* y is the node to splice out and x is its child */

		y->left = z->left;
		y->right = z->right;
		y->parent = z->parent;
		z->left->parent = z->right->parent = y;
		if (z == z->parent->left) {
			z->parent->left = y;
		}
		else {
			z->parent->right = y;
		}
		if (!(y->red)) {
			y->red = z->red;
			DeleteFixUp(x);
		}
		else
			y->red = z->red;
		delete z;
	}
	else {
		if (!(y->red)) DeleteFixUp(x);
		delete y;
	}
	return returnValue;
}

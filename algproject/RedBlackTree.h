#pragma once

#include <math.h>
#include <limits.h>
#include <iostream>
#include <stack>

using namespace std;

#ifndef MAX_INT
#define MAX_INT INT_MAX // some architechturs define INT_MAX not MAX_INT
#endif

class RedBlackEntry {
public:
	RedBlackEntry();
	virtual ~RedBlackEntry();
	virtual int GetKey() const = 0;
	virtual void Print() const;
};

class RedBlackTreeNode {
	friend class RedBlackTree;
public:
	void Print(RedBlackTreeNode*,
		RedBlackTreeNode*) const;
	RedBlackTreeNode();
	RedBlackTreeNode(RedBlackEntry *);
	RedBlackEntry * GetEntry() const;
	~RedBlackTreeNode();
	RedBlackEntry * storedEntry;
	int key;
	int red; /* if red=0 then the node is black */
	RedBlackTreeNode * left;
	RedBlackTreeNode * right;
	RedBlackTreeNode * parent;
};

class RedBlackTree {
public:
	RedBlackTree();
	~RedBlackTree();
	void Print() const;
	RedBlackEntry * DeleteNode(RedBlackTreeNode *);
	RedBlackTreeNode * Insert(RedBlackEntry *);
	RedBlackTreeNode * GetPredecessorOf(RedBlackTreeNode *) const;
	RedBlackTreeNode * GetSuccessorOf(RedBlackTreeNode *) const;
	RedBlackTreeNode * Search(int key);
	RedBlackTreeNode * GetRoot() { return root; }
	void CheckAssumptions() const;
protected:
	RedBlackTreeNode * root;
	RedBlackTreeNode * nil;
	void LeftRotate(RedBlackTreeNode *);
	void RightRotate(RedBlackTreeNode *);
	void TreeInsertHelp(RedBlackTreeNode *);
	void TreePrintHelper(RedBlackTreeNode *) const;
	void FixUpMaxHigh(RedBlackTreeNode *);
	void DeleteFixUp(RedBlackTreeNode *);
};
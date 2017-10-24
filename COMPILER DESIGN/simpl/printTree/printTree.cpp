#include "printTree.h"
#include <iostream.h>

// a function to print out a syntax tree
void treenode::printTree(treenode *t){
	cout << "(";
	if(t != NULL){
		cout << t->name << " " << t->type;
		if(t->arity != Nullary_){
			cout << " ";
			printTree(t->children[0]);
			if(t->arity != Unary_){
				cout << " ";
				printTree(t->children[1]);
				if(t->arity != Binary_){
					cout << " ";
					printTree(t->children[2]);
					if(t->arity != Trinary_){
						cout << " ";
						printTree(t->children[3]);
					} // end of quatrary
				} // end of trinary
			} // end of binary
		} // end of unary
	} // end of nullary
	cout << ")";
} // end of printTree

// constructor
treenode::treenode(int t, char *n, int ln){
	type = t; name = n; lineNo = ln, arity = Nullary_;
} // end of constructor

// add a child to the node
void treenode::addChild(treenode *x){
	if(arity < maxArity_)
		children[arity++] = x;
	else abort();
} // end of addChild

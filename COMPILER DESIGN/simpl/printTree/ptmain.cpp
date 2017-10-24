#include "printTree.h"
#include <stdlib.h>

int main(){
	treenode *t0, *t1, *t2, *t3, *t4;
	t0 = new treenode(0, "zero", 0);
	t1 = new treenode(1, "one", 0);
	t2 = new treenode(2, "two", 0);
	t3 = new treenode(3, "three", 0);
	t4 = new treenode(4, "four", 0);
	t1->addChild(t0);
	t2->addChild(t1); t2->addChild(NULL);
	t3->addChild(t2); t3->addChild(t1); t3->addChild(t0);
	t4->addChild(t3); t4->addChild(t2); t4->addChild(t3); t4->addChild(t0);
	t4->printTree(t4);
}

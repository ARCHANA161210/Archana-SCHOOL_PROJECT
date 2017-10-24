// test program for SymTab
#include "SymTab.h"
#include <iostream.h>

struct node {int x; double y;};

void main(void){
	SymTab st(4);
	node john = {0, 0.0};
	node paul = {1, 1.0};
	node george = {2, 2.0};
	node ringo = {3, 3.0};
	st.add("john", &john);
	st.add("paul", &paul);
	st.add("george", &george);
	st.add("ringo", &ringo);
	cout << ((node*)(st.get("george")))->x << endl;
	cout << ((node*)(st.get("paul")))->y << endl;
	st.add("oco", &john);
	cout << ((node*)(st.get("john")))->x << endl;
} // end of main program

#include <iostream>
using namespace std;

struct control
{
 int consuption_memory;
 int process_id;
 string process_status;
 	
};
struct process
{
	int process_number;
	int processing_time;
	 string process_name;
     control PCB  ;
     
};

struct node{
	process info;
	node *next;
};

process list[11];

node *queueFront= NULL;
node *queueRear= NULL;
//--------------------------------------------------------------------------------------------------------------------------------------


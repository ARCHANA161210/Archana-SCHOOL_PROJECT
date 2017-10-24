#include <iostream>
using namespace std;

/*void initializeStack() 
{
     node *temp;
	 while(queueFront !=NULL)
	 {
	 	temp=queueFront;
	 	queueFront=queueFront->next;
	 	delete temp;
	 }
	 queueRear=NULL;
}*/
//////////////////////////////
bool isEmptyQueue() // check if queue is empty
{
     return (queueFront==NULL);
}
/////////////////////////////
bool isFullQueue() //check if queue is full
{
     return false;
}
/////////////////////////////
void ready_q(process newItem)//insert your process in queue
{
     node* newNode;
     newNode= new node;
     newNode->info=newItem;
     newNode->next=NULL;
     if(queueFront == NULL)
     {
     	queueFront=newNode;
     	queueRear= newNode;
     }
     else
     {
     	queueRear->next= newNode;
     	queueRear= queueRear->next;
     }
}
/////////////////////////////  
process front()// get front item from the queue
{
    
    return queueFront->info;
}
/////////////////////////////
process back()
{
    
    return queueRear->info;
}
/////////////////////////
void deleteQueue()  // delete the first element from the queue
{
	node *temp;
     if(!isEmptyQueue())
     {
     	temp=queueFront;
     	queueFront=queueFront->next;
     	delete temp;
     	if(queueFront == NULL)
     	queueRear=NULL;
	 }
     else
     cout<<"Cannot remove from an empty queue\n";
}
void print()   // print the queue
{
    node *p = new node;
    p = queueFront;
  if(queueFront == NULL)
    {

        cout<<"\nyour all processes are done this is your last process....\n";
    }
	else
	{

        while(p!=NULL)
		{

            cout<<p->info.process_number<<" ";

            p = p->next;

        }

    }

}


void sort(node *queueFront)//function to sort the details by processing time
{

	node *i,*j;
	i=queueFront;
	while(i!=NULL)
	{
		j=i->next;
		while(j!=NULL)
		{
			if(i->info.processing_time > j->info.processing_time)
			{
				  int temp=i->info.processing_time;
				  i->info.processing_time=j->info.processing_time;
				  j->info.processing_time=temp;

				 string temp3=i->info.process_name;
				  i->info.process_name=j->info.process_name;
				  j->info.process_name=temp3;

				  int temp1=i->info.process_number;
				  i->info.process_number=j->info.process_number;
				  j->info.process_number=temp1;

				 control temp2=i->info.PCB;
				  i->info.PCB=j->info.PCB;
				  j->info.PCB=temp2;
			}
			j=j->next;
		}
			i=i->next;
	}

}//end of sort by processing time function.


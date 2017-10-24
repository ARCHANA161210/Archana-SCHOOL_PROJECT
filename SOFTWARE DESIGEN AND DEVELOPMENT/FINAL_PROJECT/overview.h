void HonorStudent(node *head)//function to count the number of students scored gpa above 3.6
{
	node *current=head;
	cout<<"********HONOR STUDENTS********"<<endl;
	int count=0;
	cout<<"the names of the HonorStudent list="<<endl;
	FindGPA(head);
	while(current->link!=NULL)
	{
		if(current->data.totalgpa>=3.6)
		{
			count++;
			cout<<current->data.FirstName<<" "<<current->data.lastName<<endl;

		}
		current=current->link;
	}
	cout<<"the HonorStudent list count="<<count<<endl;


}//end of function.

void WarnStudent(node*head)//function to warn the student who got gpa less than 2.5
{

	node*current=head;
	cout<<"*****WARN STUDENTS*****"<<endl;
	int count=0;
	cout<<"The names of the warn students are="<<endl;

	FindGPA(head);
	while(current->link!=NULL)
	{
		if(current->data.totalgpa<=2.5 && current->data.totalgpa>2.0)
		{

			count++;
			cout<<current->data.FirstName<<" "<<current->data.lastName<<endl;;

		}
		current=current->link;
	}
	cout<<"total warn students  count="<<count<<endl;

}//end of function
void FailStudent(node *head)//function to count the number of failures and prints their name
{
	node*current=head;
	cout<<"****FAIL STUDENTS*****"<<endl;
	int count=0;
	cout<<" Names of the fail students are="<<endl;

	FindGPA(head);
	while(current->link!=NULL)
	{
		if(current->data.totalgpa<=2.0)
		{
			count++;
			cout<<current->data.FirstName<<" "<<current->data.lastName<<endl;;
		}
		current=current->link;
	}
	cout<<"Total fail students count="<<count<<endl;

}//end of function.


void countstudent(node *head) //print student name who r taking COSC504
{
	node *q;
	courseType *p;
	q=head;
	cout<<"student name who are taking cos504 are"<<endl;

	int i=0;
	while(q!=NULL)
	{
		p=q->courseLink;
		while(p!=NULL)
		{
			if(p->courseName=="COSC504")
			{
				cout<<q->data.lastName<<" "<<q->data.FirstName<<endl;
				i++;
			}
			p=p->link;

		}
		q=q->link;
	}

cout<<"total students are who taking cos504 are="<<i<<endl;
}//end function


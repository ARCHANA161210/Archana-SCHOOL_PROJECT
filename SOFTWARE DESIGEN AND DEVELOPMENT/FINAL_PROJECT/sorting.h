/* this header file contains  sorting functions  by first name, GPA, and ID.*/



void sortBylastname(node *head) //function to print the student details sorted by last name.
{
	node *i,*j;
	i=head;
student temp;
	while(i!=NULL)
	{
		j=i->link;
		while(j!=NULL)
		{
			if(i->data.lastName>j->data.lastName)//comparing which name is smaller by ascii
			{
				                   temp=i->data;
								  i->data=j->data;
								  j->data=temp;


								  courseType *temp2=i->courseLink;
								  i->courseLink=j->courseLink;
								  j->courseLink=temp2;

			}
			j=j->link;
		}
	    i=i->link;
	}

}//end of print sort by last name function...


void sortByfirstname(node *head)//function to sort the student details by headname.
{

	node *i,*j;
	i=head;
	student temp;
	while(i!=NULL)
		{
			j=i->link;
			while(j!=NULL)
			{
			if(i->data.FirstName > j->data.FirstName)
			{
				                  temp=i->data;
								  i->data=j->data;
								  j->data=temp;


								  courseType *temp2=i->courseLink;
								  i->courseLink=j->courseLink;
								  j->courseLink=temp2;

			}
			j=j->link;
			}
			i=i->link;
		}

}//end of sort by head name function.

void sortByid(node *head)//function to sort the details by i.d
{

	node *i,*j;
	i=head;
	student temp;
	while(i!=NULL)
	{
		j=i->link;
		while(j!=NULL)
		{
			if(i->data.id >j->data.id)
			{
				 temp=i->data;
				  i->data=j->data;
				  j->data=temp;


				  courseType *temp2=i->courseLink;
				  i->courseLink=j->courseLink;
				  j->courseLink=temp2;

			}
			j=j->link;
		}
			i=i->link;
	}

}//end of sort by id function.
void sortBygpa(node *head)//function to sort the student details by gpa
{
   node *i,*j;
	i=head;
	student temp;
	while(i!=NULL)
	{
		j=i->link;
		while(j!=NULL)
		{
		if(i->data.totalgpa < j->data.totalgpa)
			{
			                  temp=i->data;
							  i->data=j->data;
							  j->data=temp;


							  courseType *temp2=i->courseLink;
							  i->courseLink=j->courseLink;
							  j->courseLink=temp2;
            }
		j=j->link;
		}
		i=i->link;
	}
}//end of function


void sortall(node *head) //function to sort the student details by headname,lastname,id,gpa..
{
	cout<<"Enter your choice of sort"<<endl;
	cout<<"1:Sort by last name"<<endl;
	cout<<"2:Sort by first name"<<endl;
	cout<<"3:Sort by i.d"<<endl;
	cout<<"4:Sort by total gpa"<<endl;
	cout<<"-1:To quit"<<endl;
	cout<<"Enter your choice for sort"<<endl;
	int choice;
	cin>>choice;
	FindGPA(head);
	while((choice<=4)&&(choice!=-1))
	{
	switch(choice)
	{
	case 1:
		sortBylastname(head);
		cout<<"***************************sorting by last name of the student************************************\n";
		print(head,true);
		break;
	case 2:
		sortByfirstname(head);
		cout<<"***************************sorting by head name of the student************************************\n";

		print(head,true);
		break;
	case 3:
		sortByid(head);
		cout<<"***************************sorting by id  of the student************************************\n";

		print(head,true);
		break;
	case 4:
		sortBygpa(head);
		cout<<"***************************sorting by gpa of the student************************************\n";

		print(head,true);
		break;

	}
	cout<<"Enter your choice for sort"<<endl;
		cin>>choice;
	}
}//end of function


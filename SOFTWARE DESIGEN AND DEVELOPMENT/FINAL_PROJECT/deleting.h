
void deletestudentById(node *head) //function to delete student from the class..
{
	node *current,*temp;
	current=head;

	int iD1;
	bool found=false;
	cout<<"Enter a students id whom you want to delete"<<endl;
	string newId;
	cin>>newId;
	getNumericType("ID",&newId);
		iD1=atoi(newId.c_str());
	bool deleteflag=true;
	temp=current;
	while(deleteflag){
	while(current!=NULL)
	{
		if(iD1==current->data.id)
		{
			found=true;


			if(temp->link==current->link){
				temp=current->link;
				current->link=temp;

				}else{
				temp->link=current->link;
				}

		delete current;;
		break;
		}
		temp=current;
			current=current->link;
	}//end of while loop.

	if(found==false)
	{
       cout<<"The student is not registered"<<endl;
	   		cout<<"Enter another id"<<endl;
	       cin>>newId;
	       getNumericType("ID",&newId);
		iD1=atoi(newId.c_str());

	deleteflag=true;
	current=head;
	}

	else{

		cout<<"The count of the student after deleting="<<count(head)<<endl;
		print(head,false);
		deleteflag=false;
	}
	}//end of outer while loop.

}//end of delete student function.


void deletestudentByName(node *head) //function to delete student from the class..
{
	node *current,*temp;
	current=head;

	string fName,lName;
	bool found=false;
	cout<<"Enter a students first name whome you want to delete"<<endl;
	cin>>fName;
	getStringType(&fName);
	cout<<"Enter a students last name  whome you want to delete"<<endl;
	cin>>lName;
	getStringType(&lName);
	temp=current;
	bool deleteflag=true;
	while(deleteflag){
	while(current!=NULL)
	{
		if((fName==current->data.FirstName)&&(lName==current->data.lastName))
		{
			found=true;
			if(temp->link==current->link){//for the delete head node
				temp=current->link;
				current->link=temp;
				head=temp;
				}else{//deletion of other nodes
				temp->link=current->link;
				}


		delete current;;
		break;
		}
		temp=current;
			current=current->link;
	}//end of while loop.

	if(found==false)
	{
       cout<<"The student is not registered"<<endl;
	   		cout<<"Enter another students first name "<<endl;
         cin>>fName;
		 getStringType(&fName);
		 cout<<"Enter another students last name "<<endl;
		 cin>>lName;
		 getStringType(&lName);
	deleteflag=true;
	current=head;
	}

	else{

		cout<<"The count of the student after deleting="<<count(head)<<endl;
		print(head,false);
		deleteflag=false;
	}
	}//end of outer while loop.

}//end of function






void deltecourse(node *head)//function to delete a course of student by asking the i.d
{
	node *current=head;
	courseType *p,*temp;
	int idnum;
	string course;
	bool found1=false;
	bool found2=false;
	cout<<"Enter student i.d that you want to delete a course"<<endl;
	string newId;
	cin>>newId;
	getNumericType("ID",&newId);
		idnum=atoi(newId.c_str());

	while(!found1){
	while(current!=NULL)
	{
		if(idnum==current->data.id)
		{
			found1=true;
			cout<<"enter the course to be deleted"<<endl;

			cin>>course;
		getCourse(&course);
			p=current->courseLink;
			temp=p;
		bool courseIterate=true;
		while(courseIterate){
			while(p!=NULL){
			if(course==p->courseName)
			{
				found2=true;
				if(temp->link==p->link){
				temp=p->link;
				current->courseLink=temp;
				}else{
				temp->link=p->link;
				}
				courseIterate=false;
               delete p;
			   break;
			}

			temp=p;
			p=p->link;
			}
        if(found2==false){
			cout<<"the student is not registered in that course"<<endl;
			cout<<"enter another course"<<endl;
			cin>>course;
		getCourse(&course);
			p=current->courseLink;
			temp=p;
			courseIterate=true;
		}
}

		}
		current=current->link;
	}
		if(found1==false)
		{
			cout<<"the student is not registered"<<endl;
			cout<<"Enter another id"<<endl;
			cin>>newId;
	getNumericType("ID",&newId);
		idnum=atoi(newId.c_str());
			current=head;

		}
		if((found1==true)&&(found2==true)){
			print(head,false);

	}
	}

}//end of the function...



void deltecourseByName(node *head)//function to delete a course of student by asking the i.d
{
	node *current=head;
	courseType *p,*temp;
	string fName;
	string lName;
	string course;
	bool found1=false;
	bool found2=false;
	cout<<"Enter student First Name, Last Name that you want to delete a course"<<endl;
	cin>>fName;
	getStringType(&fName);
	cin>>lName;
	getStringType(&lName);
	while(!found1){
	while(current!=NULL)
	{
		if(fName==current->data.FirstName && lName==current->data.lastName)
		{
			found1=true;
			cout<<"enter the course to be deleted"<<endl;

			cin>>course;
		getCourse(&course);


			p=current->courseLink;
			temp=p;
		bool courseIterate=true;
		while(courseIterate){
			while(p!=NULL){
			if(course==p->courseName)
			{
				found2=true;
				if(temp->link==p->link){
				temp=p->link;
				current->courseLink=temp;
				}else{
				temp->link=p->link;
				}
				courseIterate=false;
               delete p;
			   break;
			}

			temp=p;
			p=p->link;
			}
        if(found2==false){
			cout<<"the student not registered in that course"<<endl;
			cout<<"enter another course"<<endl;

			cin>>course;
		getCourse(&course);
			p=current->courseLink;
			temp=p;
			courseIterate=true;
		}
}

		}
		current=current->link;
	}
		if(found1==false)
		{
			cout<<"the student is not registered"<<endl;
			cout<<"Enter another students First Name and Last Name"<<endl;
			cin>>fName;
			getStringType(&fName);
			cin>>lName;
			getStringType(&lName);

			current=head;

		}
		if((found1==true)&&(found2==true)){
			print(head,false);

	}
	}

}//end of the function...


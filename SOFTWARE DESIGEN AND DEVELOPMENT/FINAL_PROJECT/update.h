
void modify(node *head) //function to update the students data..
{
	node *current=head;
	courseType *p;
	int iD;
	bool found1=false;
	bool found2=false;
	bool modifyflag=true;
	string course,grade1;
	string 	newId;
	cout<<"enter an i.d of student that you want to update="<<endl;

	cin>>newId;
	getNumericType("ID",&newId);
		iD=atoi(newId.c_str());

	while(modifyflag){
	while(current!=NULL)
	{
		if(iD==current->data.id)
		{   found1=true;
		   p=current->courseLink;
			cout<<"enter the course that you want to update the grade="<<endl;
			cin>>course;
			getCourse(&course);
        bool courseIterateFlag=true;
		while(courseIterateFlag){
			while(p!=NULL)
		 {
			 if(course==p->courseName)
			 {
				 found2=true;
				 cout<<"enter the grade you want to change as="<<endl;
				 cin>>grade1;
				 getStringTypeWithLength("Grade",&grade1);
				 p->grade=grade1;

				 FindGPA(head);
				 courseIterateFlag=false;
			 }
			 p=p->link;
			}
		  if(found2==false)
			 {
				 cout<<"the student not registered in to that course"<<endl;
				 cout<<"Enter another course"<<endl;
				 cin>>course;
				 getCourse(&course);
				 p=current->courseLink;
				 courseIterateFlag=true;
			 }

		}
		}//if loop closed.
		current=current->link;

	}//outer while closed.
	if(found1==false)
		 {
      cout<<"the student is not registered"<<endl;
	  cout<<"Enter another i.d"<<endl;
	  	  cin>>newId;
	getNumericType("ID",&newId);
		iD=atoi(newId.c_str());

	  current=head;
	  modifyflag=true;
		 }
	else{
		modifyflag=false;
	}

	}
	print(head,true);

}//function end.


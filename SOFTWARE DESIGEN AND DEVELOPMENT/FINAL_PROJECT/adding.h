
void addcourse(node *&head) //function to add new course to an existed student..
{
	courseType *newcourse,*p,*q;
	node *current;
	int iD;
	string newId;
	bool found=false;
	current=head;
    cout<<"Enter a students i.d to whom you want add course"<<endl;
    cin>>newId;
	getNumericType("ID",&newId);
		iD=atoi(newId.c_str());

	bool iterateFlag=true;
	while(iterateFlag)//loop to check whether the i.d is there or not
	{
	while(current!=NULL)
	{
		if(iD==current->data.id)
		{
			bool courseFlag=true;
			do{
			found=true;
			p=current->courseLink;
			newcourse=new courseType;
			cout<<"Enter course name that you want to add"<<endl;
			string course;
			cin>>course;
		getCourse(&course);
		newcourse->courseName=course;

		   while(p!=NULL)
		   {
				 if(p->courseName==newcourse->courseName)//loop to check the entered course is already registered or not
					{
						cout<<"Student already registered in that course enter another course"<<endl;
						string anotherCourse;
			cin>>anotherCourse;
		getCourse(&anotherCourse);
		newcourse->courseName=anotherCourse;
						p=current->courseLink;
					 }else{
						 if( p->link==NULL){
				    q=p;
						 }
						  p=p->link;
				    }

		   }
		   cout<<"Enter credits for the new course"<<endl;
		   string credit;
		   cin>>credit;
			getNumericType("CREDIT",&credit);
			newcourse->credit=atoi(credit.c_str());

		   cout<<"Enter grade for the new course"<<endl;
		   string grade;
		cin>>grade;
		getStringTypeWithLength("Grade",&grade);
		newcourse->grade=grade;


	  q->link=newcourse;
	  newcourse->link=NULL;


	  cout<<"Do you want add another course? Y/N"<<endl;
	  cout<<"'y' for continue and 'n' for quit"<<endl;
	string cont;
	cin>>cont;
	if(cont=="Y" || cont=="y"){
		  courseFlag=true;
	  }else{
		  courseFlag=false;
	       }
			}while(courseFlag);

		}
		current=current->link;
	}
	if(found==false)
	{
    cout<<"The student is not registered"<<endl;
    cout<<"Enter another id"<<endl;
	string newId;
	cin>>newId;
	getNumericType("ID",&newId);
		iD=atoi(newId.c_str());
	iterateFlag=true;
	current=head;
	}
	else
	{
	print(head,false);
	iterateFlag=false;
	}
	}
}//end of add course function...

void addcourseByName(node *&head) //function to add new course to an exsisted student..
{
	courseType *newcourse,*p,*q;
	node *current;
	bool found=false;
	current=head;
    cout<<"Enter a students First Name and Last Name to whome you want add course"<<endl;
    string fName, lName;
	cin>>fName;

getStringType(&fName);
	cin>>lName;
	getStringType(&lName);

	bool iterateFlag=true;
	while(iterateFlag){    //loop to check whether the i.d is there or not
	while(current!=NULL)
	{
		if(fName==current->data.FirstName && lName==current->data.lastName)
		{
			bool courseFlag=true;
			do{
			found=true;
			p=current->courseLink;
			newcourse=new courseType;
			cout<<"Enter course name that you want to add"<<endl;
			string course;
			cin>>course;
						getCourse(&course);
		              newcourse->courseName=course;
		   while(p!=NULL)
		   {
				 if(p->courseName==newcourse->courseName)//loop to check the entered course is already registered or not
					{
						cout<<"Student already registered in that course enter another course"<<endl;
						string anothrCourse;
						getCourse(&anothrCourse);
		              newcourse->courseName=anothrCourse;
						p=current->courseLink;
					 }else{
						 if( p->link==NULL){
				    q=p;
						 }
						  p=p->link;
				    }

		   }
		   cout<<"Enter credits for the new course"<<endl;
		   string credit;
		cin>>credit;
			getNumericType("CREDIT",&credit);
			newcourse->credit=atoi(credit.c_str());

		   cout<<"Enter grade for the new course"<<endl;
		   string grade;
		cin>>grade;
		getStringTypeWithLength("Grade",&grade);
		newcourse->grade=grade;

	  q->link=newcourse;
	  newcourse->link=NULL;


	  cout<<"Do you want add another course? Y/N"<<endl;
	  cout<<"y for yes && n for no"<<endl;
	string cont;
	cin>>cont;
	if(cont=="Y" || cont=="y"){
		  courseFlag=true;
	  }else{
		  courseFlag=false;
	       }
			}while(courseFlag);

		}
		current=current->link;
	}
	if(found==false)
	{
    cout<<"The student is not registered"<<endl;
    cout<<"Enter another student First Name and Last Name"<<endl;

    cin>>fName;
	getStringType(&fName);
	cin>>lName;
	getStringType(&lName);

	iterateFlag=true;
	current=head;
	}
	else
	{
	print(head,false);
	iterateFlag=false;
	}
	}
}//end of add course function...


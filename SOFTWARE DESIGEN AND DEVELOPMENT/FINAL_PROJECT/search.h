
void SearchById(node *head) //function to SearchById a student by i.d
{
	node *current=head;
	bool found=false;
	bool SearchByIdflag=true;
	double totalgpa1=0;
	double totalcredit=0;
	int idno;
	cout<<"Enter an i.d of a student whom you want to SearchById"<<endl;
	cin>>idno;
	while(SearchByIdflag){
	while(current!=NULL)
	{
       if(idno==current->data.id)
	   {
		   found=true;
			   cout<<"The first name="<<current->data.FirstName<<endl;;
			   cout<<"The last name="<<current->data.lastName<<endl;
			   courseType *p=current->courseLink;
			   while(p!=NULL)
			   {
				   cout<<"course="<<p->courseName<<"  "<<"credit="<<p->credit<<"  "<<"grade="<<p->grade<<" ";

			if(p->grade=="A")
			{
				p->gpa=p->credit*4;
				cout<<"gpa=";
				cout<<p->gpa<<endl;
			}
			else if(p->grade=="B")
			{
				p->gpa=p->credit*3;
				cout<<"gpa=";
				cout<<p->gpa<<endl;
			}
			else if(p->grade=="C")
			{
				p->gpa=p->credit*2;
				cout<<"gpa=";
				cout<<p->gpa<<endl;
			}
			else if(p->grade=="D")
			{
				cout<<"gpa=";
				p->gpa=p->credit*1;
				cout<<p->gpa<<endl;
			}
			else
			{
				p->gpa=p->credit*0;
				cout<<"fail"<<endl;
			}
		  totalcredit=totalcredit+p->credit;
		 totalgpa1=(totalgpa1+p->gpa);

				   p=p->link;
			   }
			   current->data.totalgpa=totalgpa1/totalcredit;
			   cout<<"total gpa="<<current->data.totalgpa<<endl;
	   }

	  current=current->link;
	}
	 if(found==false){

		   cout<<"The student is not registered"<<endl;
		   cout<<"Enter another i.d"<<endl;
		   cin>>idno;
		   SearchByIdflag=true;
		   current=head;
	 }
	 else{
		 SearchByIdflag=false;
	 }

	}
}//end of SearchById..

void SerchStudentBycourse(node *head) //print student name who r taking COSC504
{
	node *q;
	courseType *p;
	q=head;
	string coursename1;
	cout<<"enter the course name=";
	cin>>coursename1;

	cout<<"student name who are taking"<<coursename1<<" are"<<endl;
	int i=0;
	while(q!=NULL)
	{
		p=q->courseLink;
		while(p!=NULL)
		{
			if(p->courseName==coursename1)
			{
				cout<<q->data.lastName<<" "<<q->data.FirstName<<endl;
				i++;
			}
			p=p->link;

		}
		q=q->link;
	}

cout<<"total students are who taking "<<coursename1<<" are="<<i<<endl;
}//end function



#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<stack>
#include "Utility.h"

using namespace std;


struct courseType //structure for course details.
{
	string courseName;
	int credit;
	string grade;
	double gpa;
	courseType *link;
};

struct student
	{
		string FirstName;
			string lastName;
			int id;
			double totalgpa;

	};

struct node //main structure for student details.
{
	student data;
	courseType *courseLink;
	node *link;
};
		node *head=NULL;

int count(node*head) ; //function to count the student details..
void Createlist(node *&head);   //function to create the list of student by using singlelinked list.
void FindGPA(node *&head);//function to calculate gpa
void InsertNewStudent(node *&head) ; //function to InsertNewStudent new student details....
void menu();
void deltecourseByName(node *head);
void deletestudentById(node *head);
void deletestudentByName(node *head);
void deltecourse(node *head);
void print(node *head,bool gpaflag);  //function to print the created list.
void HonorStudent(node *head);//function to count the number of students scored gpa above 3.6
void WarnStudent(node*head);//function to warn the student who got gpa less than 2.5
void FailStudent(node *head);//function to count the number of failures and prints their name
void countstudent(node *head); //print student name who r taking COSC504
void sortBylastname(node *head) ;//function to print the student details sorted by last name.
void sortByfirstname(node *head);//function to sort the student details by headname.
void sortBygpa(node *head);//function to sort the student details by gpa
void sortByid(node *head);//function to sort the details by i.d
void sortall(node *head); //function to sort the student details by headname,lastname,id,gpa..
void SearchById(node *head); //function to SearchById a student by i.d
void SerchStudentBycourse(node *head); //print student name who r taking COSC504
void modify(node *head); //function to update the students data..
void addcourse(node *&head); //function to add new course to an existed student..
void addcourseByName(node *&head); //function to add new course to an exsisted student..

int count(node*head)  //function to count the student details..
{
	node *current;
	int count=0;
	current=head;
	while(current!=NULL)//traversing the list
	{
		current=current->link;
		count++;
	}

	return count;
}//end of count function....



void Createlist(node *&head)   //function to create the list of student by using singlelinked list.
{
	ifstream infile;
	infile.open("seniorclass.txt");
	node *newnode;
	courseType *newCourseNode;
	head=NULL;
	while(!infile.eof())//read from file until the end of the file
	{
		newnode=new node;
		newCourseNode=new courseType;
		infile>>newnode->data.FirstName>>newnode->data.lastName>>newnode->data.id>>newCourseNode->courseName>>newCourseNode->credit>>newCourseNode->grade;
		newnode->link=NULL;
		newCourseNode->link=NULL;
		newnode->courseLink=newCourseNode;
	if(head==NULL)//special case
	{

		head=newnode;

	}
	else
	{
		node *temp;
		temp=head;
		bool flag=true;
		while (temp!=NULL)//loop to add information to course link.
		{
			if(temp->data.FirstName==newnode->data.FirstName && temp->data.lastName==newnode->data.lastName){//camparing whether the name is same
				flag=false;
			courseType *tempCourse;
		tempCourse=temp->courseLink;
				while (tempCourse->link!=NULL)
				{
					tempCourse=tempCourse->link;
				}
				tempCourse->link=newCourseNode;
				tempCourse=newCourseNode;
			}

			temp=temp->link;
		}

		node *temp1=head;
		if(flag){
			while (temp1->link!=NULL)
				{
					temp1=temp1->link;
				}

			temp1->link=newnode;
			temp1=newnode;
		}

	}

	}

}//end of create function.


void print(node *head,bool gpaflag)  //function to print the created list.
{
	node *current;
	current=head;
	cout<<"FIRSTNAME\tLASTNAME\tID\t\tCOURSE\t\tCREDIT\t\tGRADE";

	 if(gpaflag==true)
	  {
		  cout<<"\tTOTAL GPA"<<endl;
	  }
	  else
	  {
		  cout<<endl;
	  }
	while(current!=NULL)
	{
		cout<<current->data.FirstName<<"\t\t"<<current->data.lastName<<"\t\t"<<current->data.id;
		courseType *tempCourse;
		tempCourse=current->courseLink;
		bool flag=false;
		while(tempCourse!=NULL)  //to print the course link
		{
			if(flag)
			{
		cout<<current->data.FirstName<<"\t\t"<<current->data.lastName<<"\t\t"<<current->data.id;
		}
	  cout<<"\t\t"<<tempCourse->courseName<<"\t\t"<<tempCourse->credit<<"\t\t"<<tempCourse->grade;
	  if(gpaflag==true)
	  {
		  cout<<"\t\t"<<current->data.totalgpa<<endl;
	  }
	  else{
		  cout<<endl;
	  }

	  flag=true;
		tempCourse=tempCourse->link;

		cout<<endl;
		}


		current=current->link;

	}
}//end of print function...



void FindGPA(node *&head)//function to calculate gpa
{
	node *current;

	courseType *p;
	current=head;
	while(current!=NULL)//traversing for the list to calculate gpa
	{
		double TOTAL=0;
	double totalcredit=0;
		p=current->courseLink;
		while(p!=NULL)
		{
			if(p->grade=="A")
			{
				p->gpa=p->credit*4;
			}
			else if(p->grade=="B")
			{
				p->gpa=p->credit*3;
			}
			else if(p->grade=="C")
			{
				p->gpa=p->credit*2;
			}
			else if(p->grade=="D")
			{
				p->gpa=p->credit*1;
			}
			else
			{
				p->gpa=p->credit*0;
				cout<<"fail"<<endl;
			}
			totalcredit=totalcredit+p->credit;
			TOTAL=(TOTAL+p->gpa);
			p=p->link;
		}//closing inner while
		current->data.totalgpa=TOTAL/totalcredit;
		current=current->link;
	}//closing outer while

}//closing function.

void menu()  //menu function to select choices.
{
cout<<"*********************MENU********************"<<endl;
cout<<"*********************************************"<<endl;
cout<<"press <1>=Create and print"<<endl;
cout<<"press <2>=To InsertNewStudent"<<endl;
cout<<"press <3>=To AddCourse"<<endl;
cout<<"press <4>=To DeleteStudent"<<endl;
cout<<"press <5>=To DeleteCourse"<<endl;
cout<<"press <6>=To FindGPA"<<endl;
cout<<"press <7>=To Sort"<<endl;
cout<<"press <8>=To Search "<<endl;
cout<<"press <9>=To Update"<<endl;
cout<<"press <10>=To HonorStudents"<<endl;
cout<<"press <11>=To WarnStudents"<<endl;
cout<<"press <12>=To FailStudents"<<endl;
cout<<"press <13>=To Print"<<endl;
cout<<"press <14>=Find students who are taking cosc504"<<endl;
cout<<"*********************************************"<<endl;
cout<<"Select your choice=";
}

void InsertNewStudent(node *&head)  //function to InsertNewStudent new student details....
{

node *newnode,*current;
courseType *newcourseNode;
current=head;
newnode=new node;
newcourseNode=new courseType;
while(current->link!=NULL)
{
	current=current->link;
}

cout<<"Enter student's first name"<<endl;
string fName;
cin>>fName;
getStringType(&fName);
newnode->data.FirstName=fName;
cout<<"Enter students last name"<<endl;
string lName;
cin>>lName;
getStringType(&lName);
newnode->data.lastName=lName;
cout<<"Enter students i.d"<<endl;
string id;
cin>>id;
getNumericType("ID",&id);
newnode->data.id=atoi(id.c_str());

node* temp=head;
while(temp!=NULL)
	{
		if(newnode->data.id==temp->data.id) // checks whether the given id is already existed or not.
		{
			cout<<"Id should be unique please enter another i.d"<<endl;
            cin>>id;
			getNumericType("ID",&id);
			newnode->data.id=atoi(id.c_str());
			temp=head;
		}
		else
		{
			temp=temp->link;
		}

}
bool courseContFlag=false;
newcourseNode=NULL;
do{

	if(newcourseNode==NULL){
		newcourseNode=new courseType;
		cout<<"enter course name"<<endl;
		string course;
		cin>>course;
		getCourse(&course);
		newcourseNode->courseName=course;

		cout<<"Enter credit"<<endl;
		string credit;
		cin>>credit;
			getNumericType("CREDIT",&credit);
			newcourseNode->credit=atoi(credit.c_str());
			temp=head;

		cout<<"Enter grade"<<endl;
		string grade;
		cin>>grade;
		getStringTypeWithLength("Grade",&grade);
		newcourseNode->grade=grade;

		newcourseNode->link=NULL;
	}else{
		courseType* temp1=newcourseNode;
		courseType*trail=newcourseNode;

		while (newcourseNode->link!=NULL)
		{
			newcourseNode=newcourseNode->link;
		}
		courseType *newcourseNode1;
		newcourseNode1=new courseType;
		cout<<"enter course name"<<endl;
		string course;
		cin>>course;
		getCourse(&course);
		newcourseNode1->courseName=course;



while(temp1!=NULL)
	{
		if(newcourseNode1->courseName==temp1->courseName){
			cout<<"The student already registered in that course"<<endl;
			cout<<"Enter another course"<<endl;
			string course;
			cin>>course;
		getCourse(&course);
		newcourseNode1->courseName=course;
			temp1=trail;
		}
		else
		{
			temp1=temp1->link;
		}

}

		cout<<"Enter credit"<<endl;
		string credit;
		cin>>credit;
			getNumericType("CREDIT",&credit);
			newcourseNode1->credit=atoi(credit.c_str());
		cout<<"Enter grade"<<endl;
		string grade;
		cin>>grade;
		getStringTypeWithLength("Grade",&grade);
		newcourseNode1->grade=grade;
		newcourseNode1->link=NULL;
		newcourseNode->link=newcourseNode1;

	}
	cout<<"Do you want add another course? Y/N"<<endl;
	string cont;
	cin>>cont;
	if(cont=="Y" || cont=="y")
	{
	courseContFlag=true;
	}
	else
	{
	courseContFlag=false;
	}
}
while(courseContFlag);
newnode->courseLink=newcourseNode;
newnode->link=NULL;
current->link=newnode;
current=newnode;

}//end of InsertNewStudent new student function....


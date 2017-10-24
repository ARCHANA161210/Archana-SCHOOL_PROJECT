// COSC 504
// December 2015
//Programming Project:that project contains different operation using linked list


#include "header.h"
#include"sorting.h"
#include "adding.h"
#include "deleting.h"
#include "overview.h"
#include "Search.h"
#include "update.h"

int main()
	{
		node *head=NULL;
		int choice;
		Createlist(head);
	char ch;
		do
		{
			menu();
				cout<<"Enter Choice for main menu"<<endl;
				cin>>choice;
	switch(choice)
	{
	case 1:
		sortBylastname(head);
	    print(head,false);
		cout<<endl;
		cout<<"the total class count is="<<count(head)<<endl;
		break;
	 case 2:
		 InsertNewStudent(head);

		 print(head,false);
		 cout<<"count after InsertNewStudent="<<count(head)<<endl;
		 break;

	case 3:
		cout<<"Enter choice of adding course"<<endl;
		cout<<"press <1>=To add by i.d"<<endl;
		cout<<"press <2>=To add by name"<<endl;
		cout<<"press <-1>=To quit"<<endl;
		cin>>choice;
		while(choice!=-1)
		{
			switch (choice)
			{
			case 1:
				addcourse(head);
				break;
			case 2:
				addcourseByName(head);
		       break;
			default:
				cout<<"Invalid choice"<<endl;
				break;
			}
		cout<<"Enter choice of adding course"<<endl;
		cin>>choice;
		}
		break;

	case 4:
		cout<<"press <1>=To delete by id"<<endl;
		cout<<"press <2>=To delete by name"<<endl;
		cout<<"press <-1>=To quit"<<endl;
		cout<<"Enter choice to delete"<<endl;
		cin>>choice;
		while(choice!=-1)
		{
			switch(choice)
			{
			case 1:
		     deletestudentById(head);
			 break;
			case 2:
		    deletestudentByName(head);
		     break;
			 default:
		       cout<<"invalid choice"<<endl;
		        break;
			}
			cout<<"Enter choice for delete"<<endl;
			cin>>choice;
		}

		break;

	case 5:

		cout<<"press <1>=To delete course by id"<<endl;
		cout<<"press <2>=To delete course by name"<<endl;
		cout<<"press <-1>=To quit"<<endl;
		cout<<"Enter your choice to delete"<<endl;
		cin>>choice;
		while(choice!=-1)
		{
			switch(choice)
			{
			case 1:
				deltecourse(head);

			 break;
			case 2:
				deltecourseByName(head);
		     break;
			 default:
		cout<<"invalid choice"<<endl;
		break;
			}
			cout<<"Enter choice for delete"<<endl;
			cin>>choice;
		}
		break;
	case 6:
		 FindGPA(head);
		 print(head,true);
		 break;

	case 7:
	     sortall(head);
		 break;

	case 8:
		cout<<"press <1>=To search student by id"<<endl;
				cout<<"press <2>=To search by course name"<<endl;
				cout<<"press <-1>=To quit"<<endl;
				cout<<"Enter choice to search"<<endl;
				cin>>choice;
				while(choice!=-1)
				{
					switch(choice)
					{
					case 1:
						SearchById(head);
					 break;
					case 2:
						SerchStudentBycourse(head);
						break;
					 default:
				       cout<<"invalid choice"<<endl;
				        break;
					}
					cout<<"Enter choice for search"<<endl;
					cin>>choice;
				}

		break;

	case 9:
		 modify(head);
		 break;

	case 10:
		  HonorStudent(head);
	     break;

	case 11:
		WarnStudent(head);
		break;

	case 12:
		FailStudent(head);
		break;

	case 13:
		 FindGPA(head);
			sortBylastname(head);

		print(head,true);
		cout<<"The total count is="<<count(head)<<endl;
		 break;
	case 14:
		countstudent(head);
		break;
	default:
		cout<<"Error.......! invalid choice"<<endl;
		break;
	}
	cout<<"want to process more y/n"<<endl;
	       cin>>ch;
	     }
	     while(ch!='n');

	    return 0;
	}


#include<iostream>
using namespace std;

void selection()
{
	cout<<endl<<endl;
	cout<<"enter your choice:-\n";
cin>>choice;
ready_q(list[choice-1]);
cout<<"This process need= "<<list[choice-1].PCB.consuption_memory<<"memory"<<endl;
cout<<"Current Available RAM is ="<<RAM<<endl;
RAM=RAM-list[choice-1].PCB.consuption_memory;
cout<<"you have left memory is= "<<RAM<<endl;

cin>>choice;
while(choice!=-1 && i!=10 )
{

if(list[choice-1].PCB.consuption_memory < RAM)
{
	ready_q(list[choice-1]);
	cout<<"This process need= "<<list[choice-1].PCB.consuption_memory<<"memory"<<endl;
	cout<<"Current Available RAM is "<<RAM<<endl;
	RAM=RAM-list[choice-1].PCB.consuption_memory;
	cout<<"you have left memory is="<<RAM<<endl;
}

else 
{
	cout<<"This process need= "<<list[choice-1].PCB.consuption_memory<<"memory"<<endl;
	cout<<"Current Available RAM is ="<<RAM<<endl;
	cout<<endl;
	cout<<"you don't have enough memory........Add another process please...!="<<endl;
}
cin>>choice;
i++;
}

}

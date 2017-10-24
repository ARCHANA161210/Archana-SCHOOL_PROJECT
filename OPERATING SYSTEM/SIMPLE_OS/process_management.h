#include<iostream>
using namespace std;



void operation()
{
cout<<endl<<endl;
sort(queueFront);
cout<<"......................................................................................\n";
cout<<".................This operating system use shortest job first algorithem..............\n";
cout<<"......................................................................................\n";
cout<<"These processes are in queue=";

print();
cout<<endl;
cout<<"###################your processes  are starting......!#######################"<<endl<<endl;

while(!isEmptyQueue())
{
		
cout<<"###################your current starting process is="<<list[front().process_number-1].process_name<<"###########"<<endl;
v=front().process_number;
cout<<"###################These processes are in waiting queue=";
deleteQueue();
print();
cout<<endl<<endl;
switch(v)	

	{
		case 1:
			cout<<"########################opening notepad .............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "notepad.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM notepad.exe "); 
		    cout<<"########################notepad is closed............!##################"<<endl;
		   	RAM+=list[0].PCB.consuption_memory;
		    break;	    
		case 2:
		    cout<<"########################opening wordpad.............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "wordpad.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM wordpad.exe "); 
		    cout<<"########################wordpad is closed............!##################"<<endl;
		   	RAM+=list[1].PCB.consuption_memory;
		    break;	    
		case 3:
		   cout<<"########################opening paint.............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "mspaint.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM mspaint.exe "); 
		    cout<<"########################paint is closed............!##################"<<endl;
		   	RAM+=list[2].PCB.consuption_memory;
		    break;	    
		case 4:
		    cout<<"########################opening SnippingTool.............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "SnippingTool.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM SnippingTool.exe "); 
		    cout<<"########################SnippingTool is closed............!##################"<<endl;
		   	RAM+=list[3].PCB.consuption_memory;
		    break;	    
		case 5:
		   cout<<"########################opening notepad++.............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "Notepad++.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM Notepad++.exe "); 
		    cout<<"########################notepad++ is closed............!##################"<<endl;
		   	RAM+=list[4].PCB.consuption_memory;
		    break;	    
		case 6:
		    cout<<"########################opening command promt.............!###################"<<endl;
			Sleep(2000);
			ShellExecute(NULL, "open", "cmd.exe", NULL, NULL, SW_SHOWDEFAULT);
        	cout<<"########################waiting this process ..........for 10 sec..#####"<<endl;
		    Sleep(10000);
            system("taskkill /F /T /IM cmd.exe "); 
		    cout<<"########################command promt is closed............!##################"<<endl;
		   	RAM+=list[5].PCB.consuption_memory;
		    break;	    
		case 7:
			cout<<"#########################strat addition process......##################"<<endl;
			a=rand() % 100;
			b=rand() % 10;
			cout<<"########################this process take your 10 second.....############\n";
			Sleep(10000);
			cout<<"########################your answer of "<<a <<"+"<<b<<" is="<<(a+b)<<"###########"<<endl;
			cout<<"#########################close the process of addition#################\n";
			break;
		case 8:
				cout<<"######################strat multiplication process......##############"<<endl;
			a=rand() % 100;
			b=rand() % 10;
			cout<<"##########################This process take your 10 second.....#############\n";
			Sleep(10000);
			cout<<"###########################your answer of "<<a <<"*"<<b<<" is="<<(a*b)<<"###########"<<endl;
			cout<<"###########################close the process of substraction#################\n";
			break;
		case 9:
				cout<<"########################strat division process......####################"<<endl;
			a=rand() % 100;
			b=rand() % 10;
			cout<<"############################this process take your 10 second.....##############\n";
			Sleep(10000);
			cout<<"############################your answer of "<<a <<"divide"<<b<<" is="<<(a/b)<<endl;
			cout<<"##############################close the process of divisoin#################\n";
			break;
		case 10:
			cout<<"########################strat substraction process......#########################"<<endl;
			a=rand() % 100;
			b=rand() % 10;
			cout<<"#########################this process take your 10 second.....#####################\n";
			Sleep(10000);
			cout<<"##########################your answer of "<<a <<"-"<<b<<" is="<<(a-b)<<endl;
			cout<<"###########################close the process of substraction#####################\n";
			break;
	}
	
	cout<<endl<<endl<<endl<<endl;
		
}

}

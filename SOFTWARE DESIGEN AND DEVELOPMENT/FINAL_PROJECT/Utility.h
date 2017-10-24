#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

//This function will check the given input string is a numeric value or not
//if return value is false, the given string is not a numeric
//if return value is true, the given string is  a numeric

bool checkNumeric(string *inputString)
{
  bool chkFlag=true;
  for (int n = 0; n < (*inputString).length(); n++)
  {
  if (!isdigit( (*inputString)[ n ] ))
    {
    chkFlag = false;
    break;
    }
  }
	return chkFlag;
}


//This function will check the given input string is a alphabatical  value or not
//if return value is false, the given string is not a alphabatical
//if return value is true, the given string is  a alphabatical
bool checkAlpha(string *inputString)
{
	bool chkFlag=true;
	for (int n = 0; n < (*inputString).length(); n++)
  {
	  if (!isalpha( (*inputString)[ n ] ))
    {
    chkFlag = false;
    break;
    }
  }
	return chkFlag;
}
//This function will check the given input string is a alpha numeric  value or not
//if return value is false, the given string is not a alpha numeric
//if return value is true, the given string is  a alpha numeric
bool checkAlphaNumeric(string *inputString){
	bool chkFlag=true;
	for (int n = 0; n < (*inputString).length(); n++)
  {
  if (!isalnum( (*inputString)[ n ] ))
    {
    chkFlag = false;
    break;
    }
  }
	return chkFlag;
}

//This function will convert given input string in to first letter of the string into upper case letter
//and remaining letters into lower case letters
//EX: if given input is apple, out is Apple
void convertString(string *inputString)
{
	string result;

	for(unsigned int l = 0; l < (*inputString).length(); l++)
  {
	  if(l==0){
    (*inputString)[l] = toupper((*inputString)[l]);
	  }else{
		   (*inputString)[l] = tolower((*inputString)[l]);
	  }
  }

}

//This function will check given input string is numeric value or not
//This will not exit until user gives a numeric value

void validateNumeric(string *inputString){


	bool has_only_digits = true;
	has_only_digits=checkNumeric(inputString);
	while(!has_only_digits){
	cout<<"wrong data, Please re enter only numeric values"<<endl;
	cin>>*inputString;

	has_only_digits=checkNumeric(inputString);
	}

}

//This function will check given input string is string value or not
//This will not exit until user gives a string value
void getStringType(string *inputString)
{

	bool stringFlag = true;
	stringFlag=checkAlpha(inputString);
	while(!stringFlag)
	{
	cout<<"wrong data, Please re enter only alpha values"<<endl;
	cin>>*inputString;
	stringFlag=checkAlpha(inputString);
	}

	convertString(inputString);
}
//This function will check given input string is alphabatical  value or not
//This will not exit until user gives a alphabatical value and its size is equal to 1
void getStringTypeWithLength(string type,string *inputString)
{

	bool gradeFlag=true;
	while(gradeFlag)
	{
		getStringType(inputString);
			if(type=="Grade" && (*inputString).length()==1)
			{
				gradeFlag=false;
			}
			else
			{
				cout<<"Grade should be single alpha, please enter again:";
				cin>>*inputString;

				gradeFlag=true;
			}
	}
}
//This function will validate given input string length based on given type
bool validateSize(string type,string *inputString)
{
	bool chk=false;

	if(type=="ID" && (*inputString).length()==5)
	{
	chk=true;
	}
	else if(type=="CREDIT" && (*inputString).length()==1)
	{
	chk=true;
	}

	return chk;
}

void getNumericType(string type,string *inputString){ //vlaidates given input string is numeric or not and also
	validateNumeric(inputString);                     //validates the size given input type.
	bool has_only_digits = true;
	has_only_digits=validateSize(type,inputString);
	while(!has_only_digits){
	cout<<"wrong data, Please re enter only numeric values of proper size";
	if(type=="ID"){
	cout<<" 5 "<<endl;
	}else if(type=="CREDIT"){
		cout<<"  1  "<<endl;
	}
	cin>>*inputString;

	has_only_digits=validateSize(type,inputString);
	}

}
//This function will check given input string is alpha numeric or not
//This function will not exit until user gives alpha numeric value

void validateCourseName(string *inputString){
	bool chkFlag = true;
	chkFlag=checkAlphaNumeric(inputString);
	while(!chkFlag){
	cout<<"wrong data, Please re enter only alpha numeric values"<<endl;
	cin>>*inputString;

	chkFlag=checkAlphaNumeric(inputString);
	}
}

void getCourse(string *inputString){ //function to validate given course name is correct or not and deplays
	bool courseFlag=true;            //message if it is not consistent.
	while(courseFlag){
		validateCourseName(inputString);
		if((*inputString).size()==6 || (*inputString).size()==7){
			string courseStr,cousreInt;
			if((*inputString).size()==6){
				courseStr=(*inputString).substr(0,3);
				cousreInt=(*inputString).substr(3,5);


			}else{
				courseStr=(*inputString).substr(0,4);
				cousreInt=(*inputString).substr(4,6);

			}

			bool courseIntFlag=true;
				courseIntFlag=checkNumeric(&cousreInt);
				if(!courseIntFlag){
				cout<<"Last 3 digits of course should be numeric, please enter course again:";
				cin>>*inputString;
				courseFlag=true;
				}

				if(courseIntFlag){
				bool courseStrFlag=true;
				courseStrFlag=checkAlpha(&courseStr);
				if(!courseStrFlag){
				cout<<"First 3 or 4 digits of course should be aplpha, please enter course again:";
				cin>>*inputString;
				courseFlag=true;
				}else{
					convertString(inputString);
					courseFlag=false;
				}
				}

		}else{
		cout<<"Course should be min 5 & max 6 length, please re enter:";
		cin>>*inputString;
		courseFlag=true;
		}
	}
}


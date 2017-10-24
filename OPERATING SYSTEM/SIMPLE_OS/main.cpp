#include<iostream>
#include<windows.h>

using namespace std;

int RAM =132;
int v=0,a,b;
int choice;
int j=0,i=1;

#include "menu.h"
#include "constant.h"
#include "list_process.h"
#include "queue.h"
#include "process_management.h"
#include "memeory_map.h"

int main()
{
	display();
	adding_process_info();
	selection();
	operation();
}

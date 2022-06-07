#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <map>
#include "task.h"

//using namespace std;

class List
{
private:
	map<int, Task> tlist; //TODO unsigned
	//Assign int on load, trim it before writing to file (to handle remove and ID range)
	bool showTask(int iID);
public:
	List();
	List(string strFileName);
	bool showAll();
	bool addTask(string strText);
	bool markTask(int iID);
	int searchForTask(string strSearchTerm);
	bool editTask(int iID, string strNewText);
	bool isEmpty();
};


#endif //_LIST_H_
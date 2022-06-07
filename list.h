#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <vector>
#include "task.h"

//using namespace std;

class List
{
private:
	vector<Task> tlist;
	bool showTask(int iID);
public:
	List();
	List(string strFileName);
	bool showAll();
	bool addTask(string strText);
	bool markTask(int iID);
	int searchForTask(string strSearchTerm); //or ret bool
	bool editTask(int iID, string strNewText);
};


#endif //_LIST_H_
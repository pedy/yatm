#ifndef _LIST_H_
#define _LIST_H_

#include <string>
#include <map>
#include "task.h"

#define DATA_FNAME			"data.txt"
#define ONFILE_CHECKED 		"+"
#define ONFILE_UNCHECKED 	"-"

class List
{
private:
	map<int, Task> tlist;
	bool hasChanged;
public:
	enum class ShowType { All, Marked, Unmarked } ;
	List();
	List(string strFileName);
	bool show(ShowType what = ShowType::All);
	bool addTask(string strText);
	bool markTask(int iID);
	int searchForTask(string strSearchTerm);
	bool editTask(int iID, string strNewText);
	bool isEmpty();
	bool hasID(int id);

	bool writeToFile();
};


#endif //_LIST_H_
#ifndef _TASK_H_
#define _TASK_H_

#include <string>
using namespace std;

class Task
{
    string strText;
    bool bChecked;

public:
    Task();
    Task(string text);
    bool setText(string text);
    string getText();
    bool mark();
    bool isMarked();
    void reset();
};

#endif //_TASK_H_
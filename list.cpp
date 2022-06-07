#include "list.h"

List::List()
{
    cout << "Default constructor" << endl;
}

List::List(string strFileName)
{
    cout << "fileName constructor: " << strFileName << endl;
}

bool List::addTask(string strText)
{
    Task tsk(strText);
    tlist.push_back(tsk);

    return true;
}

bool List::showAll()
{
    //TODO handle empty
    for (Task item : tlist)
    {
        if (item.isMarked())
            cout << "[x] ";
        else
            cout << "[ ] ";

        cout << item.getText() << endl;
    }
}
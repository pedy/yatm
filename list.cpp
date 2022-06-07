#include "list.h"

List::List()
{
    //TODO cout << "Default constructor" << endl;
}

List::List(string strFileName)
{
    //TODO cout << "fileName constructor: " << strFileName << endl;
}

bool List::isEmpty()
{
    return (tlist.size() == 0) ? true : false;
}

bool List::addTask(string strText)
{
    try
    {
        Task newTask(strText);
        int iNewItemIdx = 1;
        //tlist.push_back(tsk); was for vector
        //auto upb = tlist.upper_bound();

        //cout << tlist.size() << endl;

        //tlist.insert(pair<int, string>(1, "yek"));
        if (!isEmpty())
        {
            auto lastItem = *tlist.rbegin();
            iNewItemIdx = lastItem.first + 1;
        }
        tlist.insert(pair<int, Task>(iNewItemIdx, newTask));


        /*tlist.insert(pair<int, string>(2, "do"));
        tlist.insert(pair<int, string>(3, "se"));
        cout << tlist.size() << endl;

        auto yek = tlist.at(1);
        auto dn = tlist.rbegin();
        --dn;

        tlist.insert(pair<int, string>(1, "sesh"));*/

        return true;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
}

bool List::showAll()
{
    //TODO handle empty
    //for (Task item : tlist)vector
    for (pair<int, Task> kv : tlist)
    {
        Task item = kv.second;
        cout << kv.first << ") ";
        if (item.isMarked())
            cout << "[x] ";
        else
            cout << "[ ] ";

        cout << item.getText() << endl;
    }
    return true;
}

bool List::markTask(int iID)
{
    try
    {
        if (tlist.find(iID) == tlist.end())
        {
            cerr << "Not found." << endl;
            return false;
        }
        else
        {
            tlist[iID].mark();
            cout << "[x] " << tlist[iID].getText() << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Failed!" << endl;
        return false;
    }
    
    return true;
}

bool List::editTask(int iID, string strNewText)
{
    try
    {
        if (tlist.find(iID) == tlist.end())
        {
            cerr << "Not found." << endl;
            return false;
        }
        else
        {
            tlist[iID].setText(strNewText);
            if (tlist[iID].isMarked())
                cout << "[x] ";
            else
                cout << "[ ] ";
            cout << tlist[iID].getText() << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Failed!" << endl;
        return false;
    }
    
    return true;
}

int List::searchForTask(string strSearchTerm)
{
    int iFoundCount = 0;
    try
    {
        //TODO indexing to search better?
        for (auto item : tlist)
            if (item.second.getText().find(strSearchTerm) != string::npos) //TODO case insensitive
            {
                cout << "Found " << item.first << ") " << item.second.getText() << endl;
                ++iFoundCount;
            }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (iFoundCount == 0)
        cout << "Not found." << endl;

    return iFoundCount;
}
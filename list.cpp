#include "list.h"
#include <fstream>
#include <iostream>

List::List(string strFileName)
{
    hasChanged = false;
    tlist = map<int, Task>();
    ifstream dataFile (strFileName, ios::in);
    if (dataFile) //Data file already exists
    {   
        cout << "data file found." << endl;
        //Read the file and load data
        Task objTempTask;
        string strTemp = "";
        int iInMemoryListIndex = 0;

        while (getline(dataFile, strTemp))
        {
            objTempTask.reset();
            objTempTask.setText(strTemp.substr(1));
            if (strTemp.substr(0, 1) == ONFILE_CHECKED)
                objTempTask.mark();

            tlist.insert(pair<int, Task>(++iInMemoryListIndex, objTempTask));
            /*  iInMemoryListIndex is an integer index to facilitate user's pointing to items.
                It isn't in the data file. It has no added value, and in case of later development of
                delete operation, handling IDs could make it harder.
            */
        }
        dataFile.close();
        cout << iInMemoryListIndex << " items loaded. Try [l]ist command to see them." << endl;
    }
    else
    {
        cout    << "No data file found in " << strFileName
                << ". Starting from scratch..." << endl;
    }
}

bool List::isEmpty()
{
    return (tlist.size() == 0) ? true : false;
}

bool List::addTask(string strText)
{
    hasChanged = true;

    Task newTask(strText);
    int iNewItemIdx = 1;

    if (!isEmpty())
    {
        //Find next available in-memory ID
        auto lastItem = *tlist.rbegin();
        iNewItemIdx = lastItem.first + 1;
    }
    tlist.insert(pair<int, Task>(iNewItemIdx, newTask));
    return true;
}

bool List::show(ShowType what)
{
    if (isEmpty())
    {
        cout << "There are no items available." << endl;
        return false;
    }
    for (pair<int, Task> kv : tlist)
    {
        Task item = kv.second;
        if (item.isMarked())
        {
            if (what == ShowType::Unmarked)
                continue;
            cout << kv.first << ") "<< "[x] ";
        }
        else
        {
            if (what == ShowType::Marked)
                continue;
            cout << kv.first << ") "<< "[ ] ";
        }

        cout << item.getText() << endl;
    }
    return true;
}

bool List::markTask(int iID)
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
        hasChanged = true;
        return true;
    }
}

bool List::editTask(int iID, string strNewText)
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
        hasChanged = true;
        return true;
    }
}

int List::searchForTask(string strSearchTerm)
{
    int iFoundCount = 0;
    for (auto item : tlist)
        if (item.second.getText().find(strSearchTerm) != string::npos)
        {
            cout << "Found " << item.first << ") " << item.second.getText() << endl;
            ++iFoundCount;
        }
    if (iFoundCount == 0)
        cout << "Not found." << endl;
    else
        cout << "Total items found: " << iFoundCount << endl;

    return iFoundCount;
}


bool List::writeToFile()
{
    if (!hasChanged)
    {
        cout << "No work to save." << endl;
        return true;
    }

    /*
    //If you provided delete option in future
    else if (hasChanged && isEmpty()) //All items are removed
    {
        remove(DATA_FNAME); //#include <cstdlib> 
    }*/

    ofstream ofs(DATA_FNAME, ios::out);

    if (!ofs)
    {
        cerr << "Couldn't access!" << endl;
        /* It's better to be checked, but I couldn't simulate a scenario.
            - If file is deleted after the loading, it will be re-writen.
            - If file is open in another editor (tested with Vim and Kate, simultaneously), it could be rewritten, too.
            (Both tested on Linux)
        */
        return false;
    }
    
    for (auto item : tlist)
    {
        ofs <<  (item.second.isMarked() ? ONFILE_CHECKED : ONFILE_UNCHECKED) <<
                item.second.getText() << endl;
    }

    ofs.close();
    cout << "Changes saved." << endl;
    return true;
}

bool List::hasID(int id)
{
    return (tlist.find(id) == tlist.end()) ? false : true;
}



#include "task.h"
using namespace std;

Task::Task()
{
    strText = "";
    bChecked = false;
}

Task::Task(string text)
{
    try
    {
        strText = text;
        bChecked = false;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
}

bool Task::setText(string text)
{
    //TODO limit input
    strText = text;
    return true;
}

bool Task::mark()
{
    bChecked = true;

    return true;
}

bool Task::isMarked()
{
    return bChecked;
}

string Task::getText()
{
    return strText;
}
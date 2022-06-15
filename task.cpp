#include "task.h"
#include <iostream>
using namespace std;

Task::Task()
{
    strText = "";
    bChecked = false;
}

Task::Task(string text)
{
    strText = text;
    bChecked = false;
}

bool Task::setText(string text)
{
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

void Task::reset()
{
    strText = "";
    bChecked = false;
}
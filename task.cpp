#include "task.h"
using namespace std;

task::task(string text)
{
    try
    {
        strText = text;
    }
    catch(const std::exception& e)
    {
        cerr << e.what() << '\n';
    }
}
#include <iostream>

using namespace std;
/* Left:
- CMake build
- Switches:
    - a: add (string)
    - e: edit (id - could be temp - but temp couldn't return; needs CLI loop)
    - l: list (note completed and incomplete)
    - m: mark
- Clean up:
    - Headers in folders?
- Potential Improvements:
    - Clear marked items
    - Due date
*/

int main(int argc, char* argv[])
{
    try
    {
        /* Handle args:
            0: help (TODO IMPRV CLI Menu) 
            1: Switch
            2: Switches requiring data
        */
       cout << "YATM: Yet Another Task Manager" << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
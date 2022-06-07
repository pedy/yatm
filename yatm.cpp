#include <iostream>
#include <fstream> //temp
#include <map> //temp
#include <list> //temp
#include "task.h"
#include "list.h"

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
void showMainOptions()
{
    cout << endl << "---------------------------------------------------------" << endl
    <<     "[a]dd"  
    << "    [e]dit" 
    << "    [l]ist" 
    << "    [m]ark" 
    << "    [s]earch"
    << "    [q]uit"  //TODO Other useful actions: unmark, clear marked items, ...
    << endl << "Enter one of highlighted characters: ";

    return;
}
int main(int argc, char* argv[])
{
    try
    {
        char option;
        int iID = 0;
        string strTemp;
        Task objTemp;
        List lst;
        while (true)
        {
            showMainOptions();
            option = std::getc(stdin);
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //TODO This was a copy/paste! Get to know what it does.
            switch (option)
            {
                case 'a':
                    //cout << "add" << endl;

                    cout << "Enter task text: " ;
                    //cin.getline(strTemp, 400); //TODO define this max
                    strTemp = "";
                    getline(cin, strTemp);
                    //cin >> strTemp;
                    //objTemp.SetText(strTemp);
                    lst.addTask(strTemp);
                    //TODO error handling
                    cout << "Item added.";

                    break;
                case 'e':
                    if (lst.isEmpty())
                        cout << "There are no items." << endl;
                    else
                    {
                        lst.showAll();
                        cout << "Enter the item ID: " ;
                        cin >> iID; //TODO check
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //TODO This was a copy/paste! Get to know what it does.
                        cout << "Enter the new text: ";
                        strTemp = "";
                        getline(cin, strTemp);
                        lst.editTask(iID, strTemp);
                        //TODO check result
                    }
                    break;
                case 'l':
                    if (lst.isEmpty())
                        cout << "There are no items." << endl;
                    else
                        lst.showAll();
                    break;
                case 'm':
                    if (lst.isEmpty())
                        cout << "There are no items." << endl;
                    else
                    {
                        lst.showAll(); //TODO show only unmarked
                        cout << "Enter the item ID: " ;
                        cin >> iID; //TODO check
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //TODO This was a copy/paste! Get to know what it does.
                        lst.markTask(iID);
                        //TODO check result
                    }
                    break;
                case 's':
                    cout << "Enter the search term (case sensitive): ";
                    strTemp = "";
                    getline(cin, strTemp);
                    lst.searchForTask(strTemp);
                    //TODO check output
                    break;
                case 'q':
                    cout << "quit" << endl;
                    return 0;//break;
                default:
                    cout << "unsupported command: " << option << endl;
                    break;
            }
        }
        /* Handle args:
            0: help (TODO IMPRV CLI Menu) 
            1: Switch
            2: Switches requiring data
        */
        cout << "YATM: Yet Another Task Manager" << endl;

        /*Task objTask ("Build all files");


        ofstream objOf;
        objOf.open(".\\temp.txt", ios::out | ios::app);

        //cout << "Seek to end: " << 
        //objOf.seekp(0, ios::end);

        objOf << "Hi" << endl;
        objOf << " there" << endl;

        objOf.close();

		map<int, string> mpList;
		map<int, Task> m2List;
        m2List.insert(pair<int, Task>(3, objTask));
        m2List[1] = objTask;
        mpList[1] = "objtask";

        list<Task> ls;
        ls.push_back(objTask);*/

        int f = 4;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
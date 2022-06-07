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
    cout << endl << "-----------------------------------------------------------------------" << endl;
    cout << "a) add"  ;//  << endl;
    cout << "\t\te) edit" ;//<< endl;
    cout << "\t\tl) list" ;//<< endl;
    cout << "\t\tm) mark" ;//<< endl;
    cout << "\t\tq) quit" << endl << "? ";

    return;
}
int main(int argc, char* argv[])
{
    try
    {
        char option;
        string strTemp;
        Task objTemp;
        List lst;
        while (true)
        {
            showMainOptions();
            option = std::getc(stdin);
            cin.ignore();
            //cout << "Entered: " << option << endl;
            switch (option)
            {
                case 'a':
                    //cout << "add" << endl;

                    cout << "Enter: " ;
                    //cin.getline(strTemp, 400); //TODO define this max
                    getline(cin, strTemp);
                    //cin >> strTemp;
                    //objTemp.SetText(strTemp);
                    lst.addTask(strTemp);
                    //TODO error handling
                    cout << "Item added.";

                    break;
                case 'e':
                    cout << "edit" << endl;
                    break;
                case 'l':
                    //cout << "list" << endl;
                    lst.showAll();
                    break;
                case 'm':
                    cout << "mark" << endl;
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
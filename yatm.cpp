#include <iostream>
#include "list.h"

using namespace std;
void showMainOptions()
{
    cout << endl << "---------------------------------------------------------" << endl
    <<     "[a]dd"  
    << "    [e]dit" 
    << "    [l]ist" 
    << "    [m]ark" 
    << "    [s]earch"
    << "    [q]uit" 
    << endl << "Enter one of highlighted characters: ";

    return;
}

int main(int argc, char* argv[])
{
    cout    << endl << endl
            << "******************************************" << endl
            << "***   YATM: Yet Another Task Manager   ***" << endl
            << "******************************************" << endl
            << endl << endl;
    try
    {
        int iID = 0;
        string strTemp = "";
        List lst(DATA_FNAME);

        while (true)
        {
            showMainOptions();
            char option = std::getc(stdin);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            switch (option)
            {
                case 'a':
                    cout << "Enter task text: " ;
                    strTemp = "";
                    getline(cin, strTemp);
                    lst.addTask(strTemp);
                    cout << "Item added." << endl;
                    break;
                case 'e':
                    if (lst.show())
                    {
                        cout << "Enter the item ID: " ;
                        cin >> iID;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        if (!lst.hasID(iID))
                        {
                            cerr << "No item #" << iID << " found." << endl;
                            break;
                        }
                        cout << "Enter the new text: ";
                        strTemp = "";
                        getline(cin, strTemp);
                        lst.editTask(iID, strTemp);
                    }
                    break;
                case 'l':
                    lst.show();
                    break;
                case 'm':
                    if (lst.show(List::ShowType::Unmarked))
                    { 
                        cout << "Enter the item ID: " ;
                        cin >> iID;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        lst.markTask(iID);
                    }
                    break;
                case 's':
                    cout << "Enter the search term (case sensitive): ";
                    strTemp = "";
                    getline(cin, strTemp);
                    lst.searchForTask(strTemp);
                    break;
                case 'q':
                    cout << "Exiting..." << endl;
                    return lst.writeToFile() ? 0 : -1;
                default:
                    cout << "unsupported command: " << option << endl;
                    break;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return -1;
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include "../header/menu.hpp"

using namespace std;

void displayRules (std::ostream&);
void displayCardCombinations(std::ostream&);

int main()
{
    string userInput;
    cout << "-------------- START MENU -----------------" << endl;
    cout << "rules" << endl;
    cout << "card rankings" << endl;
    cout << "card combinations" << endl;
    cout << "set starting amount" << endl;
    cout << "start game" << endl;
    cout << "-------------------------------------------" << endl;
    
    while (true)
    {
        getline(cin, userInput);

        if (userInput == "rules")
        {
            displayRules(std::ostream& );
            break;
        }
        else if (userInput == "card rankings" || userInput == "cr")
        {
            cout << "todo" << endl;
            break;
        }
        else if (userInput == "card combinations" || userInput == "cc")
        {
            displayCardCombinations(std::ostream& );
            break;
        }
        else if (userInput == "set starting amount" || userInput == "starting amount")
        {
            cout << "todo" << endl;
            break;
        }
        else if (userInput == "start game" || userInput == "start")
        {
            cout << "todo" << endl;
            break;
        }
        else
        {
            cout << "re-enter start menu option" << endl;
        }
    }
}


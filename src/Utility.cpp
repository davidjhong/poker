#include <iostream>

#include "../header/Utility.h"

using namespace std;

//https://stackoverflow.com/questions/17335816/clear-screen-using-c 
void Utility::clearScreen() 
{
    cout << "\033[2J\033[1;1H";
}
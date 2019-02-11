#include <iostream>
#include "StoreyBoard.hpp"
using namespace std;

int main()
{
    
    Task::TestStoryBoard tsb;
    
    if (tsb.testAddingNote())
        cout<<"Hello World";
    else
        cout<<"No Hello World";

    return 0;
}

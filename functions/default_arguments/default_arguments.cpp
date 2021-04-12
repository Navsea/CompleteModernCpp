#include <iostream>
using namespace std;

/*
1. Allows some or all function arguments to have defaults values
2. it becomes optional to pass values for those arguments 
3. Default arguments should begin from the right side in the list of arguments
*/

void createWindow(const char * title, int x, int y, int width, int height);

void createWindow(const char * title, int x=100, int y=100, int width=1024, int height=864)
{
    cout << "title: " << title << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "width: " << width << endl;
    cout << "height: " << height << endl;
}

int main()
{
    createWindow("MyWindow", 5, 6, 800, 600);
    createWindow("SecondWindow");

    // Important you have to start specifying from left to right
    // You cannot skip defining parameters which have default value!
    createWindow("ThirdWindow", 500);
}

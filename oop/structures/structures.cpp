/* Structures
- Other way to create user defined types
- Uses struct keyword
- Similar to class, but members are by default public
- Typically used to create abstract datastructures that need public access (its more convenient)
- For using function objects (used as callbacks in std library, discussed later)
*/
#include <iostream>
using namespace std;

struct Point 
{
    int x;
    int y;
};

void draw_line(Point start, Point end)
{
    cout << start.x << endl;
}

int main()
{
    Point start{1, 2};
    Point end{5, 6};
    draw_line(start, end);
    return 0;
}
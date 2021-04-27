#include <iostream>
using namespace std;

#define RED 0
const int GREEN = 1;
// BLUE ORANGE AND YELLOW HAVE GLOBAL SCOPE!
enum Color{BLUE, ORANGE, YELLOW};

// you can assign values yourself
enum class Color_scoped{GREEN=5, BLUE, ORANGE, PURPLE};

void fill_color(int color) {

}

void fill_color_enum(Color color)
{

}

void fill_color_enum_scoped(Color_scoped color)
{

}

int main() {
    fill_color(RED);
    fill_color(GREEN);
    fill_color(6); // still correct call

    // global scope of enum members
    fill_color_enum(BLUE);

    Color new_color = ORANGE;
    fill_color_enum(new_color);
    fill_color(new_color);

    // integer not implicitly converted to enum type
    //fill_color_enum(5);
    fill_color_enum(static_cast<Color>(3));

    // you can create a scoped enum
    // PURPLE IS NOT KNOWN IN GLOBAL SCOPE
    //fill_color_enum(PURPLE);
    fill_color_enum_scoped(Color_scoped::PURPLE);

    // no implicit cast to int for scoped enums!
    //int x = Color_scoped::PURPLE;
    int x = static_cast<int>(Color_scoped::PURPLE);
    //fill_color(Color_scoped::PURPLE);

    return 0;
}
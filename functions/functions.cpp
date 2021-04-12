#include <iostream>
using namespace std;
#include "math.h"

// <return type> <name> <parameters> {<function body>}

int main(void)
{
    int x, y;
    cin >> x >> y;
    int result = Add(x,y);
    cout << "The result of summing " << x << " and " << y << " is: " << result << endl;
    return 0;
}

/*
<return type> operator "" _<literal> (<arguments>)
return type: can be any type, including void
_<literal>: always starts with _(underscore) followed by a name (without _ is reserved by std library)
<arguments>: can be of the following types:
    - integer - unsigned long long (if you use integers, arugment type should be unsigned long long)
    - floating point - long double
    - character - char, wchar_t, char16_t, char32_t
    - string - const char *

You cannot redefine built in literal suffixes
these always need to be global functions, no members functions
*/

#include <iostream>
using namespace std;

class Distance {
    long double m_km;
public:
    Distance(long double km): m_km{km} { }
    long double get_km() const {
        return m_km;
    }
    void set_km(long double km) {
        m_km = km;
    }
};

Distance operator"" _mi(long double val) {
    return Distance(val * 1.6);
}

Distance operator"" _meters(long double val) {
    return Distance(val / 1000);
}

int main() {
    Distance dist{32.0_mi};
    cout << "dist was 32 miles in km: " << dist.get_km() << endl;

    Distance dist2{1200.0_meters};
    cout << "dist was 1200 meters in km: " << dist2.get_km() << endl;
}
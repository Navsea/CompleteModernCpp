// no longer in experimental in gcc8
#include <experimental/filesystem>
#include <iostream>
using namespace std;

int main() {
    using namespace std::experimental::filesystem;
    // you can pass any string in the constructor, its not checked
    path p { R"(/home/kenneth/Cpp/CompleteModernCpp/Helloworld.cpp)" };
    path p2 { R"(/home/kenneth/Cpp/CompleteModernCpp/)" };
    if (p.has_filename()) {
        cout << p.filename() << endl;
    }
    for (const auto &x: p) {
        cout << x << endl;
    }

    directory_iterator begin{p2};
    directory_iterator end{};
    while (begin != end) {
        cout << *begin << endl;
        begin++;
    }
    return 0;
}
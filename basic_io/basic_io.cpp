#include <iostream>
using namespace std;

int main(void)
{
    // endl will enter new line and flush the buffer (so that its written to console)
    cout << "Hello world!" << endl;
    int age;
    cout << "What is your age?" << endl;
    cin >> age;
    cout << "Your age is: " << age << endl;


    char name[50]; 
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "Your name is: " << name << endl;
    // To remove the previous endline charachter \n from the previous input
    cin.ignore(50, '\n');

    // Note that when you enter a space, cin will stop reading the keyboard
    // use getline for that purpope
    char full_name[100]; 
    cout << "What is your full name?" << endl;
    cin.getline(full_name, 20, '\n');
    cout << "Your full name is: " << full_name << endl;

    return 0; 
}
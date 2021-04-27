#include <iostream>
using namespace std;
#include <memory>

class Employee;

class Project {
public:
    Employee * m_em;
    Project() {
        cout << "Project()" << endl;
    }
    ~Project() {
        cout << "~Project()" << endl;
    }
};

class Employee {
public:
    Project *m_proj;
    Employee() {
        cout << "Employee()" << endl;
    }
    ~Employee() {
        cout << "~Employee()" << endl;
    }
};

class EmployeeSh;

class ProjectSh {
public:
    shared_ptr<EmployeeSh> m_em;
    ProjectSh() {
        cout << "ProjectSh()" << endl;
    }
    ~ProjectSh() {
        cout << "~ProjectSh()" << endl;
    }
};

class EmployeeSh {
public:
    shared_ptr<ProjectSh> m_proj;
    EmployeeSh() {
        cout << "EmployeeSh()" << endl;
    }
    ~EmployeeSh() {
        cout << "~EmployeeSh()" << endl;
    }
};

class EmployeeWk;
class ProjectWk {
public:
    shared_ptr<EmployeeWk> m_em;
    ProjectWk() {
        cout << "ProjectWk()" << endl;
    }
    ~ProjectWk() {
        cout << "~ProjectWk()" << endl;
    }
};

class EmployeeWk {
public:
    weak_ptr<ProjectWk> m_proj;
    EmployeeWk() {
        cout << "EmployeeWk()" << endl;
    }
    ~EmployeeWk() {
        cout << "~EmployeeWk()" << endl;
    }
};

int main() {
    Employee *e = new Employee{};
    Project *proj = new Project{};
    e->m_proj = proj;
    proj->m_em = e;

    delete e;
    delete proj;

    // SAME USING SHARED PTRS
    shared_ptr<EmployeeSh> esh{new EmployeeSh{}};
    shared_ptr<ProjectSh> projsh{new ProjectSh{}};

    esh->m_proj = projsh;
    projsh->m_em = esh;

    // NOTE THAT MEMORY IS NOT RELEASED!!!!
    // Theres a circular reference!!
    // This can be solved by weak ptrs! because weak ptr does not increase the ref count (unless you call .lock())
    shared_ptr<EmployeeWk> ewk2{new EmployeeWk{}};
    shared_ptr<ProjectWk> projwk2{new ProjectWk{}};

    ewk2->m_proj = projwk2;  // Initalize weak ptr to counter block of projsh2
    projwk2->m_em = ewk2;

    // Now everything is nicely released
}
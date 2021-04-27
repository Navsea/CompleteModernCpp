#include <iostream>
using namespace std;
#include <memory>
#include "Integer.h"

class Project {
public:
    ~Project() {
        cout << "~Project()" << endl;
    }
};

class Employee {
    Project *m_project;
public:
    void set_project(Project *proj) {
        m_project = proj;
    }
    Project* get_project() const {
        return m_project;
    }
};

// class EmployeeUniquePtr {
//     unique_ptr<Project> m_project;
// public:
//     // has to be passed by ref, as not copy can be created
//     void set_project(unique_ptr<Project> &proj) {
//         // but here you would still try to use copy assigment
//         m_project.reset(proj);
//     }
//     unique_ptr<Project> get_project() const{
//         return m_project;
//     }
// };

class EmployeeSharedPtr {
    shared_ptr<Project> m_project;
public:
    // here a copy is created of shared_ptr: ref count = 2
    void set_project(const shared_ptr<Project> proj) {
        // here another copy is created ref counter = 3 (copy of shared_ptr not of underlying resource)
        m_project = proj;
    }
    shared_ptr<Project> get_project() const{
        return m_project;
    }
};

// where should we delete the project?
// we cannot do it in descructor of employee, because multiple employees have the same project
// unique ptr is meant for pointers that are not shared
// shared ptr is meant for this
Employee * assign_project() {
    Project *p = new Project{};
    Employee *e1 = new Employee{};
    e1->set_project(p);
    return e1;
}

shared_ptr<EmployeeSharedPtr> assign_project_shared() {
    shared_ptr<Project> p{new Project{}};
    shared_ptr<EmployeeSharedPtr> e1{new EmployeeSharedPtr{}};
    e1->set_project(p);
    // at this point 2 copies of shared ptr exist
    // one for p and one for the shared ptr inside EmployeeSharedPtr
    return e1;
}   // when exiting local shared_ptr p is destroyed

int main() {
    shared_ptr<EmployeeSharedPtr> e = assign_project_shared();
    // When employee ptr is deleted, the underlying resource will be deleted

    if (e == nullptr)
    {

    }
    e.get();
    e.reset(new EmployeeSharedPtr{});
}
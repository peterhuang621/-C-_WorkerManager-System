#include "employee.h"

Employee::Employee(int id, string name, int did)
{
    this->m_id = id;
    this->m_dept = did;
    this->m_name = name;
};

void Employee::showinfo()
{
    cout << "ID: " << this->m_id << "\t"
         << "Name: " << this->m_name << "\t"
         << "Dept: " << this->m_dept << "\t"
         << "Respon: Finish the job assigned by the manager." << endl;
};
string Employee::getdeptname() { return "A normal worker."; };
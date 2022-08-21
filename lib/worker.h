#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>

class Worker
{
public:
    virtual void showinfo() = 0;
    virtual string getdeptname() = 0;

    int m_id;
    string m_name;
    int m_dept;
};
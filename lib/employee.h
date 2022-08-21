#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "worker.h"

class Employee : public Worker
{
public:
    Employee(int id, string name, int did);
    virtual void showinfo();
    virtual string getdeptname();
};
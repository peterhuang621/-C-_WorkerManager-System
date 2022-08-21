#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>
#include "worker.h"

class Manager : public Worker
{
public:
    Manager(int id, string name, int did);
    virtual void showinfo();
    virtual string getdeptname();
};
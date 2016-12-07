#pragma once
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
namespace Program {

    const int limit = 20;
    using namespace std;

    class Items {

    private:
        int ID;
        char Name[limit];
        int Cost;
        int Habarytes;
    public:
        void setID(int);

        int  getID();

        void setName(char * Name);

        char*  getName();

        void setCost(int);

        int  getCost();

        void setHabarytes(int);

        int  getHabarytes();

    };

    class User
    {
    private:
        int ID;
        char Name[limit];
        char Surname[limit];
        char Login[limit];
        char Password[limit];
        int Status;
    public:
        void setID(int);

        int  getID();

        void setName(char * Name);

        char*  getName();

        void setSurname(char * Surname);

        char*  getSurname();

        void setLogin(char * Login);

        char*  getLogin();

        void setPassword(char * Password);

        char* getPassword();

        void setStatus(int);

        int getStatus();

    };
}


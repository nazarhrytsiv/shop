//
// Created by Nazar on 02.12.2016.
//

#include "shop.h"
using namespace std;
namespace Program {



    void Items::setID(int id)
    {
        ID = id;
    }

    int Items::getID() {
        return ID;
    }


     void Items::setName(char * name) {
          strcpy(Name,name);
      }

    char* Items::getName() {
        return Name;
    }

    void Items::setCost(int cost)
    {
        Cost = cost;
    }

    int Items::getCost() {
        return Cost;
    }

    void Items::setHabarytes(int habarytes)
    {
        Habarytes = habarytes;
    }

    int Items::getHabarytes() {
        return Habarytes;
    }


    void User::setID(int id)
    {
        ID = id;
    }

    int User::getID() {
        return ID;
    }


    void User::setName(char * name) {
        strcpy(Name,name);
    }

    char* User::getName() {
        return Name;
    }

    void User::setSurname(char * surname)
    {
        strcpy(Surname,surname);
    }

    char* User::getSurname() {
        return Surname;
    }

    void User::setLogin(char * login)
    {
        strcpy(Login,login);
    }

    char* User::getLogin() {
        return Login;
    }

    void User::setPassword(char * password)
    {
        strcpy(Password,password);
    }

    char* User::getPassword() {
        return Password;
    }

    void User::setStatus(int status)
    {
        Status = status;
    }

    int User::getStatus() {
        return Status;
    }

 }

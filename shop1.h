#include "shop.h"

using namespace std;
using Program::Items;
using Program::User;

int FirstMenu();
int back();
int fChoose();
void OutputItems(Items & item1);
void AddNewItem(Items & item1, FILE *dataF);
void ChangePrice(vector<Items> &items);
void WriteItemsToFile(vector<Items> &items , FILE *dataF);
void AddNewUser(User & user1, vector<User> & user, FILE *logPass);
void WriteUserToFile(vector<User> &users, FILE * logPass);
void Revice( vector<User> & user);


void OutputItems(Items & item1)
{
    cout << item1.getID() << "\t" << item1.getName() << "\t" << item1.getHabarytes() << "\t" << item1.getCost() << endl;
}



void AddNewItem(Items & item1, FILE *dataF)
{
    int id, habarytes, cost;
    char name[20];
    cout << "enter id: " << endl;
    cin >> id;
    cout << "enter name" << endl;
    cin >> name;
    cout << "enter Weight" << endl;
    cin >> habarytes;
    cout << "enter Price" << endl;
    cin >> cost;
    item1.setID(id);
    item1.setName(name);
    item1.setHabarytes(habarytes);
    item1.setCost(cost);
}

void ChangePrice(vector<Items> &items)
{
    int id, cost;
    cout << "enter id of product to change price: " << endl;
    cin >> id;
    cout << "enter new price" << endl;
    cin >> cost;
    for (int i = 0; i < items.size(); ++i)
    {
        if (items[i].getID() == id)
        {
            cout << "name of product to change cost: " << items[i].getName() << endl;
            items[i].setCost(cost);
            break;
        }
    }

}


void WriteItemsToFile(vector<Items> &items, FILE * dataF)
{
    for (int i = 0; i < items.size(); ++i)
    {
        fprintf(dataF, "%i %s %i %i\n", items[i].getID(), items[i].getName(), items[i].getCost(), items[i].getHabarytes());
    }
}




void AddNewUser(User & user1, vector<User> & user, FILE *logPass)
{
    int id, status;
    char name[20];
    char surname[20];
    char login[20];
    char password[20];
    cout << "enter id: " << endl;
    cin >> id;
    cout << "enter name" << endl;
    cin >> name;
    cout << "enter surname" << endl;
    cin >> surname;
    cout << "enter login" << endl;
    cin >> login;
    for (int i = 0; i < user.size(); ++i)
    {

        if(!strcmp(user[i].getLogin(), login)) {
            do {
                cout << "Try another login: " << endl;
                cin >> login;
            } while ((!strcmp(user[i].getLogin(), login)));
        }
    }
    cout <<"Enter password: ";
    cin >> password;
    cout << "Enter status: "<< endl;
    cin >> status;
    user1.setID(id);
    user1.setName(name);
    user1.setSurname(surname);
    user1.setLogin(login);
    user1.setPassword(password);
    user1.setStatus(status);
}

void Revice(vector <User> & user)
{
    char login[20], password[20];
    cout << "Enter your login: " ;
    cin >> login;
    cout << endl;
    cout <<"Enter your password: ";
    cin >> password;
    for (int i = 0; i < user.size(); ++i)
    {

        if((strcmp(user[i].getLogin(), login) != 0 || strcmp(user[i].getPassword(), password) != 0)) {
            do {
                cout << "Try another login: " ;
                cin >> login;
                cout << endl;
                cout <<"Try another password: ";
                cin >> password;
            } while ((strcmp(user[i].getLogin(), login) != 0 || strcmp(user[i].getPassword(), password) != 0));
        }
    }
}


void WriteUserToFile(vector<User> &user, FILE * logPass)
{
    for (int i = 0; i < user.size(); ++i)
    {
        fprintf(logPass, "%i %s %s %s %s %i\n", user[i].getID(), user[i].getName(), user[i].getSurname(), user[i].getLogin(), user[i].getPassword(), user[i].getStatus());
    }
}

int fChoose() {
    int choose;

    cout << "1)Watch" << endl;
    cout << "2)Add" << endl;
    cout << "3)Change" << endl;
    cout << "4)Back" << endl;


    cin >> choose;
    return choose;
}

int back() {
    int choose;
    cout << "1)Back" << endl;
    cin >> choose;
    if (choose != 1) {
        while (choose != 1) {
            cout << "Write a correct number!" << endl;
            cout << "1)Back" << endl;
            cin >> choose;
            if (choose == 1) {
                break;
            }
        }
    }
    return choose;
}

int FirstMenu() {
    int choose;
    cout << "1)Registation" << endl;
    cout << "2)Log in" << endl;
    cout << "3)Exit" << endl;
    cin >> choose;
    return choose;
}
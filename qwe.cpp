#include "shop.h"
#include "shop1.h"
using namespace std;
using Program::Items;
using Program::User;

int main()
{
    vector<Items> items;
    Items item1;
    vector<User> user;
    User user1;
    FILE *dataF = NULL;
    dataF = fopen("datafile.txt", "r+");
    FILE *logPass = NULL;
    logPass = fopen("logPass.txt", "r+");
     if (dataF != NULL)
     {
         while (!feof(dataF))
         {
             int cost, habarytes, id;
             char name[20];
             fscanf(dataF, "%i%s%i%i", &id, &name, &cost, &habarytes);
             item1.setCost(cost);
             item1.setName(name);
             item1.setHabarytes(habarytes);
             item1.setID(id);
             items.push_back(item1);
         }
         items.pop_back();
         // clean datafile
         dataF = fopen("datafile.txt", "w+");
         if (dataF == NULL)
         {
             cout << "Cannot open datafile.txt for writing" << endl;
         }
     }
     else
     {
         cout << "Cannot open file datafile.txt" << endl;
     }
     if (logPass != NULL)
     {
         while (!feof(logPass))
         {
             int status, id;
             char name[20];
             char surname[20];
             char login[20];
             char password[20];
             fscanf(logPass, "%i%s%s%s%s%i", &id, &name, &surname, &login, &password, &status);
             user1.setID(id);
             user1.setName(name);
             user1.setSurname(surname);
             user1.setLogin(login);
             user1.setPassword(password);
             user1.setStatus(status);
             user.push_back(user1);
         }
         user.pop_back();
         // clean datafile
         logPass = fopen("logPass.txt", "w+");
         if (logPass == NULL)
         {
             cout << "Cannot open logPass.txt for writing" << endl;
         }
     }
     else
     {
         cout << "Cannot open file logPass.txt" << endl;
     }

    int iChoose = 0;
    int num = items.size();
    while (iChoose !=3) {
        iChoose = FirstMenu();

        switch (iChoose) {
            case 1: {
                system("cls");
                ///registration
                AddNewUser(user1,user,logPass);
                user.push_back(user1);
                break;
            }

            case 2: {
                system("cls");
                Revice(user);



                while (iChoose != 4) {
                    iChoose = fChoose();

                    switch (iChoose) {
                        case 1: {
                            system("cls");
                            for (int i = 0; i < num; ++i)
                                OutputItems(items[i]);
                            cout << endl;

                            if (back() == 1) {
                                system("cls");
                                break;
                            }
                        }


                        case 2: {
                            AddNewItem(item1, dataF);
                            items.push_back(item1);
                            num = items.size();
                            if (back() == 1) {
                                system("cls");
                                break;
                            }
                        }

                        case 3: {
                            system("cls");
                            for (int i = 0; i < num; i++)
                                OutputItems(items[i]);
                            ChangePrice(items);

                            if (back() == 1) {
                                system("cls");
                                break;
                            }
                        }
                        case 4: {
                            system("cls");
                            break;
                        }
                    }
                }
            }
            case 3: {
                system("cls");
                cout << "Good bye.";
                break;
            }
        }
    }
    WriteItemsToFile(items,dataF);
    WriteUserToFile(user,logPass);
    fclose(dataF);
    fclose(logPass);
    system("pause");
    return 0;
}
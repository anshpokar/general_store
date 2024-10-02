#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string itemID, itemName;
    int itemQuantity, itemPrice;
    fstream file, file1;
    int totalAmount, quantity, itemRate;
    string search;
    char _choice;

public:
    void addproduct(void);
    void viewproduct(void);
    void buyproduct(void);
} obj;

int main()
{
    char choice;
    cout << "press 1 --> Start Shopping" << endl;
    cout << "press 0 --> Exit" << endl;
    cin >> choice;
    switch (choice)
    {
    case 'A':
        obj.addproduct();
        break;
    case '1':
        obj.viewproduct();
        obj.buyproduct();
        break;
    case '0':
        system("exit");
        break;
    default:
        cout << "invalid selection...!";
        break;
    }
    return 0;
}

void temp ::addproduct()
{
    cout << "Enter Product ID :: ";
    cin >> itemID;
    cout << "Enter Product Name :: ";
    cin >> itemName;
    cout << "Enter Product Quantity :: ";
    cin >> itemQuantity;
    cout << "Enter Product Price :: ";
    cin >> itemPrice;

    file.open("data.txt", ios ::out | ios ::app);
    file << "\t" << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
    file.close();
}

void temp ::viewproduct()
{
    file.open("data.txt", ios ::in);
    file >> itemID >> itemName >> itemQuantity >> itemPrice;

    while (!file.eof())
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << "Product ID\t\tProduct Name\t\tQuantity\t\tProduct Price" << endl;
        cout << itemID << "\t\t\t" << itemName << "\t\t\t" << itemQuantity << "\t\t\t" << itemPrice << endl;
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        file >> itemID >> itemName >> itemQuantity >> itemPrice;
    }
    file.close();
}

void temp ::buyproduct()
{
    _choice = 'y';

    while (_choice = +'y')
    {

        file.open("data.txt", ios ::in);
        file1.open("temp.txt", ios ::out | ios ::app);
        file >> itemID >> itemName >> itemQuantity >> itemPrice;

        cout << "Enter Product Id :: ";
        cin >> search;
        cout << "Enter Quantity :: ";
        cin >> quantity;

        while (!file.eof())
        {
            if (itemID == search)
            {
                itemQuantity = itemQuantity - quantity;
                file << "\t" << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;

                itemRate = quantity * itemPrice;
                totalAmount = totalAmount + itemRate;
                cout << "------------------Payment Bill------------------" << endl;
                cout << "Total Purchase Amount :: " << totalAmount << endl;
                cout << "----------------------------------------------------" << endl;
            }
            else
            {
                file << "\t" << itemID << "\t" << itemName << "\t" << itemQuantity << "\t" << itemPrice << endl;
            }
            file >> itemID >> itemName >> itemQuantity >> itemPrice;
        }
        file.close();
        file1.close();
        remove("data.txt");
        rename("temp.txt","data.txt");
    }
    cout << "\n Continue Shopping ? (Y / N) ";
    cin >> _choice;
}
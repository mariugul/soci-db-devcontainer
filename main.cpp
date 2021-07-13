#include "terminalColors.hpp"
#include <iostream>
#include <soci.h>
#include <postgresql/soci-postgresql.h>

using namespace soci;
using namespace std;

bool get_name(string &name) {
    cout << "Enter name: ";
    cin >> name;
    if(name != "")
        return true;
    else 
        return false;
}

int main() {
    cout << "Hello SOCI Dev!\n\n";
    
    try
    {
        session sql(postgresql, "dbname=mydb");
        
        int count;
        sql << "", into(count);

        cout << "We have " << count << " entries in the phonebook.\n";

        string name;

        while (get_name(name))
        {
            string phone;
            indicator ind;
            sql << "select phone from phonebook where name = :name",
                into(phone, ind), use(name);

            if (ind == i_ok)
            {
                cout << "The phone number is " << phone << '\n';
            }
            else
            {
                cout << "There is no phone for " << name << '\n';
            }
        }
    }
    catch(const exception& e)
    {
        cerr << BOLDRED << e.what() << RESET << '\n';
    }
    
    // cout 
    //     << YELLOW 
    //     << "This example runs SOCI as a standalone container. " 
    //     << "Therefore, you would need to communicate with the database through a network \n" 
    //     << "by spinning up a PostreSQL server on another container, using Docker Compose.\n\n"
    //     << RESET;

    return 0;
}
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
        session sql(postgresql, "dbname=postgres user=postgres");
        
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

    return 0;
}
#include "terminalColors.hpp"
#include <iostream>
#include <soci.h>
#include <postgresql/soci-postgresql.h>

using namespace soci;
using namespace std;

int main() {

    cout << "---------------------------\n" << "Hello SOCI developer!\n\n";
    
    try
    {
        const string databaseName = "postgres";
        const string userName = "postgres";
        const string connectionString = "dbname=" + databaseName + " user=" + userName;

        session sql(postgresql, connectionString);

        // Check for successful connection
        if (!sql.is_connected()) return 0; // This might already be checked when creating the sql object
        cout << "Connected to database " << GREEN << databaseName << "\n" << RESET;
        
        // Does table exist?
        bool tableExists = false;
        string tableName;
        sql.get_table_names(), into(tableName);
        tableName == "" ? tableExists = false : tableExists = true; // This test is only valid because I test this one table and only that

        // Create table "colors"
        if (!tableExists){
            sql.create_table("colors")
                .column("id", dt_integer)
                .column("Red", dt_string)
                .column("Green", dt_string)
                .column("Blue", dt_string)
                .primary_key("colors_pk", "id");
            cout << "Successfully created table 'colors'\n";
        }
        else {
            cout << "Table 'colors' exists already.\n";
        }
    }  
    catch(const exception& e)
    {
        cerr << BOLDRED << e.what() << RESET << '\n';
    }

    return 0;
}
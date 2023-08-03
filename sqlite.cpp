#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    int rc = sqlite3_open("database.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Create a table if it doesn't exist
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Insert data into the table
    const char* insertDataSQL = "INSERT INTO users (name, age) VALUES ('John', 30), ('Alice', 25);";
    rc = sqlite3_exec(db, insertDataSQL, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "Error inserting data: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // Retrieve data from the table
    const char* selectDataSQL = "SELECT id, name, age FROM users;";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, selectDataSQL, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int age = sqlite3_column_int(stmt, 2);

        std::cout << "ID: " << id << ", Name: " << name << ", Age: " << age << std::endl;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

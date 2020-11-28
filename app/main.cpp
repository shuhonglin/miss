#include <iostream>
#include <iomanip>
// #include "../../external/mysql-connector-cpp/include/mysqlx/xdevapi.h"
#include "entity/book.h"
#include "../build/include/jdbc/mysql_driver.h"
#include "../build/include/jdbc/mysql_connection.h"
#include "../build/include/jdbc/cppconn/driver.h"
#include "../build/include/jdbc/cppconn/statement.h"
#include "../build/include/jdbc/cppconn/prepared_statement.h"
#include "../build/include/jdbc/cppconn/metadata.h"
#include "../build/include/jdbc/cppconn/exception.h"

void testMysql();

int main(int, char **)
{
    int a = 4, b = 5;
    int mix = 4 * 5;
    testMysql();
    std::cout << "Hello, world!\n"
              << mix << std::endl;

    const std::string isbn = "xxxx";
    const std::string name = "c++ primer";
    Book book = Book(name, isbn);
    book.printBook();
    return 0;
}

void testMysql()
{
    using namespace std;
    sql::mysql::MySQL_Driver *driver = 0;
    sql::Connection *conn = 0;

    // try
    // {
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306/zgame", "hackway", "0663");
    cout << "connect success" << endl;
    // }
    // catch (...)
    // {
    //     cout << "connect fail" << endl;
    //     return;
    // }
    sql::Statement *stat = conn->createStatement();
    // stat->execute("set names 'gbk'");
    sql::ResultSet *res;
    res = stat->executeQuery("SELECT * FROM tb_player");
    while (res->next())
    {
        cout << setiosflags(ios::left) << setw(14) << res->getString("id") << resetiosflags(ios::left)
             << setiosflags(ios::right) << setw(9) << res->getString("name") << setw(12) << res->getString("createTime") << setw(8) << res->getString("level")
             << resetiosflags(ios::right) << endl;
    }
    if (conn != 0)
    {
        delete conn;
    }
}

#include <iostream>
#include <iomanip>
// #include "../../external/mysql-connector-cpp/include/mysqlx/xdevapi.h"
#include "entity/book.h"
#include "mysqlx/xdevapi.h"

int testMysql();

void testMysqlV2();

int main(int, char **)
{
    int a = 4, b = 5;
    int mix = 4 * 5;
    int result = testMysql();
    std::cout << "Hello, world!\n"
              << mix << std::endl
              << result << std::endl;

    const std::string isbn = "xxxx";
    const std::string name = "c++ primer";
    Book book = Book(name, isbn);
    book.printBook();
}

int testMysql()
{
    using namespace std;
    using namespace ::mysqlx;
    try
    {
        // mysqlx://user:pwd@host:port/db?ssl-mode=disabled
        const char *url = "mysqlx://root:123456@192.168.0.10:33060?ssl-mode=disabled";
        cout << "Creating session on " << url << " ..." << endl;
        Session sess(url);
//         {
//             /*
//     TODO: Only working with server version 8
//   */
//             RowResult res = sess.sql("show variables like 'version'").execute();
//             std::stringstream version;
//             version << res.fetchOne().get(1).get<string>();
//             int major_version;
//             version >> major_version;
//             if (major_version < 8)
//             {
//                 cout << "Version: " << major_version << " Done!" << endl;
//                 return 0;
//             }
//         }
        SqlResult rset = sess.sql("SELECT * FROM zgame.tb_player LIMIT 20").execute();

        cout << setiosflags(ios::left) << setw(14) << "id" << resetiosflags(ios::left) // 用完之后清除
         << setiosflags(ios::right) << setw(9) << "name" << setw(12) << "createtime" << setw(8) << "level"
         << resetiosflags(ios::right) << endl;
        cout << "----------------------------------------" << endl;
        Row row;
        while (rset.hasData())
        {
            row = rset.fetchOne();
            if (row.isNull())
            {
               cout << "row is null" << endl;
               break;
            }
            cout << setiosflags(ios::left) << setw(14) << row.get(0).get<long>() << resetiosflags(ios::left)
                << setiosflags(ios::right) << setw(9) << row.get(2).get<std::string>() << setw(12) << row.get(4).get<int>() << setw(8) << row.get(5).get<int>()
                << resetiosflags(ios::right) << endl;
            // cout << "         id: " << row.get(0).get<long>() << endl;
            // cout << "       name: " << row.get(2).get<std::string>() << endl;
            // cout << " createtime: " << row.get(4).get<int>() << endl;
            // cout << "      level: " << row.get(5).get<int>() << endl;
        }
        cout << "----------------------------------------" << endl;
        sess.close();
        cout << "Done!" << endl;
    }
    catch (const mysqlx::Error &err)
    {
        cout << "ERROR: " << err << endl;
        return 1;
    }
    catch (std::exception &ex)
    {
        cout << "STD EXCEPTION: " << ex.what() << endl;
        return 1;
    }
    catch (const char *ex)
    {
        cout << "EXCEPTION: " << ex << endl;
        return 1;
    }
}
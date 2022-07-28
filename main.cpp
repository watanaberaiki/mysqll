#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "Soratomo@90";

int main()
{
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	sql::ResultSet* result;


	try
	{
		driver = get_driver_instance();
		con = driver->connect(server, username, password);
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}

	//please create database "quickstartdb" ahead of time
	con->setSchema("db1");

	////ƒe[ƒuƒ‹ì¬
	//stmt = con->createStatement();
	//stmt->execute("DROP TABLE IF EXISTS inventory");
	//cout << "Finished dropping table (if existed)" << endl;
	//stmt->execute("CREATE TABLE sample(id serial PRIMARY KEY, num INTEGER, name VARCHAR(50));");
	//cout << "Finished creating table" << endl;
	//delete stmt;

	////INSERT
	//pstmt = con->prepareStatement("INSERT INTO sample(num, name) VALUES(?,?)");
	//pstmt->setString(2, "banana");
	//pstmt->setInt(1, 150);
	//pstmt->execute();
	//cout << "One row inserted." << endl;

	//pstmt->setString(2, "orange");
	//pstmt->setInt(1, 154);
	//pstmt->execute();
	//cout << "One row inserted." << endl;

	//pstmt->setString(2, "apple");
	//pstmt->setInt(1, 100);
	//pstmt->execute();
	//cout << "One row inserted." << endl;


	////update
	//pstmt = con->prepareStatement("UPDATE sample SET num = ? WHERE name = ?");
	//pstmt->setInt(1, 200);
	//pstmt->setString(2, "banana");
	//pstmt->executeQuery();
	//printf("Row updated\n");


	////delete
	//pstmt = con->prepareStatement("DELETE FROM sample WHERE name = ?");
	//pstmt->setString(1, "orange");
	//result = pstmt->executeQuery();
	//printf("Row deleted\n");

	//pstmt->setString(1, "banana");
	//result = pstmt->executeQuery();
	//printf("Row deleted\n");

	//pstmt->setString(1, "apple");
	//result = pstmt->executeQuery();
	//printf("Row deleted\n");


	//select  
	pstmt = con->prepareStatement("SELECT * FROM sample;");
	result = pstmt->executeQuery();

	while (result->next())
		printf("Reading from table=(%d, %d, %s)\n", result->getInt(1), result->getInt(2), result->getString(3).c_str());





	delete result;
	delete pstmt;
	delete con;
	system("pause");
	return 0;
}
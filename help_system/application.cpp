#include "application.h"
#include "ftp_comunication.h"
#include <iostream>
#include <ctime>


extern std::string table_struct =
"CREATE TABLE IF NOT EXISTS Person(" \
"ID INT PRIMARY KEY     NOT NULL, " \
"NAME           VARCHAR NOT NULL, " \
"AGE            INT     NOT NULL, " \
"ADDRESS        VARCHAR, " \
"SALARY         REAL );";

extern std::string table_info_insertion = "INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (3, 'Teddy', 23, 'Norway', 20000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (4, 'Mark', 25, 'Rich-Mond', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (5, 'Alen', 21, 'New York', 16000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (6, 'David', 22, 'New York', 25000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (7, 'Jhon', 21, 'Yerevan', 62000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (8, 'Mark', 26, 'Yerevan', 41000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (9, 'Mark', 25, 'Yerevan', 26000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (10, 'Mark', 29, 'Rich-Mond', 35000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (11, 'David', 21, 'Berlin', 19000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (12, 'Jhon', 55, 'Rich-Mond', 34000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (13, 'Mark', 35, 'New York', 86000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (14, 'Mark', 45, 'New York', 72000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (15, 'Mark', 26, 'Rich-Mond', 96000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (16, 'David', 45, 'Moskov', 38000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (17, 'Mark', 29, ' Moskov', 14000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (18, 'Jhon', 25, 'Rome', 29000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (19, 'Mark', 35, 'Rome', 24000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (20, 'Mark', 23, 'Rome', 33000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (21, 'David', 25, 'Moskov', 36000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (22, 'Mark', 32, 'Moskov', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (23, 'Valod', 54, 'Moskov', 62000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (24, 'Allen', 32, 'Berlin', 18000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (25, 'Mark', 23, 'Yerevan', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (26, 'Jhon', 21, 'Yerevan', 59000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (27, 'Mark', 29, 'Yerevan', 63000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (28, 'Jhon', 25, 'Yerevan', 61000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (29, 'Mark', 22, 'Yerevan', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (30, 'Allen', 21, 'Berlin', 64000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (31, 'Jhon', 25, 'Berlin', 69000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (32, 'Allen', 25, 'Yerevan', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (33, 'Joe', 29, 'Oslo', 42000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (34, 'Paul', 25, 'Oslo', 35000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (35, 'Mark', 35, 'Oslo', 75000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (36, 'Jhon', 25, 'Oslo', 95000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (37, 'Allen', 32, 'Berlin', 85000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (38, 'Mark', 25, 'Rome', 69000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (39, 'Valod', 42, 'Rome', 78000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (40, 'Mark', 45, 'Rome', 75000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (41, 'Paul', 32, 'Dalas', 20000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (42, 'Allen', 25, 'Texas', 15000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (43, 'Teddy', 23, 'Norway', 20000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (44, 'Mark', 25, 'Rich-Mond', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (45, 'Alen', 21, 'New York', 16000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (46, 'David', 22, 'New York', 25000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (47, 'Jhon', 21, 'Yerevan', 62000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (48, 'Mark', 26, 'Yerevan', 41000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (49, 'Mark', 25, 'Yerevan', 26000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (50, 'Mark', 29, 'Rich-Mond', 35000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (51, 'David', 21, 'Berlin', 19000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (52, 'Jhon', 55, 'Rich-Mond', 34000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (53, 'Mark', 35, 'New York', 86000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (54, 'Mark', 45, 'New York', 72000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (55, 'Mark', 26, 'Rich-Mond', 96000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (56, 'David', 45, 'Moskov', 38000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (57, 'Mark', 29, ' Moskov', 14000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (58, 'Jhon', 25, 'Rome', 29000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (59, 'Mark', 35, 'Rome', 24000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (60, 'Mark', 23, 'Rome', 33000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (61, 'David', 25, 'Moskov', 36000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (62, 'Mark', 32, 'Moskov', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (63, 'Valod', 54, 'Moskov', 62000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (64, 'Allen', 32, 'Berlin', 18000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (65, 'Mark', 23, 'Yerevan', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (66, 'Jhon', 21, 'Yerevan', 59000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (67, 'Mark', 29, 'Yerevan', 63000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (68, 'Jhon', 25, 'Yerevan', 61000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (69, 'Mark', 22, 'Yerevan', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (70, 'Allen', 21, 'Berlin', 64000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (71, 'Jhon', 25, 'Berlin', 69000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (72, 'Allen', 25, 'Yerevan', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (73, 'Joe', 29, 'Oslo', 42000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (74, 'Paul', 25, 'Oslo', 35000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (75, 'Mark', 35, 'Oslo', 75000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (76, 'Jhon', 25, 'Oslo', 95000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (77, 'Allen', 32, 'Berlin', 85000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (78, 'Mark', 25, 'Rome', 69000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (79, 'Valod', 42, 'Rome', 78000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (80, 'Mark', 29, 'Rich-Mond', 35000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (81, 'David', 21, 'Berlin', 19000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (82, 'Jhon', 55, 'Rich-Mond', 34000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (83, 'Mark', 35, 'New York', 86000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (84, 'Mark', 45, 'New York', 72000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (85, 'Mark', 26, 'Rich-Mond', 96000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (86, 'David', 45, 'Moskov', 38000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (87, 'Mark', 29, ' Moskov', 14000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (88, 'Jhon', 25, 'Rome', 29000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (89, 'Mark', 35, 'Rome', 24000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (90, 'Mark', 23, 'Rome', 33000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (91, 'David', 25, 'Moskov', 36000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (92, 'Mark', 32, 'Moskov', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (93, 'Valod', 54, 'Moskov', 62000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (94, 'Allen', 32, 'Berlin', 18000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (95, 'Mark', 23, 'Yerevan', 55000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (96, 'Jhon', 21, 'Yerevan', 59000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (97, 'Mark', 29, 'Yerevan', 63000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (98, 'Jhon', 25, 'Yerevan', 61000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (99, 'Mark', 22, 'Yerevan', 60000.00 ); " \
"INSERT INTO Person (ID,NAME,AGE,ADDRESS,SALARY) VALUES (100, 'Allen', 21, 'Berlin', 64000.00 ); ";

extern std::string table_select_person = "SELECT * FROM Person;";


bool application::exec() 
{
	std::cout << "call = " << __func__ << std::endl;
	try 
	{
		std::cout << "APP Start Working ....." << std::endl;
		//Parse recived arguments to std::map<std::string, std::string> using class param_parser 
		param_parser* p = new param_parser(m_argc, m_argv);
		std::map<std::string, std::string> params_map = p->parse();
		delete p;
		p = nullptr;
		std::cout << "Parameters parsing is done " << std::endl;
		std::cout << "Start Create db" << std::endl;

		std::string file_name = "new_database_01";

		std::srand(time(0));
		int i = std::rand();
		i = i % 1000;
		file_name = file_name + std::to_string(i);

		std::cout << "filename db = " << file_name << std::endl;


		db_controller* db_control = new db_controller("./" + file_name + ".db", params_map["-db_user_name"], params_map["-db_password"]);

		if (db_control->run_command(table_struct))
		{
			std::cout << "First command was succesed " << std::endl;
		}
		else 
		{
			std::cerr << "First command was failed" << std::endl;
			throw;
		}
		if (db_control->run_command(table_info_insertion))
		{
			std::cout << "Second command was succesed " << std::endl;
		}
		else
		{
			std::cerr << "Second command was failed" << std::endl;
			throw;
		}
		;
		if (db_control->get_result(table_select_person))
		{
			std::cout << "Get result was succesed " << std::endl;
		}
		else
		{
			std::cerr << "Get result was failed" << std::endl;
			throw;
		}

		std::cout << "DB init is finished" << std::endl;

		std::string parse_file = std::string("./" + file_name + ".csv");
		std::cout << "Try covert DB to .csv file" << std::endl;
		db_control->parse_db_into_file(parse_file);
		delete db_control;
		db_control = nullptr;

		ftp_comunication* ftp_com = new ftp_comunication(params_map["-ftp_host_name"], params_map["-ftp_port"], params_map["-ftp_user_name"], params_map["-fpt_password"], params_map["-ftp_directory"]);
		if (ftp_com->send_file("./", parse_file))
		{
			std::cout << "file sending are succes " << std::endl;
		}
		else 
		{
			std::cerr << "file sending are failed" << std::endl;
		}

		delete ftp_com;
		ftp_com = nullptr;

	}
	catch (...) 
	{
		return false;
	}
	return true;
}


application::application(int argc, char** argv ) 
	  :m_argc(argc),
	   m_argv(argv)
{
	std::cout << "call = " << __func__ << std::endl;
}

application::~application() {

}




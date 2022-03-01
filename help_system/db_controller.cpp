
#include "db_controller.h"

std::vector<std::vector<std::string>> db_controller::m_selected_info;

int db_controller::exec_callback(void* data, int argc, char** argv, char** temp) 
{

	m_selected_info.clear();
	m_selected_info.resize(argc);
	for (int i = 0; i < argc; ++i)
	{
		m_selected_info.push_back(std::vector<std::string> {});
		m_selected_info.back().push_back(temp[i]);
	}
	for (int i = 0; i < argc; ++i)
	{
		m_selected_info[i].push_back(argv[i]);
	}

	return 0;
}

void db_controller::parse_db_into_file(const std::string& path)
{

	std::fstream out_file(path.c_str(), std::ios_base::out);
	for (size_t i = 0; i < m_selected_info[0].size(); ++i)
	{
		size_t j;
		for (j = 0 ; j < m_selected_info.size() - 1; ++j)
		{
			out_file << m_selected_info[j][i] << ",";
		}
		out_file << m_selected_info[j][i] << std::endl;
	}

	out_file.close();
}


bool db_controller::run_command(const std::string& comand, int(*call)(void*, int, char**, char**))
{
	std::cout << "call = " << __func__ << std::endl;
	std::cout << "path = " << m_path_db << std::endl;

	int result = sqlite3_open(m_path_db.c_str(), &m_db);

	if (SQLITE_OK != result)
	{
		std::cerr << "cant create database" << sqlite3_errmsg(m_db) << std::endl;
		return false;
	}

	char* error_msg = nullptr;
	result = sqlite3_exec(m_db, comand.c_str(), call, nullptr, &error_msg);

	if (SQLITE_OK != result)
	{
		std::cerr << "execution was failed" << error_msg << std::endl;
		sqlite3_free(error_msg);
		return false;
	}

	sqlite3_close(m_db);
	return true;
}

bool db_controller::get_result(const std::string& path) 
{
	return run_command(path, &db_controller::exec_callback);
}


void db_controller::init() 
{
	/// Setup a connection with DB
	int result = sqlite3_open(m_path_db.c_str(), &m_db);

	if (SQLITE_OK != result)
	{
		std::cerr << "Can't open database: " << sqlite3_errmsg(m_db) << std::endl;
	}
	sqlite3_close(m_db);
}

db_controller::db_controller(const std::string & db_path, const std::string& user_name, const std::string & password)
	: m_path_db(db_path),
	  m_user_name(user_name.c_str()), 
	  m_password(password.c_str())
{
	init();
}

db_controller::~db_controller() {

}
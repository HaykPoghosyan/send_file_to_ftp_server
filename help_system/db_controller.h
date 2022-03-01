#pragma once

#include "sqlite/sqlite3.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class db_controller
{


private:
	sqlite3* m_db = nullptr;
	const char* m_user_name = nullptr;
	const char* m_password = nullptr;
	std::string	m_path_db = "";
	static std::vector<std::vector<std::string>> m_selected_info;

private:
	void init();

public:
	static int exec_callback(void*, int, char**, char**);

	void parse_db_into_file(const std::string &);

public:
	bool run_command(const std::string &, int(*)(void*, int, char**, char**) = nullptr);
	bool get_result(const std::string&);

public:
	db_controller(const std::string&, const std::string&, const std::string&);
	~db_controller();
};


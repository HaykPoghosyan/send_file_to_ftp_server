#pragma once

#include <map>
#include <set>
#include <string>

class param_parser
{

private:
	int m_argc;
	char** m_argv;

private:
	int		m_iArgs = 0;
	char** m_ppArgv = nullptr;
	std::map<std::string, std::string>m_arg_map;
	std::set<std::string> m_parameters_list;

public:
	std::map<std::string, std::string> & parse();

private:
	void init();

public:
	param_parser(int, char **);
	~param_parser();
};


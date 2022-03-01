#include "param_parser.h"
#include <iostream>
#include <set>


std::map<std::string, std::string> & param_parser::parse() 
{
	std::cout << "Program name = " << m_argv[0] << std::endl;
	if ( 1 != m_argc % 2 )
	{
		std::cerr << "invalid count parameters " << std::endl;
		throw;
	}
	if (m_argc < 15) 
	{
		std::cerr << "invalid count of parameters " << " Parameters count must be More or Eqoul  15 " << std::endl;;
	}
	for (int i = 1; i < m_argc; i = i + 2) 
	{
		if (0 != m_parameters_list.count(m_argv[i]))
		{
			//std::cout << m_argv[i] << " = " << m_argv[i + 1] << std::endl;
			m_arg_map[m_argv[i]] = m_argv[i + 1];
		}
	}
	return m_arg_map;
}

void param_parser::init() 
{
	std::cout << "call = " << std::endl;
	m_parameters_list.insert("-db_user_name");
	m_parameters_list.insert("-db_password");
	m_parameters_list.insert("-ftp_host_name");
	m_parameters_list.insert("-ftp_port");
	m_parameters_list.insert("-ftp_user_name");
	m_parameters_list.insert("-ftp_password");
	m_parameters_list.insert("-ftp_directory");
}

param_parser::param_parser(int argc, char ** argv)
	: m_argc(argc),
	  m_argv(argv)
{
	std::cout << "call = " << __func__ << std::endl;
	init();
}

param_parser::~param_parser() {

}
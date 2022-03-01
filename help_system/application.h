#pragma once

#include "param_parser.h"
#include "db_controller.h"






class application
{
public:
	bool exec();

private:
	int	   m_argc = 0;
	char** m_argv = nullptr;

	public:
		application(int, char **);
		~application();
};







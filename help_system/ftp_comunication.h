#pragma once
#include <string>

class ftp_comunication
{
private:
	const std::string& m_host;
	const std::string& m_port;
	const std::string& m_user;
	const std::string& m_password;
	const std::string& m_directory;

public:
	bool send_file(const std::string&, const std::string&);

	bool folder_exists(const std::string &);

public:
	ftp_comunication(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
	~ftp_comunication();
};



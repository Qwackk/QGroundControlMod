#include "ftplib.h"
#include "config_manager.h"


int main()
{
    // Send the file and check for successful upload.
    if( sendConfigFile() )
    {

    }

    else
    {
        std::cout << "Error Uploading Config File..." << "\r\n";
        return 1;
    }

    // Get the file and check for successful download.
    if( getConfigFile() )
    {

    }

    else
    {
        std::cout << "Error Downloading Config File..." << "\r\n";
        return 1;
    }

    return 0;

}

bool generateConfigFile( void )
{
    // Create the ofstream object
    std::ofstream config_file ( "configTest3.txt" );

    // Add text to the file via upstream
    config_file << "This is a test file used for FTP file trasnfer.";

    // Close the object, creating the file.
    config_file.close();

    // Indicate a successful config file generation.
    return true;
}

bool sendConfigFile( void )
{
    int success;

    ftplib *ftp = new ftplib();

    // Create the config file and check if it was properly created.
    if( generateConfigFile() != true )
    {
        std::cout << "Error Generating Config File" << "\r\n";
        return false;
    }

    // Connect to the FTP server.
    // Using a site to test upload.
    // However, any file uploaded here is purged in 30 minutes.
    success = ftp->Connect( "ftp.dlptest.com" );

    // 1 Indicates success, 0 indicates failure.
    if( success != 1 )
    {
        std::cout << "Error Connecting to Host." << "\r\n";
        return false;
    }


    // Username, Password
    success = ftp->Login( "dlpuser@dlptest.com", "bbCKucPzfr4b9YXUY7tvsNKyh" );

    if( success != 1 )
    {
        std::cout << "Error Logging into Host." << "\r\n";
        return false;
    }


    success = ftp->Put( "configTest3.txt", "configTest3.txt", ftplib::ascii );

    if( success != 1 )
    {
        std:: cout << "Error Sending File." << "\r\n";
        return false;
    }

    ftp->Quit();

    std::cout << "Config File Uploaded!" << "\r\n";
    return true;

}

bool getConfigFile( void )
{
    int success;

    ftplib *ftp = new ftplib();

    // Connect to the FTP server.
    // Using a site to test upload.
    // However, any file uploaded here is purged in 30 minutes.
    success = ftp->Connect( "ftp.dlptest.com" );

    if( success != 1 )
    {
        std::cout << "Error Connecting to Host." << "\r\n";
        return false;
    }

    // Username, Password
    success = ftp->Login( "dlpuser@dlptest.com", "bbCKucPzfr4b9YXUY7tvsNKyh" );

    if( success != 1 )
    {
        std::cout << "Error Logging into Host." << "\r\n";
        return false;
    }

    // Get the config file and download it as retrievedConfigTest.txt
    success = ftp->Get( "retrievedConfigTest.txt", "configTest3.txt", ftplib::ascii );

    if( success != 1 )
    {
        std:: cout << "Error Retrieving File." << "\r\n";
        return false;
    }

    ftp->Quit();

    std::cout << "Config File Retrieved!" << "\r\n";
    return true;

}


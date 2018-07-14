#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;

int main(int argc, char* argv[])
{
 
    if (argc < 3) {

        std::cerr << "Please supply SSID and password" << std::endl;
        return 1;
    }

	
	ofstream wpaconf_file;
	wpaconf_file.open ("/etc/wpa_supplicant/wpa_supplicant.conf");
	wpaconf_file <<  "country=US\n";
	wpaconf_file <<  "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\n";
	wpaconf_file <<  "update_config=1\n";
	wpaconf_file <<  "\n";
	wpaconf_file <<  "\n";
	wpaconf_file <<  "network={\n";
	wpaconf_file <<  "	ssid=\"" << argv[2] << "\"\n" ;
	wpaconf_file <<  "	psk=\""<< argv[3] << "\"\n" ;
	wpaconf_file <<  "}\n";
	wpaconf_file.close();
	

	system("wpa_supplicant -B -i " << char(argv[1]) << " reconfigure");
	system("dhcpcd");
	
	
	
    return 0;
}
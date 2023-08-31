#include <iostream>
#include <cstddef>
#include <SFML/Network.hpp>

#include <string>

int main()
{
    std::string data;

	std::cout << "==== Project UDP ====\n";

	sf::UdpSocket socket;	

    sf::Socket::Status status = socket.bind(8000);
    if (status != sf::Socket::Done)
    {
        std::cout << "error bind port 8000 :c";
        system("sleep 10;pause");
    }
    
    std::cout << "\n*** Client Created ***\n";
    while(1)
    {
        sf::Packet packet;
        
        sf::IpAddress sender = "127.0.0.1";
        unsigned short port = 8001; 

        sf::Packet pack;
        pack << data;

        if (socket.receive(pack, sender, port) == sf::Socket::Done)
        {
            pack >> data;
            std::cout << "Data: " << data << " bytes from " << sender << " on port " << port << std::endl;
        }
        else
        {
            std::cout << "error receive";
        }
    }

	return 0;
}
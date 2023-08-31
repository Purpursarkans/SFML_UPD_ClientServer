#include <iostream>
#include <cstddef>
#include <SFML/Network.hpp>

#include <string>

int main()
{

    std::string data = "hello world";
    int num = 1;

	std::cout << "==== Project UDP ====\n";
    

    sf::UdpSocket socket;

    if (socket.bind(8001) != sf::Socket::Done)
    {
        std::cout << "error bind port 8001 :c";
        system("sleep 5");
    }

    int value = 0;

    std::cout << "\n*** Server Created ***\n";

    while(1)
    {
        std::cout << "Enter value: ";
        std::getline(std::cin,data);

        sf::Packet packet;
        packet << value;

        sf::IpAddress recipient = "127.0.0.1";
        unsigned short port = 8000;

        sf::Packet pack;
        pack << data;

        if(socket.send(pack, recipient, port) != sf::Socket::Done)
        {
            std::cout << "not send" << std::endl;
        }
    }
	return 0;
}
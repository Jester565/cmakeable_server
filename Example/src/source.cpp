#include <iostream>
#include "WSServer.h"

int main() {
  WSServer* server = new WSServer(boost::asio::ip::tcp::v6());
  server->createManagers();
  server->run(5231);
  std::cout << "Running" << std::endl;
  std::string str;
  std::cin >> str;
}

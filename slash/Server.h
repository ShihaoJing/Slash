//
// Created by Shihao Jing on 5/31/17.
//

#ifndef SERVER_H
#define SERVER_H

#include <boost/asio.hpp>
#include <string>
#include "ConnectionManager.h"
#include "Connection.h"

namespace HTTP {
namespace Server {

class Server {

public:
  Server(const std::string& address, const std::string& port,
         const std::string& doc_root);

  void run();

private:
  void do_accept();

  boost::asio::io_service io_service_;
  boost::asio::ip::tcp::acceptor acceptor_;
  boost::asio::ip::tcp::socket socket_;

  // The connection manager which owns all live connections.
  ConnectionManager connection_manager_;

};

} // namespace Server
} // namespace HTTP

#endif //SERVER_H

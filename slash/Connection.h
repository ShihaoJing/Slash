//
// Created by Shihao Jing on 6/13/17.
//

#ifndef SLASH_CONNECTION_H
#define SLASH_CONNECTION_H

#include <boost/asio.hpp>
#include <memory>


namespace HTTP {
namespace Server {

class ConnectionManager;

class Connection : public std::enable_shared_from_this<Connection>
{
public:
  Connection(const Connection&) = delete;
  Connection& operator=(const Connection&) = delete;

  // Construct a connection with the given socket.
  explicit Connection(boost::asio::ip::tcp::socket socket, ConnectionManager &manager);

  // Start the asynchronous operation for the connection
  void start();

  // Stop all asynchronous operation associated with the connection
  void stop();

private:
  // Perform an asynchronous read operation.
  void do_read();

  // Perform an asynchronous write operation.
  void do_write();

  // Socket for the connection.
  boost::asio::ip::tcp::socket socket_;

  // Buffer for incoming data.
  std::array<char, 8192> buffer_;

  // The manager for this connection.
  ConnectionManager& connection_manager_;


};

typedef std::shared_ptr<Connection> connection_ptr;
} // namespace Server
} // namespace HTTP


#endif //SLASH_CONNECTION_H

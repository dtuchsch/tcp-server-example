
/// \file TCPSocket.h
/// \brief TCPSocket to send and receive data via TCP/IP
/// \date 02.03.2017
/// \author Daniel Tuchscherer

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <errno.h>
#include <stdint.h>

/// Easier to read.
typedef int Handle;

/// \brief Creates a TCP socket
/// \return the socket handle as an integer
Handle create_tcp_socket();

/// \brief Listen for incoming TCP client connections.
/// \param[in] server is the socket handle
/// \param[in] client_ip to accept as characters. If you give "255.255.255.0" it
/// will accept any connections from outside.
/// \param[in] the port to listen to.
int tcp_server_listen(const Handle server, const char *client_ip,
                      const uint16_t port);

/// \brief Blocking wait for incoming client connections
/// \param[in] server socket handle
/// \return the data socket to send data.
Handle tcp_server_accept(const Handle server);

/// Receive data via TCP/IP. As default this function does a blocking read.
/// \param[in] datasocket is the handle of the socket
/// \param[in] msg the buffer address to store data on successful receive
/// \param[in] len in bytes to receive
/// \return number of bytes received.
int tcp_receive(const Handle datasocket, uint8_t *msg, const uint16_t len);

/// \brief Send data via TCP/IP.
/// \param[in] datasocket handle
/// \param[in] msg the address to read from
/// \param[in] len length in bytes to send.
/// \return number of bytes sent. 0 or -1 on error
int tcp_send(const Handle datasocket, const uint8_t *msg, const uint16_t len);

/// \brief Closes one socket
/// \param[in] handle the socket to close
int close_tcp_socket(const Handle handle);

#endif /* TCPSOCKET_H */

/**
  * Copyright (C) 2019 Hirain Technologies
  * License: Modified BSD Software License Agreement
  * Author: Feng DING
  * Description: udp sender
  */

#ifndef _UDPSENDER_H_
#define _UDPSENDER_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <string>

#define REMOTE_SERVER_PORT 1500

namespace itd_lidar {
class UdpSender {
 enum UdpStat{
   UNKOWN_HOST_ERROR = -5,
   SOCKET_BIND_ERROR = -4,
   SOCKET_SETOPT_ERROR = -3,
   SOCKET_OPEN_ERROR = -2,
   MSG_SEND_ERROR = -1,
   NO_ERROR = 0
 };
 public:
  UdpSender(std::string ip, int port = REMOTE_SERVER_PORT);
  ~UdpSender();
  int Send(const void *msg, const int& len);

 private:
  std::string target_ip_;
  int port_;
  int socket_, ret_;
  struct sockaddr_in client_address_, remote_server_address_;
  struct hostent *host_;
  int broadcast_;
  int Init();
};
} // namespace itd_lidar

#endif // _UDPSENDER_H_

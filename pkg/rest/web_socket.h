#pragma once

#include <ixwebsocket/IXWebSocketServer.h>

class WebSocket {
public:
  WebSocket();

  void start();
  void shutdown();

private:
  ix::WebSocketServer server_;
};
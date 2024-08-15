#pragma once
#include <string>

namespace Engine::Network {

enum class SocketType { TCP, UDP };

class Socket {
public:
    Socket(SocketType type);
    ~Socket();

    bool Bind(uint16_t port);
    bool Listen();
    bool Send(const std::string& data, const std::string& remoteIP, uint16_t remotePort);
    std::string Receive();

private:
    SocketType m_type;
    int m_socketFD = -1;
};

}

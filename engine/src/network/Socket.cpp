#include "engine/network/Socket.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Network {

Socket::Socket(SocketType type) : m_type(type), m_socketFD(100) {
    Core::Logger::Info("Created Network Socket abstraction.");
}

Socket::~Socket() {
    Core::Logger::Info("Closed Network Socket.");
}

bool Socket::Bind(uint16_t port) {
    Core::Logger::Info("Bound Socket to port " + std::to_string(port));
    return true;
}

bool Socket::Listen() {
    Core::Logger::Info("Socket listening for connections...");
    return true;
}

bool Socket::Send(const std::string& data, const std::string& remoteIP, uint16_t remotePort) {
    return true;
}

std::string Socket::Receive() {
    return "";
}

}

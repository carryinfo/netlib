#include "Socket.h"
#ifdef WIN32
#include <WinSock2.h>
#else
#include <sys/socket.h>
#endif

namespace netlib {
	
	int init() {
#ifdef WIN32
		WORD wVersionRequested;
		WSADATA wsaData;  
		wVersionRequested = MAKEWORD(1, 1);
		int err = WSAStartup(wVersionRequested, &wsaData);//º”‘ÿWinsocket DLL
		return err;
#endif
		return 0;
	}

	int deinit() {
#ifdef WIN32
		return WSACleanup();
#endif
		return 0;
	}

	int socket(int domain, int type, int protocol) {
		return ::socket(domain, type, protocol);
	}

	int bind(int socket, const netlib::sockaddr *address, socklen_t address_len) {  
		return ::bind(socket, (::sockaddr*)address, address_len);
	}

	int connect(int socket, const netlib::sockaddr *address, socklen_t address_len) { 
		return ::connect(socket, (::sockaddr*)address, address_len);
	}

	int listen(int socket, int backlog) {
		return ::listen(socket, backlog);
	}

	int accept(int socket, netlib::sockaddr *address, socklen_t *address_len) { 
		return ::accept(socket, (::sockaddr*)address, address_len);
	}

	int getsockname(int socket, netlib::sockaddr *address, socklen_t *address_len) {
		return ::accept(socket, (::sockaddr*)address, address_len);
	}

	int getpeername(int socket, netlib::sockaddr *address, socklen_t *address_len) {
		return ::getpeername(socket, (::sockaddr*)address, address_len);
	}

	int socketpair(int domain, int type, int protocol, int socket_vector[2]) { 
#ifdef WIN32
		//	not implemented
		return -1;
#else
		return ::socketpair(domain, type, protocol, socket_vector);
#endif
	}
	int shutdown(int socket, int how) {
		return ::shutdown(socket, how);
	}

	int setsockopt(int socket, int level, int option_name,
		const void *option_value, socklen_t option_len) {
		return ::setsockopt(socket, level, option_name, (const char*)option_value, option_len);
	}

	int getsockopt(int socket, int level, int option_name,
		void *option_value, socklen_t *option_len) {
		return ::getsockopt(socket, level, option_name, (char*)option_value, option_len);
	}

	ssize_t  send(int socket, const void *message, size_t length, int flags) {
		return ::send(socket, (const char*) message, length, flags);
	}

	ssize_t  recv(int socket, void *buffer, size_t length, int flags) {
		return ::recv(socket, (char*)buffer, length, flags);
	}

	ssize_t sendto(int socket, const void *message, size_t length, int flags,
		const netlib::sockaddr *dest_addr, socklen_t dest_len) {
		return ::sendto(socket, (const char*)message, length, flags,
			(::sockaddr*)dest_addr, dest_len); 
	}

	ssize_t recvfrom(int socket, void *buffer, size_t length,
		int flags, netlib::sockaddr *address, socklen_t *address_len) {
		return ::recvfrom(socket, (char*)buffer, length, flags,
			(::sockaddr*)address, address_len);
	}

	int close(int socket) {
#ifdef WIN32
		return ::closesocket(socket);
#else
		return ::close(socket);
#endif
	}

	int read(int socket, void* buffer, size_t length, int flags) {
		return netlib::recv(socket, buffer, length, flags);
	}

	int write(int socket, const void* message, size_t length, int flags) {
		return netlib::send(socket, message, length, flags);
	}
}
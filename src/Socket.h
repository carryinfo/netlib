#ifndef __SOCKET_H
#define __SOCKET_H 

namespace netlib { 

#define AF_UNSPEC 0
#define AF_UNIX 1  
#define AF_LOCAL 1  
#define AF_INET 2  

#define SOCK_STREAM      1
#define SOCK_DGRAM       2
#define SOCK_RAW         3
#define SOCK_RDM         4
#define SOCK_SEQPACKET   5
#define SOCK_PACKET      10

	typedef int socklen_t;
	typedef int  ssize_t;
	typedef unsigned short sa_family_t;

	struct in_addr {
		unsigned long s_addr;
	};

	struct sockaddr_in{
		short int sin_family; /* Address family */ 　
		unsigned short int sin_port; /* Port number */ 　　
		netlib::in_addr sin_addr; /* Internet address */ 　　
		unsigned char sin_zero[8]; /* Same size as struct sockaddr */ 　
	}; 

	struct sockaddr {
		sa_family_t sa_family;
		char sa_data[14];
	};
	typedef int socklen_t;

	int init();
	int deinit();

	int socket(int domain, int type, int protocol);
	int bind(int socket, const netlib::sockaddr *address, socklen_t address_len);
	int connect(int socket, const netlib::sockaddr *address, socklen_t address_len);
	int listen(int socket, int backlog);
	int accept(int socket, netlib::sockaddr *address, socklen_t *address_len);
	int getsockname(int socket, netlib::sockaddr *address, socklen_t *address_len);
	int getpeername(int socket, netlib::sockaddr *address, socklen_t *address_len);
	int socketpair(int domain, int type, int protocol, int socket_vector[2]);
	int shutdown(int socket, int how);

	int setsockopt(int socket, int level, int option_name, 
		const void *option_value, socklen_t option_len);
	int getsockopt(int socket, int level, int option_name, 
		void *option_value, socklen_t *option_len);

	ssize_t  send(int socket, const void *message, size_t length, int flags);
	ssize_t  recv(int socket, void *buffer, size_t length, int flags);

	ssize_t sendto(int socket, const void *message, size_t length, int flags,
		const netlib::sockaddr *dest_addr, socklen_t dest_len);
	ssize_t recvfrom(int socket, void *buffer, size_t length,
		int flags, netlib::sockaddr *address, socklen_t *address_len);
	 
	int close(int socket);
	int read(int socket, void* buffer, size_t length, int flags);
	int write(int socket, const void* message, size_t length, int flags);

//	TODO
//	int sendmsg(int socket, const netlib::msghdr *message, int flags);
//	int recvmsg(int socket, netlib::msghdr *message, int flags);
}

#endif	//	__SOCKET_H
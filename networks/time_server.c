#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// add the macros
#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define SOCKET int
#define GETSOCKETERRNO() (errno)

int main() {

  printf("Configuring local address...\n");  // tell user address is being configured
  struct addrinfo hints;               // create a struct for getaddress info
  memset (&hints, 0, sizeof(hints));   // set values in struct to 0
  hints.ai_family = AF_INET;           // the IP address type (contained in variable ai_family) is AF_INET which means IPv4
  hints.ai_socktype = SOCK_STREAM;     // ai_socktype means protocol. SOCK_STREAM means tcp, if it were SOCK_DGRAM that would mean udp
  hints.ai_flags = AI_PASSIVE;   // set up the address to listen on any available network interface

  struct addrinfo *bind_address;  // bind address is where the data on the socket is returned to

  // getaddrinfo(const char *restrict node, const char *restrict service, struct *hints, struct **res)
  // node determines whether AI_PASSIVE flag is relevant, if node is 0, AI_PASSIVE flag is relevant
  // node is the ip address, defaults to local 127.0.0.1 if node is 0
  // service is port number
  // node and service cannot both be null
  // hints is a struct of socket criteria
  // bind_address is where the resulting info is stored
  
  getaddrinfo(0, "8080", &hints, &bind_address);  // get info on the socket address

  printf("Creating socket...\n");  // tell user the socket is being made
  SOCKET socket_listen;           // int socket_listen, which is the file descriptor
  // socket(int domain, int type, int protocol)
  // make socket_listen a file descriptor for the socket
  // domain is IPv4, type is tcp (sock_stream), protocol used in getaddrinfo
  socket_listen = socket(bind_address->ai_family,
			 bind_address->ai_socktype, bind_address->ai_protocol);

  // if file descriptor returned is < 0 print errno
  if(!ISVALIDSOCKET(socket_listen)) {
    fprintf(stderr, "socket() failed. (%d)\n", GETSOCKETERRNO());
    return 1;
  }

  printf("Binding socket to local address...\n"); // tell user binding socket
  if( bind(socket_listen,
	   bind_address->ai_addr, bind_address->ai_addrlen)) {
    fprintf(stderr, "bind() failed. (%d) \n", GETSOCKETERRNO());
    return 1;
  }
  // frees the memory allocated for res (which is where the bind address info is)
  freeaddrinfo(bind_address);

  printf("Listening...\n"); // tell user socket is listening

  // listen on the previously created file descriptor, with a max backlog of 10
  if (listen(socket_listen, 10) < 0) {
    fprintf(stderr, "listen() failed. (%d)\n", GETSOCKETERRNO());
    return 1;
  }

  // tell user waiting for connection
  printf("Waiting for connection...\n");

  
  struct sockaddr_storage client_address; // address info for accepting socket
  socklen_t client_len = sizeof(client_address);  // length of the address info struct
  
  // accept( file descriptor socket_listen, pointer to a socket address info, memory address of length of address info
  SOCKET socket_client = accept(socket_listen, (struct sockaddr*) &client_address, &client_len);
  // if unsucessful, tell user
  if (!ISVALIDSOCKET(socket_client)) {
    fprintf(stderr, "accept() failed. (%d)\n", GETSOCKETERRNO());
    return 1;
  }

  printf("client is connected... "); // tell user client has connected
  char address_buffer[100];     // 100 bytes in address buffer
  /* getnameinfo(const struct sockaddr *restrict addr, socklen_t addrlen,
                       char host[_Nullable restrict hostlen],
                       socklen_t hostlen,
                       char serv[_Nullable restrict servlen],
                       socklen_t servlen,
                       int flags)*/

  // convert socket address to a host and service
  // client_address is pointer to the addr info struct used by accept
  // client_len is length, address_buffer is a pointer to a memory address where getnameinfo puts the host name, sizeof is length of that buffer, no need for service buffer or length, so 0, 0, NI_NUMERICHOST means numeric form of hostname is returned
  getnameinfo((struct sockaddr*)&client_address,
	      client_len, address_buffer, sizeof(address_buffer), 0, 0,
	      NI_NUMERICHOST);
  // print first character of address_buffer
  printf("%s\n", address_buffer);

  printf("Reading request...\n");  // tell user reading request
  char request[1024];   // create buffer for request of 1024 bytes
  // recv(int sockfd, void buf[size], size_t size, int flags))
  // receive message, file descriptor of socket_client, into buffer request of length 1024, 0 in flags
  int bytes_received = recv(socket_client, request, 1024, 0);
  printf("%d of %d bytes received.\n", bytes_received,1024); // print bytes received


  printf("Sending response...\n"); // tell user response is being sent
  const char *response = // pointer to response string
    "HTTP/1.1 200 OK\r\n" // http protocol version and status code
    "Connection: close\r\n" // connection close
    "Content-Type: text/plain\r\n\r\n" // content type
    "Local time is: ";  // local time is
  // send(int sockfd, const void buf[size], size_t size, int flags)
  // socket_client file descriptor, response is buffer containing message to be sent, strlen of response buffer, flags set to 0
  int bytes_sent = send(socket_client, response, strlen(response), 0);
  // tell user how many bytes sent out of the total buffer
  printf("Sent %d of %d bytes.\n", bytes_sent, (int)strlen(response));


  // timer var
  time_t timer;
  time(&timer); // mem location
  char *time_msg = ctime(&timer); // get local time and save it in timer mem address
  // calc bytes sent
  bytes_sent = send(socket_client, time_msg, strlen(time_msg), 0);
  // tell user how many bytes sent
  printf("sent %d of %d bytes.\n", bytes_sent, (int)strlen(time_msg));

  // tell user closing connection
  printf("Closing connection...\n");
  CLOSESOCKET(socket_client);

  // tell user closing socket
  printf("Closing listening socket...\n");

  CLOSESOCKET(socket_listen);

  // tell user finished
  printf("Finished.\n");

  return 0;

}

#include <sys/types.h>
#include <sys/socket.h>
#include <metdb.h>

int getaddringo(const char *node,
				const char *service,
				const struct addrinfo *hints,
				struct addrinfo **res);

int main(int argc, char const *argv[])
{
	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo;  // will point to the results

	memset(&hints, 0, sizeof hints); // make sure the struct is empty
	hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
	hints.ai_flags = AI_PASSIVE;     // fill in my IP for me

	if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0) {
	    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
	    exit(1);
	}

	// servinfo now points to a linked list of 1 or more struct addrinfos

	// ... do everything until you don't need servinfo anymore ....

	freeaddrinfo(servinfo); // free the linked-list
	
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

/*This example works was tested on my
* works fine with Firefox
* doesn't work with Google Chrome
*/

#define PORT 9002

int main(){

  // open HTML and read to application
  FILE *html_data;
  html_data = fopen("index.html", "r");
  int buffer = 1024;
  char response_data[buffer];
  fgets(response_data, buffer, html_data);

  int max_buffer = 2 * buffer;
  char http_header[max_buffer];
  //Secure way to copy the string
  strncpy(http_header, "HTTP/1.1 200 OK\r\n\n", max_buffer);

  //Vulnerable
  //strcpy(http_header, "HTTP/1.1 200 OK\r\n\n");

  strcat(http_header, response_data);

  // create a socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  //define the address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  //server part
  bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
  listen(server_socket, 5);

  // client part
  int client_socket;
  while(1){
    client_socket = accept(server_socket, NULL, NULL);
    send(client_socket, http_header, sizeof(http_header), 0);
    close(client_socket);
  }
  return 0;
}

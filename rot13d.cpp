#include <iostream>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 1067



void rot13(unsigned char *s, int n)
{
  unsigned char *p;
  for (p=s; p < s + n; p++)
  {
    if (islower(*p))
    {
      *p += 13;
      if (*p > 'z') *p -= 26;
    }
  }
} 

void rot13_service(int in, int out)
{
  unsigned char buf[1024];
  int count;
  while ((count = read(in, buf, 1024)) > 0)
  {
    rot13(buf, count);
    write(out, buf, count);
  }
}

int main()
{
  int sock, fd;
  sock = socket(AF_INET, SOCK_STREAM, 0);
  
  socklen_t client_len;

  struct sockaddr_in server, client;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons(SERVER_PORT);

  bind(sock, (sockaddr *)&server, sizeof(server));
  listen(sock, 5);
  printf("listening ...\n");

  while (1) {
    client_len = sizeof(client);
    fd = accept(sock, (sockaddr *)&client, ( socklen_t * ) &client_len);

    printf("got connection\n");

    rot13_service(fd, fd);
    close(fd);
  }

  return 0;
}


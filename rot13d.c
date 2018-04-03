#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

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

void main()
{
  int sock, fd, client_len;
  struct sockaddr_in server, client;
  struct servent *service;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = htons(SERVER_PORT);
  bind(sock, (struct sockaddr *)&server, sizeof(server));
  listen(sock, 5);
  printf("listening ...\n");

  while (1) {
    client_len = sizeof(client);
    fd = accept(sock, (struct sockaddr *)&client, &client_len);
    printf("got connection\n");
    rot13_service(fd, fd);
    close(fd);
  }
}


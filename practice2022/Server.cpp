// echo.server.c

/*
TCP 서버 구현을 위한 기본적인 함수의 호출은 밑과 같다.
1.socket() -> 소켓 생성
2. bind() -> 소켓 주소할당
3. listen() -> 연결요청 대기상태
4. accept() -> 연결 허용
5. read()/write() -> 데이터 송수신
6. close() -> 연결종료
제일 먼저 socket() 함수의 호출을 통해 소켓을 생성한다. 그리고 주소 정보를 담기 위한 구조체 변수를
선언 및 초기화 하여 bind() 함수를 호출하여 소켓에 주소를 할당한다. 
*/
#include <stdio.h>  //표준 입출력
#include <stdlib.h>  
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
   int serv_sock, clnt_sock;
   char message[BUF_SIZE];
   int str_len, i;

   struct sockaddr_in serv_adr, clnt_adr;
   socklen_t clnt_adr_sz;

   if(argc != 2)
   {
      printf("Usage : %s <port>\n", argv[0]);
      exit(1);
   }
//서버 프로그램 구현 과정에서 제일 먼저 해야 하는 것이 소켓 생성이다. 
   serv_sock = socket(PF_INET, SOCK_STREAM, 0);  //소켓 생성 완료. 아직까지는 서버 소켓이라고 부르기는 이르다.
   if(serv_sock == -1)
      error_handling("socket() error");

//소켓의 주소할당을 위해 구조체 변수를 초기화하고 bind 함수를 호출하고 있다.
   memset(&serv_adr, 0, sizeof(serv_adr));
   serv_adr.sin_family = AF_INET;
   serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
   serv_adr.sin_port = htons(atoi(argv[1]));

   if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
      error_handling("bind() error");

//함수 호출을 통해 소켓에 주소까지 할당했다면, 연결요청 대기 상태로 들어가서 listen 함수를 호출하고 있다.  
//listen 함수가 호출되어야 클라이언트가 연결 요청을 할 수 있는 상태가 된다.
//listen 함수가 호출되어야 할 클라이언트는 연결요청을 위해 connet 함수를 호출할 수 있다.
//이전에 connect 함수가 호출되면 오류가 발생한다.
//연결요청 대기 큐의 크기도 5로 설정하였다. 이제 생성한 소켓이 서버 소켓이다.

//더 알아봅시다!
//연결요청 대기 상태: 클라이언트가 연결요청을 
   if(listen(serv_sock, 5) == -1)  //5가 전달되면 큐의 크기가 5가 되어 클라이언트의 연결요펑을 5개까지 대기시킬 수 있다.
      error_handling("listen() error");

   clnt_adr_sz = sizeof(clnt_adr);

   for(i = 0; i < 5; i++)
   {
//accept 함수가 호출되었기에 대키 큐에서 첫번째로 대기 중에 있는 연결요청을 참조하여 클라이언트와의 연결을 구성한다.
//이때 생서오딘 소켓의 파일 디스크립터를 반환한다. 
//이 함수가 호출되었을 때 대기 큐가 비어있다면 대기 큐가 찰 때까지(클라이언드의 연결요청이 들어올 때까지) accept 함수는 반환하지 않는다.
      clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
      if(clnt_sock == -1)
         error_handling("accept() error");
      else
         printf("Connected client %d \n", i + 1);
      while((str_len = read(clnt_sock, message, BUF_SIZE)) != 0)
         write(clnt_sock, message, str_len);

      close(clnt_sock);
   }
   close(serv_sock);
   return 0;
}

void error_handling(char *message)
{
   fputs(message, stderr);
   fputc('\n', stderr);
   exit(1);
}
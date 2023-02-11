#Client.py
"""
TCP 소켓 프로그래밍에서 서버가 동작하는 방식
1. socket
2. connect 
-서버와 크라이언트가 연결된다.
-이때부터 3-way 핸드쉐이크를 시작한다.
-핸드쉐이크는 네트워크를 통해 양쪽이 연결되는 것을 보장하기애 중요하다. 클라이언트가 서버에 도달할 수 있으며 그 반대도 마찬가지이다. 
3. send 
-클라이언트가 데이터를 전송한다.
4. recv 
-클라이언트가 데이터를 수신한다.
-3번으로 올라가기도 한다.
5. close 
-클라이언트가 연결 종료 메세지를 전송한다.
"""
#소켓 모듈을 가져온다.
from socket import*

#서버의 주소이다.
#hostname 또는 ip address를 사용할 수 있다.
ip="127.0.0.1"

#서버에서 지정해 놓은 포트 번호이다.
port=12345

#소켓을 생성한다
clientSocket=socket(AF_INET,SOCK_STREAM)

#server.connect(address): 서버 소켓에 연결을 요청한다. 인자로 address를 튜플 형태로 둔다.
#서버와 연결한다.
#connect() 함수 안에는 연결할 호스트의 주소와 포트번호를 인자 값에 넣어준다.
clientSocket.connect((ip, port))

print("연결 확인됐습니다.")

#socket.send(byte): 데이터를 송신한다.
#데이터를 송신한다.
#send() 함수 안에는 text를 전송하면 되는데 문자열로 전송 시에는 오류가 발생하므로 이를 utf-8로 인코딩하여 16진수 데이터로 변환하여 보낸다.
clientSocket.send("I am a Jieun client".encode("utf-8"))

print("메세지를 전송했습니다.")

#socket.recv(bufsize): 데이터를 수신한다. bufsize는 한번에 수신되는 데이터의 크기이다.
#데이터를 수신한다.
data=clientSocket.recv(1024)

print("받은 데이터: ", data.decode("utf-8"))

#연결을 종료한다.
#소켓을 닫는다.
clientSocket.close()
#Client.py
"""
TCP 소켓 프로그래밍에서 클라이언트가 동작하는 방식
1. socket 
-서버에서 리스닝 소켓을 생성한다.
2. bind
3. listen
4. accept 
-4번에서 5번으로 넘어가는 과정에서 서버와 클라이언트가 연결된다.
-accpt()에서 새로운 소켓을 리턴하여 클라이언트와 통신시 사용하도록 한다.
5. recv 
-서버가 데이터를 수신한다. 5번이 4번으로 올라가기도 한다.
6. send 
-서버가 데이터를 전송한다.
7. recv
8. close
-클라이언트가 연결 종료 메세지를 전송하거나 소켓을 닫으면 서버는 클라이언트와 통신을 위해 사용한 소켓을 닫는다.
"""
#소켓 모듈을 가져온다.
from socket import* 

#접속할 서버 주소이다
host="127.0.0.1"

#임의번호이다.
#클라이언트의 접속을 대기하는 포트번호이다.
port=12345

#소켓 객체를 생성한다.
#소켓 함수를 사용할 때는 두 가지 인자를 입력해야 하는데, 각각에 해당되는 주소체계와 소켓 타입을 입력해 주어야 한다.
#IPv4 주소체계의 경우 AF_INET을 사용하고 IPv6 주소체계의 경우 AF_INET6을 사용한다.
#TCP 통신은 SOCK_STREAM을 사용하고 UDP 타입의 경우 SOCK_DGRAM을 사용한다.
serverSocket=socket(AF_INET,SOCK_STREAM) 

#socket.bind(address): 생성한 소켓을 서버 IP 및 포트를 튜플 형태로 맵핑한다.
#bind 함수는 소켓을 특정 네트워크 인터페이스와 포트 번호에 연결하는데 사용된다.
#생성한 소켓에 설정한 host와 port를 매핑한다.
#port는 1-65535 사이의 숫자를 사용할 수 있다.
serverSocket.bind((host,port))

#socket.listen(): 연결 요청 대기 상태를 결정한다.
#맵핑된 소켓을 연결 요청 대기 상태로 전환한다.
#여기서 정수 5는 큐의 공간을 의미하며 이는 최대 5개까지의 클라이언트 요청을 대기할 수 있다는 걸 의미한다.
serverSocket.listen(5)
print("김지은 서버 대기중입니다.")

#socket.accept(): 연결 승난 후 실제 통신 소켓을 반환한다.
#실제 소켓 연결 시 반환되는 실제 통신용 연결된 소켓과 연결주소를 할당한다.
#connectionSocket은 임의로 지은 이름이다.
connectionSocket,addr=serverSocket.accept()

#연결이 완료됐다고 알림이 뜬다.
#접속한 클라이언트의 주소를 출력한다.
print(str(addr),"에서 접속되었습니다.")

#socket.recv(bufsize): 데이터 수신한다. bufsize는 한 번에 수신되는 데이터 크기이다.
#데이터 수신한다. 최대 1024 bytes 이다.
data=connectionSocket.recv(1024)

#받은 데이터는 UTF-8이다.
print("받은 데이터: ", data.decode("utf-8"))

#데이터를 송신한다.
#클라이언트가 보낸 메세지를 수신하여 출력한뒤 메세지를 성공적으로 받았다는 의미로 다시 서버에서 클라이언트 측으로 문자열을 전송하는 부분이다.
connectionSocket.send("I am a Jieun server".encode("utf-8"))
print("메세지를 보냈습니다.")

#연결을 종료한다.
#서버를 닫는다.
serverSocket.close()
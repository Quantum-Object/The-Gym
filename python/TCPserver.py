import socket

# TCP uses stream stocket while UDP uses datagram socket#

#welcome socket 
server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)


# these 0s are good to recieve form everyone 
server_socket.bind(('0.0.0.0',12346))

server_socket.listen()

print("now we're listening ")


conn,addr = server_socket.accept()

print(f"Connection established with {addr}")


data = conn.recv(1024).decode('utf-8')

cap_data=data.upper()

print(f"Recieved from client: {data}")
print(f"Sending to client : {cap_data}")


conn.send(cap_data.encode("utf-8"))

conn.close()




import socket

client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

client_socket.connect(('localhost',12346))

phrase=input("ENTER YA MAJEED PLEEEEEEASE")

client_socket.send(phrase.encode('utf-8'))


print(client_socket.recv(1024).decode('utf-8'))

client_socket.close()


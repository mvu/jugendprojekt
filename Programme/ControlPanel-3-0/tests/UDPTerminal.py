#!/usr/bin/python3

import socket
import sys
import json

UDP_ADDR = ("192.168.1.111", 8888)
delimiter = ","
regs_setpoint, regs_analog, regs_active = [], [], []

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def loadRegisters():
	global sock
	global regs_setpoint, regs_analog, regs_active

	sock.sendto("x".encode('utf8'), UDP_ADDR)
	raw, server = sock.recvfrom(4096)
	regs = []
	for i in range(len(raw)//2):
		regs.append(int.from_bytes(raw[2*i : 2*i+2], 'big'))
		regs_setpoint = regs[0:4]
		regs_analog   = regs[4:8]
		regs_active   = regs[8:12]
	print("Registers reloaded")

print("Started UDP Terminal for ", UDP_ADDR[0], ":", UDP_ADDR[1])
loadRegisters()
print("For list of observables type 'ls'")

run = True;
while run:
	req = input("> ").split(" ")
	cmd = req[0]
	if cmd == "q":
		print("closing...")
		run = False
	elif cmd == "ls":
		print("setpoints:\t", regs_setpoint)
		print("analogs:\t", regs_analog)
		print("active:\t\t", regs_active)
	elif cmd == "reload":
		loadRegisters()
	elif (cmd == "activate") and (len(req) == 2):
		tmp = [regs_active[int(req[1])-1].to_bytes(2, 'big')]
		tmp.append(int(1).to_bytes(1, 'big'))
		sock.sendto(b''.join( [x for x in tmp] ), UDP_ADDR)
		raw, server = sock.recvfrom(4096);
		# if int(raw) != 0:
		# 	print("Write Error")
	elif (cmd == "deactivate") and (len(req) == 2):
		tmp = [regs_active[int(req[1])-1].to_bytes(2, 'big')]
		tmp.append(int(0).to_bytes(1, 'big'))
		sock.sendto(b''.join( [x for x in tmp] ), UDP_ADDR)
		raw, server = sock.recvfrom(4096);
		if int(raw) != 0:
			print("Write Error")
	elif (cmd == "get") and (len(req) == 2):
		sock.sendto(int(req[1]).to_bytes(2, 'big'), UDP_ADDR)
		raw, server = sock.recvfrom(4096)
		print(int.from_bytes(raw[0:2], 'big'))
	elif (cmd == "set") and (len(req) == 3):
		sock.sendto(b''.join([int(r).to_bytes(2, 'big') for r in req[1:3]]), UDP_ADDR)
		raw, server = sock.recvfrom(4096);
		if int(raw) != 0:
			print("Write Error")
	else:
		print("Invalid command");
sock.close();

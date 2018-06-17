import binascii
import socket
import struct
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the port
server_address = ('localhost', 8090)
print >>sys.stderr, 'starting up on %s port %s' % server_address
sock.bind(server_address)

# https://docs.python.org/3/library/struct.html
unpacker = struct.Struct('QI')
unpacker_b = struct.Struct('?')

while True:
    data, address = sock.recvfrom(4096)
    
    print >>sys.stderr, '\nreceived %s bytes from %s' % (len(data), address)
    #print >>sys.stderr, 'received "%s"' % binascii.hexlify(data)

    unpacked_data = unpacker.unpack(data[0:12])
    print >>sys.stderr, 'Seq:', unpacked_data[0]
    print >>sys.stderr, 'Freq:', unpacked_data[1]
    unpacked_data = unpacker_b.unpack(data[12:12+1])
    print >>sys.stderr, 'is_valid:', unpacked_data[0]
    unpacked_data = unpacker.unpack(data[13:13+12])
    print >>sys.stderr, 'time:', unpacked_data[0]
    print >>sys.stderr, 'Len:', unpacked_data[1]

    print >>sys.stderr, 'data: %s' % binascii.hexlify(data[25:25+unpacked_data[1]])

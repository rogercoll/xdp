# Development

Tested in Amazon Linux 2 operating system. 

# Prerequisits

- Two network interfaces (to not lose the SSH connection)
- ENA driver version >= 2.2.0 (to support XDP, if not available you cannot you XDP Native Mode)

# Compilation && Net Interface attachment

```
clang -O2 -Wall -target bpf -g -c xdp-example.c -o xdp-example.o

ip link set dev eth1 xdpdrv object xdp-example.o (Native mode)
ip link set dev eth1 xdpgeneric object xdp-example.o (Generic mode)
```

# Verification and dis(attachment)

```
ping -I eth1 1.1.1.1
ip link set dev eth1 xdp off
```

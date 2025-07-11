# SocketProgramming

A comprehensive C project demonstrating:

* **File Socket**: Transfer files using UNIX domain sockets.
* **Internet Socket**: Establish a chat service using TCP/IP.
* **Subnetting & Supernetting Tools**: Calculate network and broadcast addresses, mask conversions, CIDR operations.

---

## 🛠️ Features

### UNIX Domain (File) Socket

* Create a server and client communicating over a socket file.
* Transfer files reliably between processes.
* Sample usage: send a text or binary file from client to server.

### Internet (TCP/IP) Socket – Chat Service

* Server listens on a specified TCP port.
* Multiple clients can connect simultaneously.
* Real-time group chat: messages from one client are broadcast to all other clients.
* Handles client disconnects and graceful shutdowns.

### Subnetting & Supernetting

* Utility functions to:

  * Convert subnet masks between dotted-decimal and CIDR slash notation.
  * Compute network and broadcast addresses for given IP and mask.
  * Aggregate contiguous subnets into a supernet.
  * Split a large network into smaller subnets.

---

## 📁 Project Structure

```text
.
├── file_socket/         # UNIX domain socket file-transfer implementation
│   ├── server.c
│   └── client.c
│
├── inet_socket/         # Internet socket chat implementation
│   ├── server.c
│   └── client.c
│
├── net_tools/           # Subnetting & Supernetting utilities
│   ├── subnet.c
│   └── supernet.c
│
└── Makefile             # Build script
```

---

## ⚙️ Requirements

* GCC (or compatible C compiler)
* Linux/Unix-like OS (for UNIX domain sockets)
* POSIX-compliant system libraries

---

## 🚀 Build & Run

Build everything:

```bash
make all
```

To build an individual component:

```bash
make file_socket
make inet_socket
make net_tools
```

---

## 🧩 Usage Examples

### File Socket

1. **Start the server**:

   ```bash
   ./file_socket/server /tmp/socketfile
   ```
2. **Send a file from client**:

   ```bash
   ./file_socket/client /tmp/socketfile path/to/local/file.txt
   ```
3. Server receives and writes the file.

---

### Internet Chat Service

1. **Launch the chat server** (default port `9000`):

   ```bash
   ./inet_socket/server 9000
   ```
2. **Connect a client**:

   ```bash
   ./inet_socket/client 127.0.0.1 9000
   ```
3. Chat in real-time across multiple clients.
4. Type `exit` to disconnect cleanly.

---

### Subnetting Tools

#### Subnet Calculator

```bash
./net_tools/subnet <IP> <CIDR>
# Example:
./net_tools/subnet 192.168.1.0 24
```

Outputs network address, broadcast address, and usable hosts.

#### Supernet Aggregator

```bash
./net_tools/supernet <CIDR1> <CIDR2> [...]
# Example:
./net_tools/supernet 192.168.0.0/24 192.168.1.0/24
```

Combines contiguous subnets into the smallest supernet(s).

---

## 🛠️ Makefile Targets

```makefile
all            # Build all executables
clean          # Remove compiled binaries
file_socket    # Build file_sock server & client
inet_socket    # Build internet socket server & client
net_tools      # Build subnet & supernet utilities
.PHONY: all clean file_socket inet_socket net_tools
```

---


# Minitalk

## Overview
A small data exchange program using UNIX signals (SIGUSR1 & SIGUSR2). This project is part of the 42 curriculum, focusing on creating a communication program in the form of a client and server.

## Features
- Server displays its PID on launch
- Client takes a string as parameter and communicates it to the server
- Server displays the received string
- Communication between client and server is done using only UNIX signals
- Proper signal synchronization between processes

## Project Structure
```
MINITALK/
├── client.c
├── server.c
└── FT_PRINTF/
    └── [ft_printf source files]
```

## Installation
```bash
git clone https://github.com/Jazailac/minitalk.git
cd minitalk
# First compile ft_printf
cd FT_PRINTF
make
cd ..
# Then compile minitalk
make
```

## Usage
1. First, start the server:
```bash
./server
```
The server will display its PID.

2. Then, in another terminal, run the client with the server's PID and your message:
```bash
./client [server_pid] [message]
```

Example:
```bash
./client 4242 "Hello World!"
```

## How it Works
The program uses binary communication through UNIX signals:
- SIGUSR1 represents binary 1
- SIGUSR2 represents binary 0
- Each character is sent bit by bit, starting from the most significant bit
- The server reconstructs each character by collecting 8 bits

## Technical Details
- The server must be launched first
- Both programs handle signal reception and transmission
- Error handling for invalid PIDs and signal transmission failures
- Proper signal synchronization to prevent data loss
- Clean exit handling


## Author
[@Jazailac](https://github.com/Jazailac)

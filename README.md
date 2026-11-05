# Queue

Build a FIFO (First In First Out) data structure using a circular array. Queues are fundamental for task scheduling, breadth-first search, and any scenario where processing order must match arrival order.

## Quick Start

**Use the included build scripts:**

### Linux/macOS
```bash
chmod +x run.sh
./run.sh
```

### Windows
```cmd
build.bat
```

The scripts will compile and run your program automatically.

## Prerequisites

You need a C++ compiler installed:

### macOS
```bash
xcode-select --install
```

### Linux (Ubuntu/Debian)
```bash
sudo apt install build-essential
```

### Windows
Install one of:
- [MinGW-w64](https://www.mingw-w64.org/downloads/) - Lightweight g++ for Windows
- [MSYS2](https://www.msys2.org/) - Unix-like environment with g++
- [Visual Studio](https://visualstudio.microsoft.com/) - Full IDE with MSVC compiler

## Step-by-Step Learning

This project guides you through 3 steps, each building on the previous one.

### Switching Steps

Use `start-step.sh` to load starter files for any step:

```bash
# See available steps
./start-step.sh

# Load a specific step
./start-step.sh 01-introduction
```

### Available Steps

| Step | Topic |
|------|-------|
| `01-introduction` | Create the Queue class with circular array |
| `02-implementation` | Add enqueue(), dequeue(), front(), back() |
| `03-operations` | Implement clear(), full(), and task scheduling |

## Manual Build (Without Scripts)

If you prefer to compile manually:

```bash
# Linux/macOS
g++ -std=c++17 -o queue main.cpp
./queue

# Windows (with g++)
g++ -std=c++17 -o queue.exe main.cpp
queue.exe
```

## What You'll Build

A Queue class template using a circular array with:

- O(1) enqueue and dequeue operations
- Front and rear pointer management
- Overflow and underflow error handling
- Utility methods: clear(), full(), front(), back()

## Key Concepts

- **FIFO (First In First Out)**: Elements leave in order they arrived
- **Circular Array**: Efficient reuse of array space
- **O(1) Operations**: All operations take constant time
- **Error Handling**: Proper overflow and underflow exceptions

## Support

Need help? Send a screenshot and description of your problem to badreotm27@@gmail.com for help.

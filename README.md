# xv6 Process States Extension

## Overview

This extension introduces new system calls to the **xv6** operating system for monitoring and gathering process information. Additionally, a new user program (`ps.c`) is created to print the state of all active processes in the system.

## Added System Calls

- **getNumProc()**  
  Returns the total number of active processes in the system, including processes in any of the following states: embryo, running, runnable, sleeping, or zombie.

- **getMaxPid()**  
  Returns the maximum PID (Process ID) amongst the PIDs of all currently active processes in the system.

- **getProcInfo(pid, &processInfo)**  
  Passes detailed information about a process (identified by `pid`) through the `processInfo` struct. This function facilitates the transfer of data between user and kernel mode.

## New Files

- **ps.c**  
  A new user-level program that includes the `main` function responsible for handling the required print statements. This file also includes a helper function designed to print information about all processes and their corresponding states based on the given state numbers.

## File Changes

- **proc.c**  
  - Implemented the three new system calls (`getNumProc()`, `getMaxPid()`, and `getProcInfo()`) in this file.
  - Included `processInfo.h` to define and use the `processInfo` struct.

- **proc.h**  
  - Added the following field to the `proc` struct:  
    `int nrswitch; // Number of context switches of the process.`

- **processInfo.h**  
  - Defined the `processInfo` struct, which is used to pass process information between user and kernel modes.

- **usys.S**  
  - Updated to include new system calls.

- **user.h**  
  - Updated to include new system calls.

- **sysproc.c**  
  - Implemented the logic for the new system calls.

- **syscall.h**  
  - Updated to include new system calls.

- **syscall.c**  
  - Updated to handle new system calls.

- **defs.h**  
  - Updated to include function prototypes for new system calls.

- **Makefile**  
  - Added `ps.c` to the **EXTRA** and **UPROGS** sections to include it in the compilation process for the new xv6 executable.

## Usage

1. Build the project using `make` to include the new features.
2. Run the `ps` program to view the states of all active processes in the system.


# TivaC-TM4C123GH6PM

Implementation of Interrupt, GPIO, Timer and Systick Timer

App layer contains main.c

Mcal layer - MicroController Abstraction Layer: contains all MicroController Peripheral drivers
  Inside every driver are 2 folders, 
    The interface folder: contains a .h file and a .c file
    The header file contains all function declarations, enums and structs
    The C file contains the implementation
    
    The Private folder contains a private header
    The header file contains all the addresses related to the peripheral
    
    - A Configuration folder can be added to contain the enums and structs instead of the interface
      header file
- A Hal Layer - Hardware Abstraction Layer can be added as required
  The Hal Layer contains drivers related to all external components, example: LEDs, Buttons, etc.
  

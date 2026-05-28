#ifndef PC_H
#define PC_H

// Banyak elemen pada List
#define NBELM 5

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* === ADT === */
/* Objects */
typedef struct {
    char name[100];
    char socket[20];
    int tdp;
} CPU;
/* 
    Relationship
    - Motherboard [DONE]
    - PSU
*/

typedef struct {
    char name[100];
    int tdp;
} GPU;
/* 
    Relationship
    - PSU
*/

typedef struct {
    char name[100];
    char socket[20];
    int ddr;
} Motherboard;
/* 
    Relationship
    - CPU [DONE]
    - RAM [DONE]
*/

typedef struct {
    char name[100];
    int power;
} PSU;
/* 
    Relationship
    - CPU
    - GPU
*/

typedef struct {
    char name[100];
    int ddr;
} RAM;
/* 
    Relationship
    - Motherboard [DONE]
*/

typedef struct {
    char name[100];
    char type[20]; // HDD vs SSD
} Storage;

// typedef struct {
//     CPU cpu;
//     GPU gpu;
//     Motherboard motherboard;
//     PSU psu;
//     RAM ram;
//     Storage storage;
// } PC;

/* List */
typedef struct {
    CPU container[NBELM];
    int size;
} ListCPU;

typedef struct {
    Motherboard container[NBELM];
    int size;
} ListMotherboard;

typedef struct {
    RAM container[NBELM];
    int size;
} ListRAM;

// Operators
/// Make
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp);
void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr);
void makeRAM(RAM *ram, char *p_name, int p_ddr);

/// Create List
void createListCPU(ListCPU *L);
void createListMotherboard(ListMotherboard *L);
void createListRAM(ListRAM *L);

/// Print List
void printListCPU(ListCPU L);
void printListMotheboard(ListMotherboard L);
void printListRAM(ListRAM L);

/// Insert Item
void insertListCPU(ListCPU *L, CPU item);
void insertListMotherboard(ListMotherboard *L, Motherboard item);
void insertListRAM(ListRAM *L, RAM item);

#endif
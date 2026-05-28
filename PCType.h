#ifndef PCType_H
#define PCType_H

// Banyak elemen pada List
#define NBELM 5
#define PC_MAX 9999999

#define first(LL) (LL).first
#define info(P) (P)->info
#define next(P) (P)->next

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

typedef struct {
    CPU cpu;
    Motherboard motherboard;
    RAM ram;
    // PSU psu;
    // GPU gpu;
    // Storage storage;
} PC; // Sementara beberapa komponen

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

/* Linked List */
typedef PC infoType;
typedef struct tNodePC* Address;

typedef struct tNodePC {
    infoType info;
    Address next;
} NodePC;

typedef struct {
    Address first;
} LListPC;

// Operators
/// Linked List
Address alokasi(infoType PC);
void dealokasi(Address P);
int nbElmLList(LListPC LL);

/// Make
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp);
void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr);
void makeRAM(RAM *ram, char *p_name, int p_ddr);
void makePC(PC *pc, CPU cpu, Motherboard mobo, RAM ram); // Sementara 3 komponen

/// Create Koleksi
void createListCPU(ListCPU *L);
void createListMotherboard(ListMotherboard *L);
void createListRAM(ListRAM *L);
void createLListPC(LListPC *LL);

/// Print Koleksi
void printListCPU(ListCPU L);
void printListMotheboard(ListMotherboard L);
void printListRAM(ListRAM L);
void printLListPC(LListPC LL);

/// Insert Item
void insertListCPU(ListCPU *L, CPU item);
void insertListMotherboard(ListMotherboard *L, Motherboard item);
void insertListRAM(ListRAM *L, RAM item);
void insertLListPC(LListPC *LL, infoType PC);

#endif
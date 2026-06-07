/* 
 *  Pembuat     : Rafif Setya Imaduddin (24060124130115)
 *  Mata Kuliah : Analisis dan Strategi Algoritma
 *  Kelas       : E
 */

#ifndef PCType_H
#define PCType_H

// Makro
#define nbElmList 5

/// Linked List
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

typedef struct {
    char name[100];
    int tdp;
} GPU;

typedef struct {
    char name[100];
    char socket[20];
    int ddr;
    char storage_interface[5];
} Motherboard;

typedef struct {
    char name[100];
    int power;
} PSU;

typedef struct {
    char name[100];
    int ddr;
} RAM;

typedef struct {
    char name[100];
    char interface[5]; // M2 / SATA
} Storage;

typedef struct {
    CPU cpu;
    Motherboard motherboard;
    RAM ram;
    PSU psu;
    GPU gpu;
    Storage storage; 
} PC;

/* List */
typedef struct {
    CPU container[nbElmList];
    int nbElm;
} ListCPU;

typedef struct {
    Motherboard container[nbElmList];
    int nbElm;
} ListMotherboard;

typedef struct {
    RAM container[nbElmList];
    int nbElm;
} ListRAM;
    
typedef struct {
    PSU container[nbElmList];
    int nbElm;
} ListPSU;

typedef struct {
    GPU container[nbElmList];
    int nbElm;
} ListGPU;

typedef struct {
    Storage container[nbElmList];
    int nbElm;
} ListStorage;

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

/// Make
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp);
void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr, char *p_interface);
void makeRAM(RAM *ram, char *p_name, int p_ddr);
void makePSU(PSU *psu, char *p_name, int p_power);
void makeGPU(GPU *gpu, char *p_name, int p_tdp);
void makeStorage(Storage *storage, char *p_name, char *p_interface);
PC makePC(CPU cpu, Motherboard mobo, RAM ram, PSU psu, GPU gpu, Storage storage); 

/// Create Koleksi
void createListCPU(ListCPU *L);
void createListMotherboard(ListMotherboard *L);
void createListRAM(ListRAM *L);
void createListPSU(ListPSU *L);
void createListGPU(ListGPU *L);
void createListStorage(ListStorage *L);
void createLListPC(LListPC *LL);

/// Print Koleksi
void printListCPU(ListCPU L);
void printListMotherboard(ListMotherboard L);
void printListRAM(ListRAM L);
void printListPSU(ListPSU L);
void printListGPU(ListGPU L);
void printListStorage(ListStorage L);
void printLListPC(LListPC LL);

/// Insert Item
void insertListCPU(ListCPU *L, CPU item);
void insertListMotherboard(ListMotherboard *L, Motherboard item);
void insertListRAM(ListRAM *L, RAM item);
void insertListPSU(ListPSU *L, PSU item);
void insertListGPU(ListGPU *L, GPU item);
void insertListStorage(ListStorage *L, Storage item);
void insertLListPC(LListPC *LL, infoType PC);

/// Selector
CPU selectorCPU(ListCPU L, int index);
Motherboard selectorMotherboard(ListMotherboard L, int index);
RAM selectorRAM(ListRAM L, int index);
PSU selectorPSU(ListPSU L, int index);
GPU selectorGPU(ListGPU L, int index);
Storage selectorStorage(ListStorage L, int index);
Storage getStorageFromPC(PC pc);

/// nbElm
int nbElmCPU(ListCPU L);
int nbElmMotherboard(ListMotherboard L);
int nbElmRAM(ListRAM L);
int nbElmPSU(ListPSU L);
int nbElmGPU(ListGPU L);
int nbElmStorage(ListStorage L);
int nbElmPC(LListPC LL);

/// Inisialisasi PC
void initializePC(PC *pc);
void initializeCPU(CPU *cpu);
void initializeGPU(GPU *gpu);
void initializePSU(PSU *psu);
void initializeRAM(RAM *ram);
void initializeStorage(Storage *storage);
void initializeMotherboard(Motherboard *mobo);

#endif
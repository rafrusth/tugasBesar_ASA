/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#ifndef PCType_H
#define PCType_H

// Makro
/// Banyak elemen pada list komponen PC
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
/* 
    Relationship
    - Motherboard [DONE]
    - PSU [DONE]
*/

typedef struct {
    char name[100];
    int tdp;
} GPU;
/* 
    Relationship
    - PSU [DONE]
*/

typedef struct {
    char name[100];
    char socket[20];
    int ddr;
    char storage_interface[5];
} Motherboard;
/* 
    Relationship
    - CPU [DONE]
    - RAM [DONE]
    - Storage
*/

typedef struct {
    char name[100];
    int power;
} PSU;
/* 
    Relationship
    - CPU [DONE]
    - GPU [DONE]
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
    char interface[5]; // M2 / SATA
} Storage;
/* 
    Relationship
    - Motherboard
*/

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
    int size;
} ListCPU;

typedef struct {
    Motherboard container[nbElmList];
    int size;
} ListMotherboard;

typedef struct {
    RAM container[nbElmList];
    int size;
} ListRAM;
    
typedef struct {
    PSU container[nbElmList];
    int size;
} ListPSU;

typedef struct {
    GPU container[nbElmList];
    int size;
} ListGPU;

typedef struct {
    Storage container[nbElmList];
    int size;
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
int nbElmLList(LListPC LL);

/// Make
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp);
void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr, char *p_interface);
void makeRAM(RAM *ram, char *p_name, int p_ddr);
void makePSU(PSU *psu, char *p_name, int p_power);
void makeGPU(GPU *gpu, char *p_name, int p_tdp);
void makeStorage(Storage *storage, char *p_name, char *p_interface);
void makePC(PC *pc, CPU cpu, Motherboard mobo, RAM ram, PSU psu, GPU gpu, Storage storage); 

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

#endif
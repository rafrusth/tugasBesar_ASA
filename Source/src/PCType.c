/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#ifndef PCType_C
#define PCType_C
#include "../../Header/include/PCType.h"

/// Linked List
Address alokasi(infoType PC) {
    // Kamus Lokal
    Address P;

    // Algoritma
    P = (Address) malloc(sizeof(NodePC));
    if (P != NULL) {
        info(P) = PC;
        next(P) = NULL;
    }

    return P;
}

void dealokasi(Address P) {
    // Kamus Lokal

    // Algoritma
    if (P != NULL) {
        next(P) = NULL;
    }
    free(P);
    P = NULL;
}

/// Make Objek
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp) {
    // Kamus Lokal

    // Algoritma
    strcpy((*cpu).name, p_name);
    strcpy((*cpu).socket, p_socket);
    (*cpu).tdp = p_tdp;
}

void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr, char *p_interface) {
    // Kamus Lokal

    // Algoritma
    strcpy((*mobo).name, p_name);
    strcpy((*mobo).socket, p_socket);
    strcpy((*mobo).storage_interface, p_interface);
    (*mobo).ddr = p_ddr;
}

void makeRAM(RAM *ram, char *p_name, int p_ddr) {
    // Kamus Lokal

    // Algoritma
    strcpy((*ram).name,p_name);
    (*ram).ddr = p_ddr;
}

void makePSU(PSU *psu, char *p_name, int p_power) {
    // Kamus Lokal

    // Algoritma
    strcpy((*psu).name, p_name);
    (*psu).power = p_power;
}

void makeGPU(GPU *gpu, char *p_name, int p_tdp) {
    // Kamus Lokal

    // Algoritma
    strcpy((*gpu).name, p_name);
    (*gpu).tdp = p_tdp;
}

void makeStorage(Storage *storage, char *p_name, char *p_interface) {
    // Kamus Lokal

    // Algoritma
    strcpy((*storage).name, p_name);
    strcpy((*storage).interface, p_interface);
}

void makePC(PC *pc, CPU p_cpu, Motherboard p_mobo, RAM p_ram, PSU p_psu, GPU p_gpu, Storage p_storage) {
    // Kamus Lokal

    // Algoritma
    (*pc).cpu = p_cpu;
    (*pc).motherboard = p_mobo;
    (*pc).ram = p_ram;
    (*pc).psu = p_psu;
    (*pc).gpu = p_gpu;
    (*pc).storage = p_storage;
}

/// Create Koleksi
void createListCPU(ListCPU *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializeCPU(&(*L).container[i]);
    }
}

void createListMotherboard(ListMotherboard *L) {
    // Kamus Lokal
    int i;
    
    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializeMotherboard(&(*L).container[i]);
    }
}

void createListRAM(ListRAM *L) {
    // Kamus Lokal
    int i;
    
    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializeRAM(&(*L).container[i]);
    }
}

void createListPSU(ListPSU *L) {
    // Kamus Lokal
    int i;
    
    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializePSU(&(*L).container[i]);
    }
}

void createListGPU(ListGPU *L) {
    // Kamus Lokal
    int i;
    
    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializeGPU(&(*L).container[i]);
    }
}

void createListStorage(ListStorage *L) {
    // Kamus Lokal
    int i;
    
    // Algoritma
    (*L).nbElm = 0;
    for (i = 0; i < nbElmList; i++) {
        initializeStorage(&(*L).container[i]);
    }
}

void createLListPC(LListPC *LL) {
    // Kamus Lokal
    
    // Algoritma
    first(*LL) = NULL;
}

/// Print Koleksi
void printListCPU(ListCPU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - Socket : %s\n   - TDP    : %d W\n\n", i + 1,
                                                L.container[i].name,
                                                L.container[i].socket,
                                                L.container[i].tdp);
    }
}

void printListMotherboard(ListMotherboard L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - Socket\t\t: %s\n   - DDR\t\t: %d\n   - Storage Interface\t: %s\n\n", i + 1,
                                                L.container[i].name,
                                                L.container[i].socket,
                                                L.container[i].ddr,
                                                L.container[i].storage_interface);
    }
}

void printListRAM(ListRAM L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - DDR: %d\n\n", i + 1,
                                    L.container[i].name,
                                    L.container[i].ddr);
    }
}

void printListPSU(ListPSU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - Power: %d W\n\n", i + 1,
                                        L.container[i].name,
                                        L.container[i].power);
    }
}

void printListGPU(ListGPU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - TDP: %d W\n\n", i + 1,
                                        L.container[i].name,
                                        L.container[i].tdp);
    }
}

void printListStorage(ListStorage L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.nbElm; i++) {
        printf("%d) %s\n   - Interface: %s\n\n", i + 1,
                                        L.container[i].name,
                                        L.container[i].interface);
    }
}

void printLListPC(LListPC LL) {
    // Kamus Lokal
    Address P;
    int counter;
    
    // Algoritma
    P = first(LL);
    if (P != NULL) {
        counter = 0;
        do {
            counter++;
            printf("\n[ ========= PC %d ========= ]\n", counter);
            printf("/* Spesifikasi Komponen */\n");
            printf("- [CPU] Socket        : %s\n", info(P).cpu.socket);
            printf("- [RAM] DDR           : %d\n", info(P).ram.ddr);
            printf("- [PSU] Wattage       : %d W\n", info(P).psu.power);
            printf("- [Storage] Interface : %s\n", info(P).storage.interface);

            printf("\n/* Rekomendasi Komponen PC */\n");
            printf("- CPU\t      : %s\n", info(P).cpu.name);
            printf("- GPU\t      : %s\n", info(P).gpu.name);
            printf("- RAM\t      : %s\n", info(P).ram.name);
            printf("- Storage     : %s\n", info(P).storage.name);
            printf("- Motherboard : %s\n", info(P).motherboard.name);
            printf("- PSU\t      : %s\n", info(P).psu.name);
            P = next(P);
        } while (!(P == NULL));
    }
}

/// Insert Item
void insertListCPU(ListCPU *L, CPU item) {
    // Kamus Lokal
    bool empty;
    int i, emptyIdx;

    // Algoritma
    empty = false;
    if (nbElmCPU(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while(!empty && i < nbElmList) {
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertListMotherboard(ListMotherboard *L, Motherboard item) {
    // Kamus Lokal
    bool empty;
    int i, emptyIdx;

    // Algoritma
    empty = false;
    if (nbElmMotherboard(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < nbElmList) {
            // Beda -> 1
            // Sama -> 0
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertListRAM(ListRAM *L, RAM item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if (nbElmRAM(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < nbElmList) {
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertListPSU(ListPSU *L, PSU item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if (nbElmPSU(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < nbElmList) {
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertListGPU(ListGPU *L, GPU item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if (nbElmGPU(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < nbElmList) {
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertListStorage(ListStorage *L, Storage item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if (nbElmStorage(*L) < nbElmList) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < nbElmList) {
            if (!strcmp((*L).container[i].name, "NULL")) {
                empty = true;
                emptyIdx = i;
            }
            i++;
        }
        (*L).container[emptyIdx] = item;
        (*L).nbElm++;
    }
}

void insertLListPC(LListPC *LL, infoType PC) {
    // Kamus Lokal
    Address P,Q;

    // Algoritma
    P = alokasi(PC);
    Q = first(*LL);
    if (P != NULL) {
        if (first(*LL) == NULL) {
            first(*LL) = P;
        } else {
            while (next(Q) != NULL) {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

/// Akses by Index
CPU selectorCPU(ListCPU L, int index) {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

Motherboard selectorMotherboard(ListMotherboard L, int index)  {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

RAM selectorRAM(ListRAM L, int index)  {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

PSU selectorPSU(ListPSU L, int index)  {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

GPU selectorGPU(ListGPU L, int index)  {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

Storage selectorStorage(ListStorage L, int index)  {
    // Kamus Lokal

    // Algoritma
    return L.container[index];
}

Storage getStorageFromPC(PC pc) {
    // Kamus Lokal

    // Algoritma
    return pc.storage;
}

/// NbELm
int nbElmCPU(ListCPU L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmMotherboard(ListMotherboard L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmRAM(ListRAM L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmPSU(ListPSU L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmGPU(ListGPU L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmStorage(ListStorage L) {
    // Kamus Lokal

    // Algoritma
    return L.nbElm;
}

int nbElmPC(LListPC LL) {
    // Kamus Lokal
    Address P;
    int counter;

    // Algoritma
    P = first(LL);
    counter = 0;
    while (P != NULL) {
        counter++;
        P = next(P);
    }

    return counter;
}

/// Initialize PC
void initializePC(PC *pc) {
    // Kamus Lokal

    // Algoritma
    initializeCPU(&(*pc).cpu);
    initializeGPU(&(*pc).gpu);
    initializePSU(&(*pc).psu);
    initializeRAM(&(*pc).ram);
    initializeStorage(&(*pc).storage);
    initializeMotherboard(&(*pc).motherboard);
}

void initializeCPU(CPU *cpu) {
    // Kamus Lokal

    // Algoritma
    strcpy((*cpu).name, "NULL");
    strcpy((*cpu).socket, "NULL");
    (*cpu).tdp = -999;
}

void initializeGPU(GPU *gpu) {
    // Kamus Lokal

    // Algoritma
    strcpy((*gpu).name, "NULL");
    (*gpu).tdp = -999;
}

void initializePSU(PSU *psu) {
    // Kamus Lokal

    // Algoritma
    strcpy((*psu).name, "NULL");
    (*psu).power = -999;
}

void initializeRAM(RAM *ram) {
    // Kamus Lokal

    // Algoritma
    strcpy((*ram).name, "NULL");
    (*ram).ddr = -999;
}

void initializeStorage(Storage *storage) {
    // Kamus Lokal

    // Algoritma
    strcpy((*storage).name, "NULL");
    strcpy((*storage).interface, "NULL");
}

void initializeMotherboard(Motherboard *mobo) {
    // Kamus Lokal

    // Algoritma
    strcpy((*mobo).name, "NULL");
    strcpy((*mobo).socket, "NULL");
    strcpy((*mobo).storage_interface, "NULL");
    (*mobo).ddr = -999;
}

#endif
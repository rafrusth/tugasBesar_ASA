#ifndef PCType_C
#define PCType_C
#include "PCType.h"

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


int nbElmLList(LListPC LL) {
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

/// Make Objek
void makeCPU(CPU *cpu, char *p_name, char *p_socket, int p_tdp) {
    // Kamus Lokal

    // Algoritma
    strcpy((*cpu).name, p_name);
    strcpy((*cpu).socket, p_socket);
    (*cpu).tdp = p_tdp;
}

void makeMotherboard(Motherboard *mobo, char *p_name, char *p_socket, int p_ddr) {
    // Kamus Lokal

    // Algoritma
    strcpy((*mobo).name, p_name);
    strcpy((*mobo).socket, p_socket);
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

void makePC(PC *pc, CPU p_cpu, Motherboard p_mobo, RAM p_ram, PSU p_psu, GPU p_gpu) {
    // Kamus Lokal

    // Algoritma
    (*pc).cpu = p_cpu;
    (*pc).motherboard = p_mobo;
    (*pc).ram = p_ram;
    (*pc).psu = p_psu;
    (*pc).gpu = p_gpu;
}

/// Create Koleksi
void createListCPU(ListCPU *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < nbElmList; i++) {
        strcpy((*L).container[i].name, "NULL");
        strcpy((*L).container[i].socket, "NULL");
        (*L).container[i].tdp = -999;
    }
}

void createListMotherboard(ListMotherboard *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < nbElmList; i++) {
        strcpy((*L).container[i].name, "NULL");
        strcpy((*L).container[i].socket, "NULL");
        (*L).container[i].ddr = -999;
    }
}

void createListRAM(ListRAM *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < nbElmList; i++) {
        strcpy((*L).container[i].name, "NULL");
        (*L).container[i].ddr = -999;
    }
}

void createListPSU(ListPSU *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < nbElmList; i++) {
        strcpy((*L).container[i].name, "NULL");
        (*L).container[i].power = -999;
    }
}

void createListGPU(ListGPU *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < nbElmList; i++) {
        strcpy((*L).container[i].name, "NULL");
        (*L).container[i].tdp = -999;
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
    for (i = 0; i < L.size; i++) {
        printf("%d) %s [Socket: %s, TDP: %d]\n", i + 1,
                                                L.container[i].name,
                                                L.container[i].socket,
                                                L.container[i].tdp);
    }
}

void printListMotherboard(ListMotherboard L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.size; i++) {
        printf("%d) %s [Socket: %s, DDR: %d]\n", i + 1,
                                                L.container[i].name,
                                                L.container[i].socket,
                                                L.container[i].ddr);
    }
}

void printListRAM(ListRAM L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.size; i++) {
        printf("%d) %s [DDR: %d]\n", i + 1,
                                    L.container[i].name,
                                    L.container[i].ddr);
    }
}

void printListPSU(ListPSU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.size; i++) {
        printf("%d) %s [Power: %d W]\n", i + 1,
                                        L.container[i].name,
                                        L.container[i].power);
    }
}

void printListGPU(ListGPU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < L.size; i++) {
        printf("%d) %s [Power: %d W]\n", i + 1,
                                        L.container[i].name,
                                        L.container[i].tdp);
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
            printf("- [CPU] Socket  : %s\n", info(P).cpu.socket);
            printf("- [RAM] DDR     : %d\n", info(P).ram.ddr);
            printf("- [PSU] Wattage : %d W\n", info(P).psu.power);

            printf("\n/* Rekomendasi Komponen PC */\n");
            printf("- CPU\t      : %s\n", info(P).cpu.name);
            printf("- GPU\t      : %s\n", info(P).gpu.name);
            printf("- RAM\t      : %s\n", info(P).ram.name);
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
    if ((*L).size < nbElmList) {
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
        (*L).size++;
    }
}

void insertListMotherboard(ListMotherboard *L, Motherboard item) {
    // Kamus Lokal
    bool empty;
    int i, emptyIdx;

    // Algoritma
    empty = false;
    if ((*L).size < nbElmList) {
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
        (*L).size++;
    }
}

void insertListRAM(ListRAM *L, RAM item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if ((*L).size < nbElmList) {
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
        (*L).size++;
    }
}

void insertListPSU(ListPSU *L, PSU item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if ((*L).size < nbElmList) {
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
        (*L).size++;
    }
}

void insertListGPU(ListGPU *L, GPU item) {
    // Kamus Lokal
    int i, emptyIdx;
    bool empty;

    // Algoritma
    if ((*L).size < nbElmList) {
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
        (*L).size++;
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

#endif
#ifndef PC_C
#define PC_C
#include "PC.h"

/// Make
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

/// Create List
void createListCPU(ListCPU *L) {
    // Kamus Lokal
    int i;

    // Algoritma
    (*L).size = 0;
    for (i = 0; i < NBELM; i++) {
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
    for (i = 0; i < NBELM; i++) {
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
    for (i = 0; i < NBELM; i++) {
        strcpy((*L).container[i].name, "NULL");
        (*L).container[i].ddr = -999;
    }
}

/// Print List
void printListCPU(ListCPU L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < NBELM; i++) {
        printf("%d) %s [Socket: %s, TDP: %d]\n", i + 1,
                                            L.container[i].name,
                                            L.container[i].socket,
                                            L.container[i].tdp);
    }
}

void printListMotheboard(ListMotherboard L) {
    // Kamus Lokal
    int i;

    // Algoritma
    for (i = 0; i < NBELM; i++) {
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
    for (i = 0; i < NBELM; i++) {
        printf("%d) %s [DDR: %d]\n", i + 1,
                                L.container[i].name,
                                L.container[i].ddr);
    }
}

/// Insert Item
void insertListCPU(ListCPU *L, CPU item) {
    // Kamus Lokal
    bool empty;
    int i, emptyIdx;

    // Algoritma
    empty = false;
    if ((*L).size < NBELM) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while(!empty && i < NBELM) {
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

void insertListMotherboard(ListMotherboard *L, Motherboard item) {
    // Kamus Lokal
    bool empty;
    int i, emptyIdx;

    // Algoritma
    empty = false;
    if ((*L).size < NBELM) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < NBELM) {
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
    if ((*L).size < NBELM) {
        empty = false;
        emptyIdx = -1;
        i = 0;
        while (!empty && i < NBELM) {
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

#endif
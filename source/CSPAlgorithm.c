/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#ifndef CSPAlgorithm_C
#define CSPAlgorithm_C

#include "../header/CSPAlgorithm.h"

bool isCompatible(CPU cpu, Motherboard mobo, RAM ram, PSU psu, GPU gpu, Storage storage) {
    // Kamus Lokal

    // Algoritma
    if (!strcmp(cpu.name, "NULL") || !strcmp(mobo.name, "NULL")) {
        return true;
    } else if (!strcmp(ram.name, "NULL")) {
        return (!strcmp(cpu.socket, mobo.socket));
    } else if (!strcmp(psu.name, "NULL")) {
        return ((ram.ddr == mobo.ddr) && !strcmp(cpu.socket, mobo.socket));
    } else if (!strcmp(gpu.name, "NULL")) {
        return ((ram.ddr == mobo.ddr) && !strcmp(cpu.socket, mobo.socket) && (cpu.tdp <= psu.power));
    } else if (!strcmp(storage.name, "NULL")) {
        return ((ram.ddr == mobo.ddr) && !strcmp(cpu.socket, mobo.socket) && ((cpu.tdp + gpu.tdp) <= psu.power));
    } else {
        return ((ram.ddr == mobo.ddr) && !strcmp(cpu.socket, mobo.socket) && ((cpu.tdp + gpu.tdp) <= psu.power) && (!strcmp(mobo.storage_interface, storage.interface)));
    }
}



int bruteForce(LListPC *ll_pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage) {
    // Kamus Lokal
    int count_cpu, count_mobo, count_ram, count_psu, count_gpu, count_storage;
    int counter;
    PC tempPC;

    // Algoritma
    counter = 0;
    for (count_cpu = 0; count_cpu < nbElmCPU(l_cpu); count_cpu++) {
        for (count_mobo = 0; count_mobo < nbElmMotherboard(l_mobo); count_mobo++) {
            for (count_ram = 0; count_ram < nbElmRAM(l_ram); count_ram++) {
                for (count_psu = 0; count_psu < nbElmPSU(l_psu); count_psu++) {    
                    for (count_gpu = 0; count_gpu < nbElmGPU(l_gpu); count_gpu++) {
                        for (count_storage = 0; count_storage < nbElmStorage(l_storage); count_storage++) {
                            counter++;
                            if (isCompatible(selectorCPU(l_cpu, count_cpu), selectorMotherboard(l_mobo, count_mobo), selectorRAM(l_ram, count_ram), selectorPSU(l_psu, count_psu), selectorGPU(l_gpu, count_gpu), selectorStorage(l_storage, count_storage))) {
                                tempPC = makePC(selectorCPU(l_cpu, count_cpu), selectorMotherboard(l_mobo, count_mobo), selectorRAM(l_ram, count_ram), selectorPSU(l_psu, count_psu), selectorGPU(l_gpu, count_gpu), selectorStorage(l_storage, count_storage));
                                insertLListPC(&(*ll_pc), tempPC);
                            }
                        }
                    }
                }
            }
        }
    }

    return counter;
}

bool isCompatibleBt(PC pc, int n) {
    // Kamus Lokal

    // Algoritma
    switch(n) {
        case 1:
            return true;
        
        case 2:
            return !strcmp(pc.cpu.socket, pc.motherboard.socket);
        
        case 3:
            return (pc.ram.ddr == pc.motherboard.ddr);
    
        case 4:
            return (pc.cpu.tdp <= pc.psu.power);
            
        case 5:
            return ((pc.cpu.tdp + pc.gpu.tdp) <= pc.psu.power);
        
        case 6:
            return !strcmp(pc.motherboard.storage_interface, pc.storage.interface);

        default:
            return false;
    }
}

void backtracking(int n, int *iteration, LListPC *ll_pc, PC pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage) {
    // Kamus Lokal
    int i, currNbElm;

    // Algoritma
    if (n > 6) {
        insertLListPC(&(*ll_pc), pc);
    } else {
        currNbElm = 0;
        if (n == 1) {
            currNbElm = nbElmCPU(l_cpu);
        } else if (n == 2) {
            currNbElm = nbElmMotherboard(l_mobo);
        } else if (n == 3) {
            currNbElm = nbElmRAM(l_ram);
        } else if (n == 4) {
            currNbElm = nbElmPSU(l_psu);
        } else if (n == 5) {
            currNbElm = nbElmGPU(l_gpu);
        } else if (n == 6) {
            currNbElm = nbElmStorage(l_storage);
        }

        for (i = 0; i < currNbElm; i++) {
            (*iteration)++;
            if (n == 1) {
                pc.cpu = selectorCPU(l_cpu, i);
            } else if (n == 2) {
                pc.motherboard = selectorMotherboard(l_mobo, i);
            } else if (n == 3) {
                pc.ram = selectorRAM(l_ram, i);
            } else if (n == 4) {
                pc.psu = selectorPSU(l_psu, i);
            } else if (n == 5) {
                pc.gpu = selectorGPU(l_gpu, i);
            } else if (n == 6) {
                pc.storage = selectorStorage(l_storage, i);
            }

            if (isCompatibleBt(pc, n)) {
                backtracking(n + 1, iteration, &(*ll_pc), pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage);
            }
        }
    }
}

void limitDepth(int n, int limit, int *iteration, PC pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage, LListPC *ll_pc) {
    // Kamus Lokal
    int i;

    // Algoritma
    if (n > limit) {
        if (n == 7) {
            insertLListPC(ll_pc, pc);
        }
    } else {
        if (n == 1) {
                for (i = 0; i < nbElmCPU(l_cpu); i++) {
                    pc.cpu = selectorCPU(l_cpu, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            } else if (n == 2) {
                for (i = 0; i < nbElmMotherboard(l_mobo); i++) {
                    pc.motherboard = selectorMotherboard(l_mobo, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            } else if (n == 3) {
                for (i = 0; i < nbElmRAM(l_ram); i++) {
                    pc.ram = selectorRAM(l_ram, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            } else if (n == 4) {
                for (i = 0; i < nbElmPSU(l_psu); i++) {
                    pc.psu = selectorPSU(l_psu, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            } else if (n == 5) {
                for (i = 0; i < nbElmGPU(l_gpu); i++) {
                    pc.gpu = selectorGPU(l_gpu, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            } else if (n == 6) {
                for (i = 0; i < nbElmStorage(l_storage); i++) {
                    pc.storage = selectorStorage(l_storage, i);
                    (*iteration)++;
                    if (isCompatibleBt(pc, n)) {
                        limitDepth(n + 1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
                    }
                }
            }
    }
}

void iterativeDeepeningSearch(int max_n, int *iteration, LListPC *ll_pc, PC pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage) {
    // Kamus Lokal
    int limit;

    // Algoritma
    for (limit = 1; limit <= max_n; limit++) {
        limitDepth(1, limit, iteration, pc, l_cpu, l_mobo, l_ram, l_psu, l_gpu, l_storage, ll_pc);
    }
}

#endif
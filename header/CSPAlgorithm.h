/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#ifndef CSPAlgorithm_H
#define CSPAlgorithm_H

#include "PCType.h"

bool isCompatible(CPU cpu, Motherboard mobo, RAM ram, PSU psu, GPU gpu, Storage storage);
int bruteForce(LListPC *ll_pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage);

bool isCompatibleBt(PC pc, int n);
void backtracking(int n, int *iteration, LListPC *ll_pc, PC pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage);

#endif
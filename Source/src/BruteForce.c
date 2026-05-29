/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#include "../../Header/include/BruteForce.h"

void bruteForce(LListPC *ll_pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu, ListStorage l_storage) {
    // Kamus Lokal
    int count_cpu, count_mobo, count_ram, count_psu, count_gpu, count_storage;
    PC tempPC;

    // Algoritma
    for (count_cpu = 0; count_cpu < l_cpu.size; count_cpu++) {
        for (count_mobo = 0; count_mobo < l_mobo.size; count_mobo++) {
            for (count_ram = 0; count_ram < l_ram.size; count_ram++) {
                for (count_psu = 0; count_psu < l_psu.size; count_psu++) {    
                    for (count_gpu = 0; count_gpu < l_gpu.size; count_gpu++) {
                        for (count_storage = 0; count_storage < l_storage.size; count_storage++) {
                            if (!strcmp(l_cpu.container[count_cpu].socket, l_mobo.container[count_mobo].socket)
                                &&
                                (l_mobo.container[count_mobo].ddr == l_ram.container[count_ram].ddr)
                                &&
                                ((l_cpu.container[count_cpu].tdp + l_gpu.container[count_gpu].tdp) <= l_psu.container[count_psu].power)
                                &&
                                (!strcmp(l_mobo.container[count_mobo].storage_interface, l_storage.container[count_storage].interface))) {
                                    makePC(&tempPC, l_cpu.container[count_cpu], l_mobo.container[count_mobo], l_ram.container[count_ram], l_psu.container[count_psu], l_gpu.container[count_gpu], l_storage.container[count_storage]);
                                    insertLListPC(ll_pc, tempPC);
                            }
                        }
                    }
                }
            }
        }
    }
}


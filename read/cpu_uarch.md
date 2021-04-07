### cpu microarchetecture
- [talk](https://www.infoq.com/presentations/microarchitecture-modern-cpu/)
- cpus are multi socket
- non-uniform memory arch (NUMA), 
- multiple device, multiple sockets, 
- 10, 18, 24 core skylake, 
    - registrers 180 integers / 168 floating points, 1 cycle
   - L1 cache: instructions + data, 4 cycle, 
   - L2 cache: 1MB 16 clock cycle,
   - L3 cache, shared by all core on a die, 16 MB, 11 cycle, 
   - if data has L1, it's also in L2, but not in L3, 
   - caches gets data from RAM - 150 cycle, 
- lstopo to find memories, /proc/cpuinfo, perf, toplev
- TLB : Translation look aside buffer, 
- each process has  a page table, pages can be 4k, 2M, 1G
- os uses pages
- cpu uses cache line of 64 bytes, 
- memory prefetching understanding stepping and striding, 
- pin memory taskset, worker lives in different cores, numactl, 
- improve branch prediction chance, branch target prediction, 
-






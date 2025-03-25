#include "types.h"
#include "stat.h"
#include "user.h"
#include "processInfo.h"


int main() {
    int total = getNumProc();
    int max_pid = getMaxPid();

    printf(1, "Total number of active processes: %d\n", total);
    printf(1, "Maximum PID: %d\n", max_pid);
    printf(1, "PID\tSTATE\t\tPPID\tSZ\tNFD\tNRSWITCH\n");

    for (int pid = 1; pid <= max_pid; pid++) 
    {
        struct processInfo info;
        if (getProcInfo(pid, &info) == 0) 
        {
            char* states;
            switch (info.state) 
            {
            case 1: states = "embryo"; break;
            case 2: states = "sleeping"; break;
            case 3: states = "runnable"; break;
            case 4: states = "running"; break;
            case 5: states = "zombie"; break;
            }
            printf(1, "%d\t%s\t%d\t%d\t%d\t%d\n", pid, states, info.ppid, info.sz, info.nfd, info.nrswitch);
        }
    }

    exit();
}
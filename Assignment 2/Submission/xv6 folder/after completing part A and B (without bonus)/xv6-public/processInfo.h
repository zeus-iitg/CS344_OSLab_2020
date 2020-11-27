#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

struct processInfo
{
    int ppid;
    int psize;
    int numberContextSwitches;
};

#endif
#include "types.h"
#include "stat.h"
#include "user.h"

int useless;

int
main(int argv, char* argc[]){

	if(argv<2){
		printf(1, "Incorrect format!\nFormat: test_scheduler <number of fork processes>\n");

		exit();
	}

	int n=atoi(argc[1]);

	int burst_times[n];

	for(int i=0;i<n;i++){
		burst_times[i] = randomrange(1,1000);
	}

	printf(1, "\tPID \t Type \t Burst Time \t Context Switches\n");
	printf(1, "\t___ \t ____ \t __________ \t ________________\n\n");

	for(int i=0;i<n;i++){
		if(!fork()){

			if(i%2){
				// CPU Bound process
				set_burst_time(burst_times[i]);
				int it=0;
				for(int j=0;j<100;j++){
					for(int k=0;k<10000000;k++){
						if((j+k)%2)it++;
						else it--;
					}
				}
				useless+=it;
				struct processInfo info;
				getCurrentInfo(&info);
				int bt = get_burst_time();
				if(bt<10)
					printf(1, "\t%d \t CPU         %d                  %d\n", getCurrentPID(), bt, info.numberContextSwitches);
				else
					printf(1, "\t%d \t CPU         %d                 %d\n", getCurrentPID(), bt, info.numberContextSwitches);
				exit();	
			} else {
				// I/O Bound Process
				set_burst_time(burst_times[i]);
				for(int i=0;i<10;i++){
					sleep(1);
				}
				struct processInfo info;
				getCurrentInfo(&info);
				int bt = get_burst_time();
				if(bt<10)
					printf(1, "\t%d \t I/O         %d                  %d\n", getCurrentPID(), bt, info.numberContextSwitches);
				else
					printf(1, "\t%d \t I/O         %d                 %d\n", getCurrentPID(), bt, info.numberContextSwitches);
				exit();

			}
		}
	}

	while(wait()!=-1);
	exit();

}
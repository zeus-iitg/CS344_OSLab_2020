#include "types.h"
#include "stat.h"
#include "user.h"

int useless;

int
main(void){


	for(int i=0;i<10;i++){
		if(!fork()){
			int x=0;
			for(int j=0;j<100;j++){
				for(int k=0;k<1000000;k++)
					if((j+k)%2)x++;
					else x--;
			}

			
			useless+=x;


			exit();
		}
	}

	while(wait()!=-1);
	exit();

}
#include <stdio.h>
#include <stdlib.h>

ePersona pers[3] = {{"ape1","nom1",1,0}{"ape2","nom2",2,0}{"ape3","nom3",3,0}};
ePersona auxPer;

int main(){
	for(i=0;i<cant-1;i++){
		for(j=i+1;j<cant;j++){
			if(pers[i].edad > pers[j].edad){
				auxPer = pers[i];
				pers[i] = pers[j];
				pers[j] = auxPer;
			}
		}
	}
	return 0;
}

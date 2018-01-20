#include <stdio.h>
#include <iostream>

#include "RGB.h"

int main(){
	printf("[STATUS] program started\n");

	initUART();
	
	if (UART == -1){
		print("[ERROR] Failed opening UART");
		return 0;
	}
	
	while (1 != 0){
		printf("Enter [addr, R, G, B]: ");
		scanf("%i, %i, %i, %i", &addr, &red, &green, &blue);
		int n = sendRGB(addr, red, green, blue);
		if (n < 0){
			printf("[ERROR] Failed sending data");
		}
	}
    return 0;
}

/* 
    main.c
    Copyright (C) 2016 - Mitch Ward
	
    This software may be modified and distributed under the terms
    of the MIT license.  See the LICENSE file for details.
    
*/

/*  SANSSYSUPDATER - v0.4 */

#include <3ds.h>
#include <stdio.h>

void clearScreen() {
	printf("\e[1;1H\e[2J");
}

int main() {
	gfxInitDefault();
	aptInit();
	fsInit();
	
	consoleInit(GFX_BOTTOM, NULL);
	printf("SansSysUpdater - v0.4 UNSTABLE BUILD!\n");
    printf("\x1b[31mIMPORTANT: THIS IS AN UNSTABLE BUILD, MEANING THAT THIS HAS THE POTENTIAL TO BRICK YOUR DEVICE! BE AWARE.\x1b[0m");
	
	consoleInit(GFX_TOP, NULL);
	
	printf("\x1b[32mHAX INIT...\x1b[0m\n");
	svcSleepThread(2000000000);
	
	clearScreen();
	
	printf("SansSysUpdater\n");
	printf("EXPERIMENTAL 11.x DOWNGRADER\n");
	printf("DO NOT REDISTRIBUTE!\n\n");
	svcSleepThread(500000000);
	
	printf("Press A to downgrade.\n");
	printf("Press START to exit.\n\n");
	
	while (aptMainLoop()) {
		hidScanInput();
		u32 kDown = hidKeysDown();
		
		if (kDown & KEY_A) {
			printf("Getting system information...\n");
			svcSleepThread(5000000000);
			printf("Downgrading...\n");
			FSUSER_InitializeCtrFileSystem();
			svcSleepThread(5000000000);
				printf("NATIVE_FIRM         ");
				svcSleepThread(1000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(2000000000);
				printf("000400DB00017102.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("000400DB00016102.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(6000000000);
				printf("000400DB00010502.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(7000000000);
				printf("000400DB00010302.cia");
				svcSleepThread(6000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(1000000000);
				printf("0004009B00013102.cia");
				svcSleepThread(10000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("0004009B00013102.cia");
				svcSleepThread(70000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("0004009B00013102.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("000400DB00016002.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(6000000000);
				printf("000400DB00010502.cia");
				svcSleepThread(3000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(7000000000);
				printf("000400DB00010302.cia");
				svcSleepThread(6000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(100000000);
				printf("0004009B00013102.cia");
				svcSleepThread(10000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("0004009B00012102.cia");
				svcSleepThread(70000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(5000000000);
				printf("0004009B00010402.cia");
				svcSleepThread(1000000000);
			    printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(3000000000);
				printf("0004801000022900.cia");
				svcSleepThread(4000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(6000000000);
				printf("0004001B00018002.cia");
				svcSleepThread(8000000000);
				printf("    \x1b[32mInstalled\x1b[0m\n");
				svcSleepThread(4000000000);
				printf("000400300000BE02.cia");
				svcSleepThread(8000000000);
			printf("\x1b[31mERROR: \x1b[0mDowngrading failed. Rebooting...\n");
			svcSleepThread(800000000);
		}
		
		if (kDown & KEY_START) break;
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}
	
	gfxExit();
	aptExit();
	fsExit();
	return 0;
}

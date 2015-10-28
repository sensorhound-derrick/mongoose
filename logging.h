
#ifndef __LOGGING_H
#define __LOGGING_H

#include "stdio.h"

typedef unsigned short int uint16_t;

FILE *log_fp;
char log_filename[] = "trace.tr";

void sensortracer_init() {
	log_fp = fopen(log_filename, "w");
	if (log_fp == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", log_filename);
		exit(1);
	}
}

void CFTracerM__StdControl__exit() {
	fclose(log_fp);
}

//void sersor_tracer_recordUint16(uint16_t label) {
//	fwrite(&label, 2, 1, log_fp);
//}

// PATH Label - PPPP PPPP PPPP PXSE ->
// PPPP PPPP PPPP P - PathId,  
// X - procedure/path,
// S - start/not,
// E - End/Loop
unsigned int sensor_tracer_recordLabel(unsigned int id , unsigned int isPath , unsigned int isEnd ) {
	uint16_t label = 0;

	label = label | (id << 3);
	// compress bit is turned off by default.		
	if (isPath) label = label | 0x04;

	if (isEnd) label = label | 0x01;

	//printf("recordLabel - %d 0x%x\n", id, label);
	//sensor_tracer_recordUint16(label);
	fwrite(&label, 2, 1, log_fp);

	return 0;
}

#endif

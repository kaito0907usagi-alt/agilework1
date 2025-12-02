#ifndef MyServer_h
#define MyServer_h

#include "WiFiS3.h"
#include "config.h"

void initServer();
void handleClientRequest(double sensorValue);

#endif
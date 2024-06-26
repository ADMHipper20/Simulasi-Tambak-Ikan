#ifndef OPSI_H
#define OPSI_H

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

int feedFish();
void checkTemperature();
void checkOxygen_stabilizeOxygenLevels();
void cleanFishPond();
int addFish(int tambakIkan[][10], int nomorKolam, int totalIkan[], char jenisIkan[][20], float beratIkan[][10]);
void dataIkan(int tambakIkan[][10], int totalIkan[], char jenisIkan[][20], float beratIkan[][10]);
void sortBerakIkan(float arr[], int n);

#endif
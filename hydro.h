//hydro.h
//ENCM 339 Lab 8 Exercise C

#include "list.h"

#ifndef HYDRO_H
#define HYDRO_H

void displayHeader();
int readData(FlowList& list);
int menu();
void display(const FlowList& list);
// int addData(FlowList& list, int size);
int removeData(FlowList& list, int size);
// double average(const FlowList& list);
// double median(const FlowList& list);
// void saveData(const FlowList& list);
void pressEnter();

#endif
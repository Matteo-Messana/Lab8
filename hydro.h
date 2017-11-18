//hydro.h
//ENCM 339 Lab 8 Exercise C

#ifndef HYDRO_H
#define HYDRO_H

void displayHeader();
int readData(FlowList& list, ifstream& stream, char* filename);
int menu();
int display(const FlowList& list);
void addData(FlowList& list);
void removeData(FlowList& list);
double average(const FlowList& list);
double median(const FlowList& list);
void saveData(const FlowList& list, ofstream& stream, char* filename);
void pressEnter();
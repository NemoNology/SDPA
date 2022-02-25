#pragma once
#include <exception>
#include <fstream>


using namespace std;



void Record_to_file(fstream &f, int s) {

	f << s;

}


void Record_to_file(fstream &f, string s) {

	f << s;

}


void Record_to_file(fstream &f, float s) {

	f << s;

}


void Record_to_file(fstream &f, double s) {

	f << s;

}


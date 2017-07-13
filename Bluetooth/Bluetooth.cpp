/*
 * File:   Bluetooth.cpp
 * Author: Yuki Mori
 *
 * Created on 2017/07/11
 */
#include "Bluetooth.h"

using namespace BT;
using namespace AITLibrary;

Bluetooth::Bluetooth(void): cn() {
	
}

Bluetooth::Bluetooth(BTConnection cn): cn(cn) {
	
}

Bluetooth::~Bluetooth(void) {
	
}

bool Bluetooth::print(String str) {
	return this->cn.write(str.getCharPointer());
}

String Bluetooth::getString(void) {
	if(!cn.isConnected()) {
		return "";
	}
	char c = cn.read();
	String str = "";
	while(c != '\r') {
		if(c < 0) {
			return "";
		}
		char tmp[2];
		tmp[0] = c;
		tmp[1] = '\0';
		str += tmp;
	}
	return str;
}
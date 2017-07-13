/*
 * File:   BTConnection.cpp
 * Author: Yuki Mori
 *
 * Created on 2017/07/11
 */
#include "BTConnection.h"
#include "ev3api.h"
 
using namespace BT;

FILE* BTConnection::sbt = NULL;

BTConnection::BTConnection(void){
}

BTConnection::BTConnection(BTConnection& orig){
    this->bt = orig.bt;
}

BTConnection::~BTConnection(void){
    fclose(bt);
}

BTConnection BTConnection::connect(){
    if(!ev3_bluetooth_is_connected()){
        sbt = ev3_serial_open_file(EV3_SERIAL_BT);
    }
    BTConnection cn;
    cn.bt = sbt;
    return cn;
}

bool BTConnection::isConnected(void) {
    if(this->bt == NULL) {
        return false;
    }
    return ev3_bluetooth_is_connected();
}

bool BTConnection::write(const char* str) {
    if(!this->isConnected()) {
        return false;
    }
    int result = fprintf(this->bt, "%s\r", str);
    return (result < 0) ? false : true;
}

int BTConnection::read(void) {
    if(!this->isConnected()) {
        return -1;
    }
    return fgetc(this->bt);
}
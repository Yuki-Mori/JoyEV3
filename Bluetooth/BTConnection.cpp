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
/*
 * File:   Bluetooth.h
 * Author: Yuki Mori
 *
 * Created on 2017/07/11
 */
#ifndef __BLUETOOTH
#define __BLUETOOTH
#include "BTConnection.h"
namespace BT {
	class Bluetooth{
	public:
		Bluetooth(void);
		Bluetooth(BTConnection cn);
		~Bluetooth(void);
	private:
		BTConnection cn;
	};
}
#endif /*__BLUETOOTH*/
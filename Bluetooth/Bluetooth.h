/*
 * File:   Bluetooth.h
 * Author: Yuki Mori
 *
 * Created on 2017/07/11
 */
#ifndef __BLUETOOTH
#define __BLUETOOTH
#include "BTConnection.h"
#include "../Library/MyString.h"
using namespace AITLibrary;
namespace BT {
	class Bluetooth{
	public:
		Bluetooth(void);
		Bluetooth(BTConnection cn);
		~Bluetooth(void);
		bool print(String str);
		String getString(void);
	private:
		BTConnection cn;
	};
}
#endif /*__BLUETOOTH*/
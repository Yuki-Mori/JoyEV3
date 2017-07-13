/*
 * File:   BTConnection.h
 * Author: Yuki Mori
 *
 * Created on 2017/07/11
 */
#ifndef __BT_CONNECTIOIN
#define __BT_CONNECTIOIN
#include <stdio.h>
namespace BT {
	class BTConnection {
	public:
		BTConnection(void);
		BTConnection(BTConnection& orig);
		~BTConnection(void);
		bool isConnected(void);
		bool write(char* str);
		int read(void);
		static BTConnection connect(void);
	private:
		static FILE* sbt;
		FILE* bt;
	};
}

#endif /*__BT_CONNECTIOIN*/
/* 
 * File:   MyString.h
 * Author: Yuki Mori
 *
 * Created on 2017/07/07
 */

#ifndef MY_STRING_H
#define MY_STRING_H

#include <stddef.h>

namespace AITLibrary {

    class String {
    public:
        String();
        String(const char* str);
        String(const String& orig);
        virtual ~String();

        //演算子オーバーロード
        String operator+(const char* str);
        String operator+(const String& str);
        String& operator+=(const char* str);
        String& operator+=(const String& str);
        String& operator=(const char* str);
        String& operator=(const String& str);
        bool operator==(const char* str);
        bool operator==(const String& str);

        //メンバ関数
        const char* getCharPointer(void) const;
        int length(void);
        bool isEmpty(void);
        int hashCode(void);
        
        static String valueOf(int val);
        static String valueOf(unsigned int val);
        static String valueOf(long val);
        static String valueOf(unsigned long val);
        static String valueOf(long long val);
        static String valueOf(unsigned long long val);
        static String valueOf(float val);
        static String valueOf(double val);
        static String valueOf(long double val);
    private:
        size_t m_capacity;
        size_t m_size;
        char* m_data;
    };
}
#endif /* MY_STRING_H */


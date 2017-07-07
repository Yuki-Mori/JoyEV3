/* 
 * File:   String.cpp
 * Author: Yuki Mori
 * 
 * Created on 2017/07/07
 */

#include "MyString.h"
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <stdio.h>

using namespace AITLibrary;
String::String() {
    this->m_capacity = 0;
    this->m_size = 0;
    this->m_data = new char[this->m_size + 1];
    this->m_data[0] = '\0';
}

String::String(const char* str){
    this->m_capacity = strlen(str);
    this->m_size = this->m_capacity;
    this->m_data = new char[this->m_size + 1];
    strcpy(this->m_data,str);
}

String::String(const String& orig) {
    this->m_capacity = orig.m_capacity;
    this->m_size = orig.m_size;
    this->m_data = new char[this->m_size + 1];
    strcpy(this->m_data, orig.m_data);
}

String::~String() {
    delete[] this->m_data;
}

String String::operator+(const char* str) {
    String ans(*this);
    ans += str;
    return ans;
}

String String::operator +(const String& str){
    String ans(*this);
    ans += str;
    return ans;
}

String& String::operator+=(const char* str) {
    size_t new_size = this->m_size + strlen(str);
    if(this->m_capacity < new_size){
        while(this->m_capacity < new_size){
            this->m_capacity *= 2;
        }
        char *new_m_data = new char[this->m_capacity + 1];
        memcpy(new_m_data, this->m_data, this->m_size);
        this->m_data = new_m_data;
    }
    strcpy(this->m_data + this->m_size, str);
    this->m_size = new_size;
    return *this;
}

String& String::operator+=(const String& str){
    size_t new_size = this->m_size + str.m_size;
    if(this->m_capacity < new_size){
        while(this->m_capacity < new_size){
            this->m_capacity *= 2;
        }
        char *new_m_data = new char[this->m_capacity + 1];
        memcpy(new_m_data, this->m_data, this->m_size);
        this->m_data = new_m_data;
    }
    strcpy(this->m_data + this->m_size, str.m_data);
    this->m_size = new_size;
    return *this;
}

String& String::operator=(const char* str) {
    this->m_capacity = strlen(str);
    this->m_size = this->m_capacity;
    this->m_data = new char[this->m_size + 1];
    strcpy(this->m_data, str);
    return *this;
}

String& String::operator=(const String& str){
    this->m_capacity = str.m_capacity;
    this->m_size = str.m_size;
    this->m_data = new char[this->m_size + 1];
    strcpy(this->m_data, str.m_data);
    return *this;
}

bool String::operator==(const char* str){
    return (this->m_size == strlen(str))&&(strcmp(this->m_data, str) == 0);
}

bool String::operator==(const String& str) {
    return (this->m_size == str.m_size)&&(strcmp(this->m_data, str.m_data) == 0);
}

/**
 * Char型のポインタを返します。
 * @return Char型のポインタ
 */
const char* String::getCharPointer() const{
    return this->m_data;
}

/**
 * 文字列の長さを返します。
 * @return 文字列の長さ
 */
int String::length() {
    return this->m_size;
}

/**
 * 文字列が存在するかどうかを調べます
 * @return 空 : true, ある : false
 */
bool String::isEmpty() {
    return (this->m_size == 0);
}

/**
 * 文字列のハッシュ値を計算します
 * @return ハッシュ値
 */
int String::hashCode() {
    int ans = 0;
    for(unsigned int i = 0; i < m_size; i++){
        ans += (int)pow((double)(m_data[i]*31),(double)m_size-(i+1));
    }
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(int val) {
    char tmp[128];
    sprintf(tmp,"%d",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(unsigned int val){
    char tmp[128];
    sprintf(tmp,"%u",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(long val){
    char tmp[128];
    sprintf(tmp,"%ld",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(unsigned long val){
    char tmp[128];
    sprintf(tmp,"%lu",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(long long val){
    char tmp[128];
    sprintf(tmp,"%lld",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(unsigned long long val){
    char tmp[128];
    sprintf(tmp,"%llu",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(float val){
    char tmp[128];
    sprintf(tmp,"%f",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(double val){
    char tmp[128];
    sprintf(tmp,"%f",val);
    String ans(tmp);
    return ans;
}

/**
 * 数値を文字列に変換します。
 * @param val
 * @return 変換された文字列
 */
String String::valueOf(long double val){
    char tmp[128];
    sprintf(tmp,"%Lf",val);
    String ans(tmp);
    return ans;
}













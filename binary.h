/*
	Develop by @NoSoK888
	Day: 16.05.2020
	Last update: 29.05.2020
	
	This C-lib you can use for create a bit array 
	and do some stuff like OR,XOR,AND ... operations
	For example:
		you have number like this: 12
		--
		and you want to convert it to binary list
		like this: 1100
		--
		you should to use the int_to_bin function
		For Example:
			int number = 12;
			int bit_array[<count_of_bits>];
			int_to_bin(bin_array, <count_of_bits>, number);
		--
		Also you can use a smart convertation function
		which does not give the bits count
		For example:
			int number = 12421;
			int bit_array[];
			smart_convert(bit_array, number);
*/
#ifndef BINARY_LIB
	#define BINARY_LIB
	
	// Fix the "unknow size_t type" problem
	#include <stddef.h>
	
	#include <fcntl.h>
	
	#define _stdin  0
	#define _stdout 1
	#define _stderr 2
	
	#ifndef ERROR_BIN
		#define ERROR_BIN
		#include "binerror.h"
	#endif
//-----------------------MAIN FUNCTIONS--------------------------------
int int_to_bin		(int* _bit_array, const size_t _bit_size, int _number);
int bin_to_int		(const int* const _bit_array, const size_t _bit_size, int *_number);
int show_binary		(const int* const _bit_array, const size_t _bit_size);
int set_zero_bin	(int* _bit_array, const size_t _bit_size);
int is_all_zero		(const int* const _bit_array, const size_t _bit_size);
int is_all_one		(const int* const _bit_array, const size_t _bit_size);
int copy_bit_array	(int* _dest, const size_t _bit_size, const int* const _src);
int smart_convert	(int** _bit_array, const unsigned int _number);
//---------------------------------------------------------------------

//-----------------------OTHER FUNCTIONS--------------------------------
int  to			 (const int _base, const int _step);
int  chnextbit	 (int* _base, const int _bit_size, const int _bit_index);
//---------------------------------------------------------------------

//-----------------------BINARY OPERATIONS-----------------------------
void XOR (int* _bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right);
void OR  (int* _bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right);
void AND (int* _bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right);
void NOT (int* _bit_array_base, const size_t _bit_size);
void SHR (int* _bit_array_base, const size_t _bit_size);
void SHL (int* _bit_array_base, const size_t _bit_size);
void ADD (int* _bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right);
//void SUB (int* _bit_array_base, const size_t _bit_size, const int* const _bit_array_left, int* _bit_array_right);
//---------------------------------------------------------------------
	
	#ifndef MAIN_BIN
		#define MAIN_BIN
		#include "binf.h"
	#endif
	#ifndef MATH_BIN
		#define MATH_BIN
		#include "binmathf.h"
	#endif
	#ifndef OPER_BIN
		#define OPER_BIN
		#include "binoperf.h"
	#endif
#endif

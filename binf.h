/*
	Explain: Int to binary code
	Example:
		2 -> 0010
	Update: 18.05.2020
*/
int int_to_bin(int *_bit_array, const size_t _bit_size, int _number){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input arguments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	//else if(_number > to(2, (_bit_size-1))){ return _error = BAD_NUMBER_VALUE; }
	
	/*Create a bit weight array Example: 1, 2, 4, 8, 16, 32, 64, 128 - it's a 8-bit value*/
	int _bit_weight_array[_bit_size];
	
	/*Find the bit weight values for current len of array*/
	for(int iter=_bit_size-1; iter>=0; --iter){
		_bit_weight_array[iter] = to(2, iter);
	}
	
	/*Create a bit interpritation of integer value*/
	for(int iter=_bit_size-1; iter>=0; --iter){
		if(_number == _bit_weight_array[iter]){
			_bit_array[(_bit_size-1)-iter] = 1;
			break;
		}
		else if(_number > _bit_weight_array[iter]){
			_bit_array[(_bit_size-1)-iter] = 1;
			_number-=_bit_weight_array[iter];
		}
	}
	return 0;
}
//---------------------------------------


/*
	Explain: Binary to integer
	Example:
		0010 -> 2
	Update: 18.05.2020
*/
int bin_to_int(const int* const _bit_array, const size_t _bit_size, int *_number){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	else if(_number == NULL){ return _error = BAD_INT_POINTER; }
	
	/*Create a bit weight array for current _bit_array and _bit_size*/
	int _bit_weight_array[_bit_size];
	
	/*Create a bit weight array Example: 1, 2, 4, 8, 16, 32, 64, 128 - it's a 8-bit value*/
	for(int weight=_bit_size-1, iter=0; iter<_bit_size && weight>=0; --weight, ++iter){
		_bit_weight_array[iter] = to(2, weight);
	}
	
	/*The next step is how to know what the number is that*/
	/*This is a realization of algorithm of finding value of number from binary*/
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array[iter]){
			(*_number)+=_bit_weight_array[iter];
		}
	}
	
	return 0;
}
//---------------------------------------


/*
	Explain: For fast and correct showing the binary array 
	Example:
		{0, 0, 0, 1}
		-> 0001
	Update : 18.05.2020
*/
int show_binary(const int* const _bit_array, const size_t _bit_size){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	
	for(int iter=0; iter<_bit_size; ++iter){
		printf("%d",_bit_array[iter]);
	}
	
	return 0;
}
//---------------------------------------


/*
	Explain: Sometimes we need to set all elements
			 of binary array to zero it's help us
	Update:  18.05.2020
*/
int set_zero_bin(int *_bit_array, const size_t _bit_size){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	
	for(int iter=0; iter<_bit_size; ++iter){
		_bit_array[iter] = 0;
	}
	
	return 0;
}
//---------------------------------------


/*
	Explain: For checking if all elements of binary array is set to sero
*/
int is_all_zero(const int* const _bit_array, const size_t _bit_size){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array[iter] != 0){ return 0; }
	}
	
	return 1;
}
int is_all_one(const int* const _bit_array, const size_t _bit_size){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_bit_array == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array[iter] != 1){ return 0; }
	}
	
	return 1;
}


/*
	Explain: For fast coping binary to binary
*/
int copy_bit_array(int* _dest, const size_t _bit_size, const int* const _src){
	
	enum __BIN_ERRORS__ _error;
	
	/*Check some kind of wrong input agruments*/
	if(_dest == NULL){ return _error = BAD_POINTER; }
	else if(_src == NULL){ return _error = BAD_POINTER; }
	else if(_bit_size == 0){ return _error = BAD_SIZE; }
	
	for(int iter=0; iter<_bit_size; ++iter){
		_dest[iter] = _src[iter];
	}
}

/*
	Explain: For smart interpret from integer to binary array
	Example:
		int* binary = 0;
		int number = 2;
		smart(&binary, number);
		...
*/  
int smart_convert(int** _bit_array, const unsigned int _number){
	
		enum __BIN_ERRORS__ _error;
	
		/*Check some kind of wrong input agruments*/
		if(*(_bit_array) != NULL){ return _error = BAD_POINTER; }
		else if(_bit_array == NULL){ return _error = BAD_POINTER; }
	
		auto size_t test_array_size = 8;
		if(_number > to(2, 7)){
			do{
				++test_array_size;
			}while(_number > to(2, test_array_size));
		}
		auto int test_array[test_array_size];
		*(_bit_array) = malloc(sizeof(int)*test_array_size);
		
		setzbin(test_array, test_array_size);
		setzbin(*(_bit_array), test_array_size);
		
		inttbin(test_array, test_array_size, _number);	
		copybitarray(*(_bit_array), test_array_size, test_array);
		
		return test_array_size;
}

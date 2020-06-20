void XOR(int *_bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right){
	for(int iter=0; iter<_bit_size; ++iter){
		if((_bit_array_left[iter]  == 1 &&
		   _bit_array_right[iter] == 0) ||
		   (_bit_array_left[iter] == 0 &&
		   _bit_array_right[iter] == 1)){
		   		_bit_array_base[iter] = 1;
		   }
		else
			_bit_array_base[iter] = 0;
	}
}

void OR(int *_bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right){
	for(int iter=0; iter<_bit_size; ++iter){
		if((_bit_array_left[iter]  == 1 ||
		   _bit_array_right[iter] == 1)){
		   		_bit_array_base[iter] = 1;
		   }
		else
			_bit_array_base[iter] = 0;
	}
}

void AND(int *_bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right){
	for(int iter=0; iter<_bit_size; ++iter){
		if((_bit_array_left[iter]  == 1 &&
		   _bit_array_right[iter] == 1)){
		   		_bit_array_base[iter] = 1;
		   }
		else
			_bit_array_base[iter] = 0;
	}
}

void NOT(int *_bit_array_base, const size_t _bit_size){
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array_base[iter]  == 1){
				_bit_array_base[iter] = 0;
		   }
		else
			_bit_array_base[iter] = 1;
	}
}

void SHR(int *_bit_array_base, const size_t _bit_size){
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array_base[iter] == 1){
			if(iter+1 == _bit_size){
				break;
			}else{
				_bit_array_base[iter+1] = _bit_array_base[iter];
			}
			_bit_array_base[iter]   = 0;
		}
	}
}

void SHL(int *_bit_array_base, const size_t _bit_size){
	for(int iter=0; iter<_bit_size; ++iter){
		if(_bit_array_base[iter] == 1){
			if(iter-1 <= 0){
				break;
			}else{
				_bit_array_base[iter-1] = _bit_array_base[iter];
			}
			_bit_array_base[iter]   = 0;
		}
	}
}

void ADD(int *_bit_array_base, const size_t _bit_size, const int* const _bit_array_left, const int* const _bit_array_right){
	
	int _left[_bit_size];
	copybitarray(_left, _bit_size, _bit_array_left);
	
	int _right[_bit_size];
	copybitarray(_right, _bit_size, _bit_array_right);
	
	int iter = _bit_size-1;
	while(isallzero(_right, _bit_size) <= 0){
		if((_left[iter] == 0 && _right[iter] == 1)
			|| (_left[iter] == 1 && _right[iter] == 0)){
			_left[iter] 		  = 1;
			_right[iter] 		  = 0;
		}else if(_left[iter] == 1 && _right[iter] == 1){
			chnextbit(_left, _bit_size, iter);
			_right[iter] 		  = 0;
		}
		--iter;
		if(iter <= 0){ iter = _bit_size-1; }
	}
	
	copybitarray(_bit_array_base, _bit_size, _left);
}

void SUB(int *_bit_array_base, const size_t _bit_size, const int* const _bit_array_left, int* _bit_array_right){
	auto int one[_bit_size];
	setzbin(one, _bit_size);
	inttbin(one, _bit_size, 1);
	
	NOT(_bit_array_right, _bit_size);
	ADD(_bit_array_right, _bit_size, _bit_array_right, one);
	
	ADD(_bit_array_base, _bit_size, _bit_array_left, _bit_array_right);
}


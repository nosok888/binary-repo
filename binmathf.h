int to(const int base, const int step){
	auto int current = base;
	
	if(step <= 0)
		return 1;
	else{
		for(int result=1; result<step; ++result){ current*=base; }
	}
	
	return current;
}

int chnextbit(int* _base, const int _bit_size, const int _bit_index){
	
	if(_bit_index == 0 && _base[_bit_index] == 1){
		_base[_bit_index] = 0;
	}
	else if(_base[_bit_index-1] == 1){
		_base[_bit_index] = 0;
		chnextbit(_base, _bit_size, _bit_index-1);
	}
	else if(_base[_bit_index-1] == 0)
		{ _base[_bit_index] = 0; _base[_bit_index-1] = 1; }
		
	return 1; 
}

#include "stdafx.h"
#include "Hash.h"

void ByteHash::hash_it(const char * text, int size) {
	unsigned int res = 0;
	unsigned int cur_degree = 1;
	for (size_t i = 0; i < size; i++) {
		res += cur_degree * text[i] % MOD;
		res %= MOD;
		cur_degree *= DEGREE;
		cur_degree %= MOD;
	}
	this->value = res;
}

#pragma once

#define DEGREE 131
#define MOD ((unsigned int)1e9)

class ByteHash{
public:
	void hash_it(const char *, int);

	void setValue(unsigned int value) {
		this->value = value;
	}

	unsigned int getValue() {
		return value;
	}

private:
	unsigned int value;
};

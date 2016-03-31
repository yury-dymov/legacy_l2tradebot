#ifndef BF_H
#define BF_H

#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <iostream>

#include "../../data.h"

class Blowfish
{
	private:
		unsigned long * P_;
		unsigned long ** S_;		
		void swap_ (b32 *w1, b32 *w2);
		unsigned long F_ (b32 *x) ;		
		void encrypt_ (b32 *w1, b32 *w2);
		void decrypt_ (b32 *w1, b32 *w2);
		void encryptBlock_ (unsigned char *b64);
		void decryptBlock_ (unsigned char *b64);
		int init_;
		std::string key_;
	public:
		Blowfish();
		~Blowfish();
		std::string checksum (const std::string & pck);
		int init (const std::string & key);
		std::string encrypt (const std::string & str);
		std::string decrypt (const std::string & str);
		std::string hex2str (const std::string & str);
		std::string key () const;
};

#endif // BF_H

//#ifndef CRYPTOPP_DLL_ONLY
//# define CRYPTOPP_DEFAULT_NO_DLL
//#endif

#include "dll.h"
#include "cryptlib.h"
#include "filters.h"
#include <iostream>
#include <sstream>
#include <iomanip>

USING_NAMESPACE(CryptoPP)
USING_NAMESPACE(std)
void  SmokeTestWithSha256()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte digest[32];

	cout << "Start" << endl;

	SHA256 sha;
	//sha.Update(message, 3);
	sha.Update(message,0);
	sha.Final(digest);

//	typedef std::vector<unsigned char> bytes;
//	const bytes in = digest;

//	bytes::const_iterator from = in.cbegin();
//	bytes::const_iterator to = in.cend();
	std::ostringstream oss;
	byte* from = (byte*) &digest;
	byte* to = ((byte*) &digest) + sizeof(digest);
	int i = 0;
	for (; from != to; ++from) {
		oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*from);
//		oss << std::hex << std::setw(2) << std::setfill('0') << *from;

		i++;
	}
//	return oss.str();
	cout << oss.str() << endl;
	cout << i << endl;

	cout << "End" << endl;

}

void  SmokeTestStats()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte digest[32];

	cout << "Start" << endl;

	SHA256 sha;
	unsigned int even=0, odd=0;
	for(unsigned int i=0; i<1000000; i++) {
		//sha.Update(message, 3);
		sha.Restart();
		sha.Update((byte*)&i, sizeof(i));
		sha.Final(digest);

		//std::ostringstream oss;
		//byte* from = (byte*) &digest;
		byte* end = ((byte*) &digest) + sizeof(digest) - 1;
		if(*end & 2)
			odd++;
		else
			even++;

	}
//	return oss.str();
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;

	cout << "End" << endl;

}

void  SmokeTestStatsT()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte digest[32];

	cout << "Start" << endl;

	SHA256T sha;
	unsigned int even=0, odd=0;
	for(unsigned int i=0; i<1000000; i++) {
		//sha.Update(message, 3);
		sha.Restart();
		sha.Update((byte*)&i, sizeof(i));
		sha.Final(digest);

		//std::ostringstream oss;
		//byte* from = (byte*) &digest;
		byte* end = ((byte*) &digest) + sizeof(digest) - 1;
		if(*end & 2)
			odd++;
		else
			even++;

	}
//	return oss.str();
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;

	cout << "End" << endl;

}



void  SmokeTestStats2()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte tmpdigest[32];
	byte digest[32];


	cout << "Start" << endl;

	SHA256 sha;
	unsigned int even=0, odd=0;
	for(unsigned int i=0; i<1000000; i++) {
		//sha.Update(message, 3);
		sha.Restart();
		sha.Update((byte*)&i, sizeof(i));
		sha.Final(tmpdigest);

		sha.Restart();
		sha.Update((byte*)tmpdigest, sizeof(tmpdigest));
		sha.Final(digest);

		//std::ostringstream oss;
		//byte* from = (byte*) &digest;
		byte* end = ((byte*) &digest) + sizeof(digest) - 1;
		if(*end & 2)
			odd++;
		else
			even++;

	}
//	return oss.str();
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;

	cout << "End" << endl;

}

void  SmokeTestStats2Three()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte tmpdigest[32];
	byte tmpdigest2[32];
	byte digest[32];


	cout << "Start" << endl;

	SHA256 sha;
	unsigned int even=0, odd=0;
	for(unsigned int i=0; i<1000000; i++) {
		//sha.Update(message, 3);
		sha.Restart();
		sha.Update((byte*)&i, sizeof(i));
		sha.Final(tmpdigest);

		sha.Restart();
		sha.Update((byte*)&tmpdigest, sizeof(tmpdigest));
		sha.Final(tmpdigest2);



		sha.Restart();
		sha.Update((byte*)tmpdigest2, sizeof(tmpdigest2));
		sha.Final(digest);

		//std::ostringstream oss;
		//byte* from = (byte*) &digest;
		byte* end = ((byte*) &digest) + sizeof(digest) - 1;
		if(*end & 2)
			odd++;
		else
			even++;

	}
//	return oss.str();
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;

	cout << "End" << endl;

}



void  SmokeTestStats3()
{
	const byte message[] = {'a', 'b', 'c'};
	const byte expectedDigest[] = {0xA9,0x99,0x3E,0x36,0x47,0x06,0x81,0x6A,0xBA,0x3E,0x25,0x71,0x78,0x50,0xC2,0x6C,0x9C,0xD0,0xD8,0x9D};
	byte tmpdigest[32];
	byte digest[32];


	cout << "Start" << endl;

	SHA256T shat;
	SHA256 sha;
	unsigned int even=0, odd=0;
	for(unsigned int i=0; i<1000000; i++) {
		//sha.Update(message, 3);
		shat.Restart();
		shat.Update((byte*)&i, sizeof(i));
		shat.Final(tmpdigest);

		sha.Restart();
		sha.Update((byte*)tmpdigest, sizeof(tmpdigest));
		sha.Final(digest);

		//std::ostringstream oss;
		//byte* from = (byte*) &digest;
		byte* end = ((byte*) &digest) + sizeof(digest) - 1;
		if(*end & 2)
			odd++;
		else
			even++;

	}
//	return oss.str();
	cout << "Even: " << even << endl;
	cout << "Odd: " << odd << endl;

	cout << "End" << endl;

}







//#ifdef CRYPTOPP_DLL_ONLY

//int __cdecl main()
int main()
{
	//SmokeTestWithSha1();
	//SmokeTestWithSha256();
	SmokeTestStats();
	SmokeTestStatsT();
	SmokeTestStats2();
	SmokeTestStats2Three();
	SmokeTestStats3();


	unsigned int x = 0xabcdef01;
	cout << hex << x << endl;
	cout << hex << ~x << endl;

	return 0;
}

//#endif

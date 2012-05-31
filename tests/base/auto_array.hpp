
// Copyright (c) 2010-2012 niXman (i dot nixman dog gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef _yas_test__auto_array_hpp__included_
#define _yas_test__auto_array_hpp__included_

template<typename OA, typename IA>
bool auto_array_test() {
	static const size_t array_size = 6;

	char ca1[] = {"string"}, ca2[array_size+1] = {0};
	unsigned char uca1[] = {0x73,0x74,0x72,0x69,0x6e,0x67,0x00}, uca2[array_size+1] = {0};
	short sa1[array_size] = {1,2,3,4,5,6}, sa2[array_size];
	unsigned short usa1[array_size] = {1,2,3,4,5,6}, usa2[array_size];
	int ia1[array_size] = {1,2,3,4,5,6}, ia2[array_size];
	unsigned int uia1[array_size] = {1,2,3,4,5,6}, uia2[array_size];
	long la1[array_size] = {1,2,3,4,5,6}, la2[array_size];
	unsigned long ula1[array_size] = {1,2,3,4,5,6}, ula2[array_size];
	long long lla1[array_size] = {1,2,3,4,5,6}, lla2[array_size];
	unsigned long long ulla1[array_size] = {1,2,3,4,5,6}, ulla2[array_size];
	long double lda1[array_size] = {1,2,3,4,5,6}, lda2[array_size];
	double da1[array_size] = {1,2,3,4,5,6}, da2[array_size];
	float fa1[array_size] = {1,2,3,4,5,6}, fa2[array_size];

	{  OA oa;
		oa & ca1;
		IA ia(oa.get_intrusive_buffer());
		ia & ca2;
		if ( memcmp(ca1, ca2, array_size*sizeof(ca1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [1]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & uca1;
		IA ia(oa.get_intrusive_buffer());
		ia & uca2;
		if ( memcmp(uca1, uca2, array_size*sizeof(uca1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [2]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & sa1;
		IA ia(oa.get_intrusive_buffer());
		ia & sa2;
		if ( memcmp(sa1, sa2, array_size*sizeof(sa1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [3]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & usa1;
		IA ia(oa.get_intrusive_buffer());
		ia & usa2;
		if ( memcmp(usa1, usa2, array_size*sizeof(usa1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [4]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & ia1;
		IA ia(oa.get_intrusive_buffer());
		ia & ia2;
		if ( memcmp(ia1, ia2, array_size*sizeof(ia1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [5]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & uia1;
		IA ia(oa.get_intrusive_buffer());
		ia & uia2;
		if ( memcmp(uia1, uia2, array_size*sizeof(uia1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [6]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & la1;
		IA ia(oa.get_intrusive_buffer());
		ia & la2;
		if ( memcmp(la1, la2, array_size*sizeof(la1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [7]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & ula1;
		IA ia(oa.get_intrusive_buffer());
		ia & ula2;
		if ( memcmp(ula1, ula2, array_size*sizeof(ula1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [8]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & lla1;
		IA ia(oa.get_intrusive_buffer());
		ia & lla2;
		if ( memcmp(lla1, lla2, array_size*sizeof(lla1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [9]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & ulla1;
		IA ia(oa.get_intrusive_buffer());
		ia & ulla2;
		if ( memcmp(ulla1, ulla2, array_size*sizeof(ulla1[0])) ) {
			std::cout << "AUTO_ARRAY deserialization error! [10]" << std::endl;
			return false;
		}
	}
	{  OA oa;
		oa & lda1;
		IA ia(oa.get_intrusive_buffer());
		ia & lda2;
		if ( yas::is_binary_archive<OA>::value ) {
			if ( memcmp(lda1, lda2, array_size*sizeof(lda1[0])) ) {
				std::cout << "AUTO_ARRAY deserialization error! [11]" << std::endl;
				return false;
			}
		} else {
			if ( !std::equal(lda1, lda1+array_size, lda2) ) {
				std::cout << "AUTO_ARRAY deserialization error! [11]" << std::endl;
				return false;
			}
		}
	}
	{  OA oa;
		oa & da1;
		IA ia(oa.get_intrusive_buffer());
		ia & da2;
		if ( yas::is_binary_archive<OA>::value ) {
			if ( memcmp(da1, da2, array_size*sizeof(da1[0])) ) {
				std::cout << "AUTO_ARRAY deserialization error! [12]" << std::endl;
				return false;
			}
		} else {
			if ( !std::equal(da1, da1+array_size, da2) ) {
				std::cout << "AUTO_ARRAY deserialization error! [12]" << std::endl;
				return false;
			}
		}
	}
	{  OA oa;
		oa & fa1;
		IA ia(oa.get_intrusive_buffer());
		ia & fa2;
		if ( yas::is_binary_archive<OA>::value ) {
			if ( memcmp(fa1, fa2, array_size*sizeof(fa1[0])) ) {
				std::cout << "AUTO_ARRAY deserialization error! [13]" << std::endl;
				return false;
			}
		} else {
			if ( !std::equal(fa1, fa1+array_size, fa2) ) {
				std::cout << "AUTO_ARRAY deserialization error! [13]" << std::endl;
				return false;
			}
		}
	}

	return true;
}

#endif // _yas_test__auto_array_hpp__included_
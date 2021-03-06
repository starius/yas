
// Copyright (c) 2010-2013 niXman (i dot nixman dog gmail dot com)
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

#ifndef _yas__text_mem_stream_hpp
#define _yas__text_mem_stream_hpp

#include <memory>

#include <yas/detail/io/binary_mem_stream.hpp>

namespace yas {
namespace detail {

/***************************************************************************/

template<archive_type::type>
struct omemstream;

template<>
struct omemstream<archive_type::text>: omemstream<archive_type::binary> {
	omemstream()
		:omemstream<archive_type::binary>()
		,_stream(new std::ostream(this))
	{}

	omemstream(size_t size)
		:omemstream<archive_type::binary>(size)
		,_stream(new std::ostream(this))
	{}

	omemstream(char* ptr, size_t size)
		:omemstream<archive_type::binary>(ptr, size)
		,_stream(new std::ostream(this))
	{}

	template<typename T>
	std::ostream& operator<< (const T& v) {
		return ((*_stream) << v);
	}

private:
	std::auto_ptr<std::ostream> _stream;
};

/***************************************************************************/

template<archive_type::type>
struct imemstream;

template<>
struct imemstream<archive_type::text>: imemstream<archive_type::binary> {
	imemstream(const char* ptr, size_t size)
		:imemstream<archive_type::binary>(ptr, size)
		,_stream(new std::istream(this))
	{}
	imemstream(const intrusive_buffer& buf)
		:imemstream<archive_type::binary>(buf)
		,_stream(new std::istream(this))
	{}

	imemstream(const shared_buffer& buf)
		:imemstream<archive_type::binary>(buf)
		,_stream(new std::istream(this))
	{}

	void get() { _stream->get(); }

	template<typename T>
	std::istream& operator>> (T& v) {
		return ((*_stream) >> v);
	}

private:
	std::auto_ptr<std::istream> _stream;
};

/***************************************************************************/

} // ns detail
} // ns yas

#endif // _yas__text_mem_stream_hpp

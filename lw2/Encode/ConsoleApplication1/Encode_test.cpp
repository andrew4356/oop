
#include "stdafx.h"
#include "../Encode/unitForEncode.h"

BOOST_AUTO_TEST_SUITE(HtmlEncode_function)

BOOST_AUTO_TEST_CASE(check_the_symbol_apos)
{
	const string expectedResult = "&apos;";
	string symbol = "\'";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}

BOOST_AUTO_TEST_CASE(check_the_symbol_amp)
{
	const string expectedResult = "&amp;";
	string symbol = "&";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}

BOOST_AUTO_TEST_CASE(check_the_symbol_quot)
{
	const string expectedResult = "&quot;";
	string symbol = "\"";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}

BOOST_AUTO_TEST_CASE(check_the_symbol_lt)
{
	const string expectedResult = "&lt;";
	string symbol = "<";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}

BOOST_AUTO_TEST_CASE(check_the_symbol_gt)
{
	const string expectedResult = "&gt;";
	string symbol = ">";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}

BOOST_AUTO_TEST_CASE(check_the_symbol_char)
{ 
	const string expectedResult = "a b c abc ab bc";
	string symbol = "a b c abc ab bc";
	string encode = HtmlEncode(symbol);
	BOOST_CHECK(encode == expectedResult);
}



BOOST_AUTO_TEST_SUITE_END()

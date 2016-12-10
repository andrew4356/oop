
#include "stdafx.h"
#include "../Encode/unitForEncode.h"

BOOST_AUTO_TEST_SUITE(HtmlEncode_function)

	BOOST_AUTO_TEST_CASE(replacement_the_symbol_apostrophe)
	{
		const string expectedResult = "&apos;";
		string symbol = "\'";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(replaces_the_symbol_ampersand)
	{
		const string expectedResult = "&amp;";
		string symbol = "&";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(replacement_the_symbol_quote)
	{
		const string expectedResult = "&quot;";
		string symbol = "\"";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(replacement_the_symbol_less_than)
	{
		const string expectedResult = "&lt;";
		string symbol = "<";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(replacement_the_symbol_greater_than)
	{
		const string expectedResult = "&gt;";
		string symbol = ">";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}

	BOOST_AUTO_TEST_CASE(replacement_the_symbol_char)
	{ 
		const string expectedResult = "a b c abc ab bc";
		string symbol = "a b c abc ab bc";
		string encode = HtmlEncode(symbol);
		BOOST_CHECK(encode == expectedResult);
	}



BOOST_AUTO_TEST_SUITE_END()

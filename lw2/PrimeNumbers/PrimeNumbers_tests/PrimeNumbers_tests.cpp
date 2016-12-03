// PrimeNumbers_tests.cpp : Defines the entry point for the console application.
//
//
#include "stdafx.h"

#include "../PrimeNumbers/UnitForPrimeNumbers.cpp"

BOOST_AUTO_TEST_SUITE(Test)

BOOST_AUTO_TEST_CASE(primes_count)
{
	{
		const auto expectedResult = true;
		char * ch[2];
		ch[1] = "0";
		auto test = CheckOnTheCorrectnessOfTheArguments(2, ch[1]);
		BOOST_CHECK(test == expectedResult);
	}

	{
		const auto expectedResult = false;
		char * ch[2];
		ch[1] = "1";
		auto test = CheckOnTheCorrectnessOfTheArguments(2, ch[1]);
		BOOST_CHECK(test == expectedResult);
	}
	
	{
		const auto expectedResult = 0;
		auto primes = GeneratePrimeNumbersSet(1);
		BOOST_CHECK(primes.size() == expectedResult);
	}

	{
		const auto expectedResult = 1;
		auto primes = GeneratePrimeNumbersSet(2);
		BOOST_CHECK(primes.size() == expectedResult);
	}

	{
		const auto expectedResult = 2;
		auto primes = GeneratePrimeNumbersSet(3);
		BOOST_CHECK(primes.size() == expectedResult);
	}

	{
		const auto expectedResult = 4;
		auto primes = GeneratePrimeNumbersSet(10);
		BOOST_CHECK(primes.size() == expectedResult);
	}

	{
		const auto expectedResult = 25;
		auto primes = GeneratePrimeNumbersSet(100);
		BOOST_CHECK(primes.size() == expectedResult);
	}

#ifdef NDEBUG
	{
		const auto expectedResult = 5'761'455;
		auto primes = GeneratePrimeNumbersSet(100'000'000);
		BOOST_CHECK(primes.size() == expectedResult);
	}
#endif
}

BOOST_AUTO_TEST_CASE(compare_sets)
{
	{
		const std::set<uint32_t> expectedResult = {
			2, 3, 5, 7
		};
		const auto primes = GeneratePrimeNumbersSet(10);
		BOOST_CHECK(primes == expectedResult);
	}

	{
		const std::set<uint32_t> expectedResult = {
			2, 3, 5, 7, 11
		};
		const auto primes = GeneratePrimeNumbersSet(12);
		BOOST_CHECK(primes == expectedResult);
	}

	{
		const std::set<uint32_t> expectedResult = { 2 };
		const auto primes = GeneratePrimeNumbersSet(2);
		BOOST_CHECK(primes == expectedResult);
	}

	{
		const std::set<uint32_t> expectedResult = {};
		const auto primes = GeneratePrimeNumbersSet(1);
		BOOST_CHECK(primes == expectedResult);
	}
}

BOOST_AUTO_TEST_SUITE_END()









































//#include "stdafx.h"
//#include <boost/test/output/compiler_log_formatter.hpp>
//#include <boost/algorithm/string/replace.hpp>
//
///*
//������ ����� ��������� ��������������� ������� ������� ������
//��� ����, ����� ������� ���������, ���������� ������ ���� �������� � ������ --log-level=test_suite (��. Post-build event � ���������� �������)
//*/
//class SpecLogFormatter :
//	public boost::unit_test::output::compiler_log_formatter
//{
//	virtual void test_unit_start(std::ostream &os, boost::unit_test::test_unit const& tu) override
//	{
//		// ����� �������� test unit-� ������� ��� test unit-�, ������� ������ ������������� �� ������
//		os << std::string(m_indent, ' ') << boost::replace_all_copy(tu.p_name.get(), "_", " ") << std::endl;
//		// ����������� ������ ��� ������ ���� ����������� test unit-�� � ���� ������
//		m_indent += 2;
//	}
//
//	virtual void test_unit_finish(std::ostream &/*os*/, boost::unit_test::test_unit const& /*tu*/, unsigned long /*elapsed*/) override
//	{
//		// �� ��������� test unit-� ��������� ������
//		m_indent -= 2;
//	}
//
//	int m_indent = 0;
//};
//
//
//boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
//{
//	// �������� ��� log formatter �� ����������������
//	boost::unit_test::unit_test_log.set_formatter(new SpecLogFormatter);
//	// ��� ��������� ������ ������ - All tests
//	boost::unit_test::framework::master_test_suite().p_name.value = "All tests";
//	return 0;
//}
//
//
//
//
//
//
//int main(int argc, char* argv[])
//{
//	// ��������� �����, ��������� ��������� ��������� ������ � ��������� ������� ������������� ������
//	return boost::unit_test::unit_test_main(&init_unit_test_suite, argc, argv);
//}

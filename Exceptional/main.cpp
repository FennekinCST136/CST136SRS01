﻿// Exceptional.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "RangeInt.h"
#include <cassert>

int main()
{
	auto errors{ 0 };
	auto good_tests{ 0 };
	auto test_cases{ 0 };
	auto unaccounted_errors{ 0 };

	try
	{
		
		++test_cases;
		RangeInt test(0, 4);
		test.set_value(10); //error
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}

	try
	{
	
		++test_cases;
		RangeInt test(5, 10);
		test.set_value(1); //error
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}
	try
	{
		//good
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10);
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}
	try
	{
		//good
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10.0);
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}
	try
	{
		//good
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10L);
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}
	try
	{
		//good
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10.f); 
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}
	try
	{
		
		++test_cases;
		RangeInt test(0, 15);
		test.set_value("garbage"); //error
		++good_tests;
	}
	catch (std::invalid_argument &e)
	{
		++errors;
	}

	try
	{
		
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10L);
		test.set_upper(7); //error
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}

	try
	{
		//good
		++test_cases;
		RangeInt test(0, 15);
		test.set_value(10L);
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		++errors;
	}

	try
	{
		//error
		++test_cases;
		RangeInt test(0, 15);
		test.set_value("garbage");
		++good_tests;
	}
	catch (std::out_of_range &e)
	{
		//wont hit error because looking for wrong error type
		++errors;
	}
	catch (...)
	{
		//catches errors I didnt account for
		++unaccounted_errors;
	}
	assert(test_cases == errors + good_tests);
	return errors;
}


/**
	@file
    @brief Модуль тестирования
	@author SavaLione
	@date 23 Jun 2018
*/
/**
	@defgroup testcpp Test.cpp
	@ingroup test
	@{
*/
#include <iostream>

#include <gtest/gtest.h>

#include <Core.h>

TEST(yenot_test, correct_connection_testing_module) {
	EXPECT_EQ(NULL, NULL);
    EXPECT_EQ(1, 1);
	EXPECT_EQ("Yenot", "Yenot");
}
/** @} */
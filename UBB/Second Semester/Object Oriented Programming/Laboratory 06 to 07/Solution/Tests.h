#pragma once
#include "Service.h"
#include "Validator.h"

/*
Run all tests
*/
void run_all_tests();

/*
Tests the functions in domain
*/
void test_domain();

/*
Tests the functions in repository
*/
void test_repository();

/*
Tests the functions in service
*/
void test_service();

/*
Tests the validator
*/
void test_validator();

/*
Tests the list
*/
void test_list();
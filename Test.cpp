/**
 *
 * AUTHOR: Nadav Moyal
 * 
 * 
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	// CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
	// 												 "@-------@\n"
	// 												 "@-@@@@@-@\n"
	// 												 "@-@---@-@\n"
	// 												 "@-@@@@@-@\n"
	// 												 "@-------@\n"
	// 												 "@@@@@@@@@"));
                                                     
    CHECK(nospaces(mat(7, 5, 'x', '0')) == nospaces ("xxxxxxx\n"
													 "x00000x\n"
													 "x0xxx0x\n"
													 "x00000x\n"
													 "xxxxxxx\n"));
    CHECK(nospaces(mat(1, 1, '$', '0')) == nospaces ("$\n"));
}
TEST_CASE("zero or negative input to 'col' or 'row'") {
    int i= 0;
    while(i>-10){
    CHECK_THROWS(mat(i, 5, '$', '%'));
    CHECK_THROWS(mat(3, i, '!', '$'));
    CHECK_THROWS(mat(i, 9, '*', '@'));
    CHECK_THROWS(mat(i+10, 0, '*', 't'));
    CHECK_THROWS(mat(0, i+10, '*', 't'));
    i=i-1;
    }
    }

TEST_CASE("even input to 'col' or 'row'") {
    int i=2;
    while(i<20){
    CHECK_THROWS(mat(i, 5, '$', '%'));
    CHECK_THROWS(mat(3, i, '!', '$'));
    CHECK_THROWS(mat(i, 9, '*', '@'));
    CHECK_THROWS(mat(i+10, 0, '*', 't'));
    CHECK_THROWS(mat(0, i+20, '*', 't'));
    i=i+2;
    }
    }	
TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(5, 8, '(', '@'));
    CHECK_THROWS(mat(10, 4, '$', '!'));

}
TEST_CASE("Unsupported char - not in the ascii table") {
    int a = 3; //legal value of col / row
    int b = 5; //legal value of col / row
    char c = 126;// this is the last char in ascii 
    char d = 32; // this is the first char in ascii 
    c=c+1;   // Unsupported char - not in the ascii table
    d=d+1;   // Unsupported char - not in the ascii table
    while(b<20){
        CHECK_THROWS(mat(a, b, c,d));  
        a=a+4;
        b=b+4;
        c=c+1;
        d=d-1;
    }   
 }						

#include "ctest/ctest.h"
#include "checkfite.h"
#include "checkmove.h"
#include "printF.h"
#include "sp.h"

CTEST(P_Move, Correct) {
    int result = board_func("b2b3", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(P_Move, Incorrect) {
    int result = board_func("b2c3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(R_Move, Correct) {
    int result = board_func("a1a5", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(R_Move, Incorrect) {
    int result = board_func("a1c3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(N_Move, Correct) {
    int result = board_func("b1c3", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(N_Move, Incorrect) {
    int result = board_func("b1b3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(B_Move, Correct) {
    int result = board_func("c1d3", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(B_Move, Incorrect) {
    int result = board_func("c1d3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(Q_Move, Correct) {
    int result = board_func("d1d5", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

CTEST(Q_Move, Incorrect) {
    int result = board_func("d1c3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(K_Move, Incorrect) {
    int result = board_func("d1c3", 1);
    int expected = 1;
    ASSERT_EQUAL(expected,result);
}

CTEST(K_Move, correct) {
    int result = board_func("d1-d2", 1);
    int expected = 0;
    ASSERT_EQUAL(expected,result);
}

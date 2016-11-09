/*
 * Entry point for tests. Tests use libcheck.
 * https://libcheck.github.io/check/doc/check_html/check_3.html
 *
 * If you want to debug the exe, you should define env var CK_FORK=no
 * http://check.sourceforge.net/doc/check_html/check_4.html#No-Fork-Mode
 *
 *  Copyright (C) 2016 Systerel and others.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdlib.h>
#include <check.h>
#include "check_stack.h"


START_TEST(test_empty)
{
    ;
}
END_TEST


Suite *tests_make_suite_stack(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack");
    tc_core = tcase_create("Dummy");
    tcase_add_test(tc_core, test_empty);
    suite_add_tcase(s, tc_core);

    return s;
}


int main(void)
{
    int number_failed;
    SRunner *sr;

    sr = srunner_create(tests_make_suite_stack());
    srunner_add_suite(sr, tests_make_suite_crypto_B256S256());
    srunner_add_suite(sr, tests_make_suite_tools());
    srunner_add_suite(sr, tests_make_suite_core_tools());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

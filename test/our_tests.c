#include <stdio.h>
#include <pico/stdlib.h>
#include <stdint.h>
#include <unity.h>
#include "unity_config.h"

void setUp(void) {}

void tearDown(void) {}

void test_invert_case()
{
    TEST_ASSERT_EQUAL_CHAR('A', invert_case('a'));  
    TEST_ASSERT_EQUAL_CHAR('a', invert_case('A'));
    TEST_ASSERT_EQUAL_CHAR('Z', invert_case('z'));
    TEST_ASSERT_EQUAL_CHAR('z', invert_case('Z'));
    TEST_ASSERT_EQUAL_CHAR('1', invert_case('1'));
    TEST_ASSERT_EQUAL_CHAR(' ', invert_case(' '));
    TEST_ASSERT_EQUAL_CHAR('.', invert_case('.'));
    TEST_ASSERT_EQUAL_CHAR('\n', invert_case('\n'));
    TEST_ASSERT_EQUAL_CHAR(' ', invert_case(' '));
    TEST_ASSERT_EQUAL_CHAR('A' - 1, invert_case('A' - 1));
    TEST_ASSERT_EQUAL_CHAR('Z' + 1, invert_case('Z' + 1));
    TEST_ASSERT_EQUAL_CHAR('a' - 1, invert_case('a' - 1));
    TEST_ASSERT_EQUAL_CHAR('z' + 1, invert_case('z' + 1));
}

void test_update_blink()
{
    int count = 0;
    bool on = false;

    for (int i = 0; i < 100; i++) {
        
        int current_count = count;
        bool next_on = check_update_LED(on, &count);

        TEST_ASSERT_EQUAL_MESSAGE(count, current_count + 1, "Count should always increase by 1");
        TEST_ASSERT_NOT_EQUAL_MESSAGE(on, next_on, "LED should always toggle");
        if ((i + 1) % 11) {
            TEST_ASSERT_NOT_EQUAL_MESSAGE(on, next_on, "LED should toggle");
        } else {
            TEST_ASSERT_EQUAL_MESSAGE(on, next_on, "LED should not toggle");
        }
        on = next_on;
    }   
}

int main (void)
{
    stdio_init_all();
    sleep_ms(5000); // Give time for TTY to attach.
    printf("Start tests\n");
    UNITY_BEGIN();
    RUN_TEST(test_invert_case);
    RUN_TEST(test_update_blink);
    sleep_ms(5000);
    return UNITY_END();
}

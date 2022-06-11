#include <unity.h>
#include "minmea.h"


void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}


void testGpsParseValidation() {

    constexpr auto invalid_sentence = "$jdjdjjdl";
    constexpr auto valid_sentence = "$GPRMC,081836,A,3751.65,S,14507.36,E,000.0,360.0,130998,011.3,E*62";

    TEST_ASSERT_FALSE(minmea_check(invalid_sentence,true));
    TEST_ASSERT_TRUE(minmea_check(valid_sentence,true)); 
}

void testGpsValueExtraction() {

}

int main() {
    UNITY_BEGIN();
    RUN_TEST(testGpsParseValidation);
    UNITY_END();
}
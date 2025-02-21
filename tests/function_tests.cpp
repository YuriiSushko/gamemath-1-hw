#include "gtest/gtest.h"
#include "../src/float_functions.h"
#include <cmath>
#include <cstdlib>

// Normal case
float original = 3.14f;
double originalD = 2.718;
// Normal neg case
float original_neg = -3.14f;
double original_negD = -2.718;
// Zero
float zero = 0.f;
double zeroD = 0.f;
// Negative Zero
float neg_zero = -0.f;
double neg_zeroD = -0.f;
// Positive Infinity
float pos_inf = 3.f/0.f;
double pos_infD = 3.f/0.f;
// Negative Infinity
float neg_inf = -3.f/0.f;
double neg_infD = -3.f/0.f;
// NaN (Not-a-Number)
float nan_value = 0.f/0.f;
double nan_valueD = 0.f/0.f;
// Subnormal value (very small number)
float subnormal = 1.0e-45f;
double subnormalD = 1.0e-45f;

// Test for single-precision (float)
TEST(FiniteFunctionTest, FloatCheck) {
    EXPECT_EQ(is_finite(original), true);
    EXPECT_EQ(is_finite(zero), true);
    EXPECT_EQ(is_finite(neg_zero), true);
    EXPECT_EQ(is_finite(pos_inf), false);
    EXPECT_EQ(is_finite(neg_inf), false);
    EXPECT_EQ(is_finite(nan_value), true);
    EXPECT_EQ(is_finite(subnormal), true);
}

// Test for double-precision (float)
TEST(FiniteFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_finite(originalD), true);
    EXPECT_EQ(is_finite(zeroD), true);
    EXPECT_EQ(is_finite(neg_zeroD), true);
    EXPECT_EQ(is_finite(pos_infD), false);
    EXPECT_EQ(is_finite(neg_infD), false);
    EXPECT_EQ(is_finite(nan_valueD), true);
    EXPECT_EQ(is_finite(subnormalD), true);
}

// Test for single-precision (float)
TEST(PosIinfinityFunctionTest, FloatCheck) {
    EXPECT_EQ(is_positive_inf(original), false);
    EXPECT_EQ(is_positive_inf(zero), false);
    EXPECT_EQ(is_positive_inf(neg_zero), false);
    EXPECT_EQ(is_positive_inf(pos_inf), true);
    EXPECT_EQ(is_positive_inf(neg_inf), false);
    EXPECT_EQ(is_positive_inf(nan_value), false);
    EXPECT_EQ(is_positive_inf(subnormal), false);
}

// Test for double-precision(float)
TEST(PosIinfinityFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_positive_inf(originalD), false);
    EXPECT_EQ(is_positive_inf(zeroD), false);
    EXPECT_EQ(is_positive_inf(neg_zeroD), false);
    EXPECT_EQ(is_positive_inf(pos_infD), true);
    EXPECT_EQ(is_positive_inf(neg_infD), false);
    EXPECT_EQ(is_positive_inf(nan_valueD), false);
    EXPECT_EQ(is_positive_inf(subnormalD), false);
}

// Test for single-precision (float)
TEST(NegIinfinityFunctionTest, FloatCheck) {
    EXPECT_EQ(is_negative_inf(original), false);
    EXPECT_EQ(is_negative_inf(zero), false);
    EXPECT_EQ(is_negative_inf(neg_zero), false);
    EXPECT_EQ(is_negative_inf(pos_inf), false);
    EXPECT_EQ(is_negative_inf(neg_inf), true);
    EXPECT_EQ(is_negative_inf(nan_value), false);
    EXPECT_EQ(is_negative_inf(subnormal), false);
}

// Test for double-precision(float)
TEST(NegIinfinityFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_negative_inf(originalD), false);
    EXPECT_EQ(is_negative_inf(zeroD), false);
    EXPECT_EQ(is_negative_inf(neg_zeroD), false);
    EXPECT_EQ(is_negative_inf(pos_infD), false);
    EXPECT_EQ(is_negative_inf(neg_infD), true);
    EXPECT_EQ(is_negative_inf(nan_valueD), false);
    EXPECT_EQ(is_negative_inf(subnormalD), false);
}

// Test for double-precision(float)
TEST(ZeroFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_zero(originalD), false);
    EXPECT_EQ(is_zero(zeroD), true);
    EXPECT_EQ(is_zero(neg_zeroD), true);
    EXPECT_EQ(is_zero(pos_infD), false);
    EXPECT_EQ(is_zero(neg_infD), false);
    EXPECT_EQ(is_zero(nan_valueD), false);
    EXPECT_EQ(is_zero(subnormalD), false);
}

// Test for single-precision (float)
TEST(ZeroFunctionTest, FloatCheck) {
    EXPECT_EQ(is_zero(original), false);
    EXPECT_EQ(is_zero(zero), true);
    EXPECT_EQ(is_zero(neg_zero), true);
    EXPECT_EQ(is_zero(pos_inf), false);
    EXPECT_EQ(is_zero(neg_inf), false);
    EXPECT_EQ(is_zero(nan_value), false);
    EXPECT_EQ(is_zero(subnormal), false);
}

// Test for double-precision(float)
TEST(PosZeroFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_pos_zero(originalD), false);
    EXPECT_EQ(is_pos_zero(zeroD), true);
    EXPECT_EQ(is_pos_zero(neg_zeroD), false);
    EXPECT_EQ(is_pos_zero(pos_infD), false);
    EXPECT_EQ(is_pos_zero(neg_infD), false);
    EXPECT_EQ(is_pos_zero(nan_valueD), false);
    EXPECT_EQ(is_pos_zero(subnormalD), false);
}

// Test for single-precision (float)
TEST(PosZeroFunctionTest, FloatCheck) {
    EXPECT_EQ(is_pos_zero(original), false);
    EXPECT_EQ(is_pos_zero(zero), true);
    EXPECT_EQ(is_pos_zero(neg_zero), false);
    EXPECT_EQ(is_pos_zero(pos_inf), false);
    EXPECT_EQ(is_pos_zero(neg_inf), false);
    EXPECT_EQ(is_pos_zero(nan_value), false);
    EXPECT_EQ(is_pos_zero(subnormal), false);
}

// Test for double-precision(float)
TEST(NegZeroFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_neg_zero(originalD), false);
    EXPECT_EQ(is_neg_zero(zeroD), false);
    EXPECT_EQ(is_neg_zero(neg_zeroD), true);
    EXPECT_EQ(is_neg_zero(pos_infD), false);
    EXPECT_EQ(is_neg_zero(neg_infD), false);
    EXPECT_EQ(is_neg_zero(nan_valueD), false);
    EXPECT_EQ(is_neg_zero(subnormalD), false);
}

// Test for single-precision (float)
TEST(NegZeroFunctionTest, FloatCheck) {
    EXPECT_EQ(is_neg_zero(original), false);
    EXPECT_EQ(is_neg_zero(zero), false);
    EXPECT_EQ(is_neg_zero(neg_zero), true);
    EXPECT_EQ(is_neg_zero(pos_inf), false);
    EXPECT_EQ(is_neg_zero(neg_inf), false);
    EXPECT_EQ(is_neg_zero(nan_value), false);
    EXPECT_EQ(is_neg_zero(subnormal), false);
}

// Test for double-precision(float)
TEST(NanFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_nan(originalD), false);
    EXPECT_EQ(is_nan(zeroD), false);
    EXPECT_EQ(is_nan(neg_zeroD), false);
    EXPECT_EQ(is_nan(pos_infD), false);
    EXPECT_EQ(is_nan(neg_infD), false);
    EXPECT_EQ(is_nan(nan_valueD), true);
    EXPECT_EQ(is_nan(subnormalD), false);
}

// Test for single-precision (float)
TEST(NanFunctionTest, FloatCheck) {
    EXPECT_EQ(is_nan(original), false);
    EXPECT_EQ(is_nan(zero), false);
    EXPECT_EQ(is_nan(neg_zero), false);
    EXPECT_EQ(is_nan(pos_inf), false);
    EXPECT_EQ(is_nan(neg_inf), false);
    EXPECT_EQ(is_nan(nan_value), true);
    EXPECT_EQ(is_nan(subnormal), false);
}

// Test for double-precision(float)
TEST(NormalFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_normal(originalD), true);
    EXPECT_EQ(is_normal(zeroD), false);
    EXPECT_EQ(is_normal(neg_zeroD), false);
    EXPECT_EQ(is_normal(pos_infD), false);
    EXPECT_EQ(is_normal(neg_infD), false);
    EXPECT_EQ(is_normal(nan_valueD), false);
    EXPECT_EQ(is_normal(subnormalD), false);
}

// Test for single-precision (float)
TEST(NormalFunctionTest, FloatCheck) {
    EXPECT_EQ(is_normal(original), true);
    EXPECT_EQ(is_normal(zero), false);
    EXPECT_EQ(is_normal(neg_zero), false);
    EXPECT_EQ(is_normal(pos_inf), false);
    EXPECT_EQ(is_normal(neg_inf), false);
    EXPECT_EQ(is_normal(nan_value), false);
    EXPECT_EQ(is_normal(subnormal), false);
}

// Test for double-precision(float)
TEST(SubnormalFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_subnormal(originalD), false);
    EXPECT_EQ(is_subnormal(zeroD), false);
    EXPECT_EQ(is_subnormal(neg_zeroD), false);
    EXPECT_EQ(is_subnormal(pos_infD), false);
    EXPECT_EQ(is_subnormal(neg_infD), false);
    EXPECT_EQ(is_subnormal(nan_valueD), false);
    EXPECT_EQ(is_subnormal(subnormalD), true);
}

// Test for single-precision (float)
TEST(SubnormalFunctionTest, FloatCheck) {
    EXPECT_EQ(is_subnormal(original), false);
    EXPECT_EQ(is_subnormal(zero), false);
    EXPECT_EQ(is_subnormal(neg_zero), false);
    EXPECT_EQ(is_subnormal(pos_inf), false);
    EXPECT_EQ(is_subnormal(neg_inf), false);
    EXPECT_EQ(is_subnormal(nan_value), false);
    EXPECT_EQ(is_subnormal(subnormal), true);
}

// Test for double-precision(float)
TEST(SignbitFunctionTest, DoubleCheck) {
    EXPECT_EQ(is_signed(originalD), false);
    EXPECT_EQ(is_signed(zeroD), false);
    EXPECT_EQ(is_signed(neg_zeroD), true);
    EXPECT_EQ(is_signed(pos_infD), false);
    EXPECT_EQ(is_signed(neg_infD), true);
    EXPECT_EQ(is_signed(nan_valueD), false);
    EXPECT_EQ(is_signed(subnormalD), false);
}

// Test for single-precision (float)
TEST(SignbitFunctionTest, FloatCheck) {
    EXPECT_EQ(is_signed(original), false);
    EXPECT_EQ(is_signed(zero), false);
    EXPECT_EQ(is_signed(neg_zero), true);
    EXPECT_EQ(is_signed(pos_inf), false);
    EXPECT_EQ(is_signed(neg_inf), true);
    EXPECT_EQ(is_signed(nan_value), false);
    EXPECT_EQ(is_signed(subnormal), false);
}

// Test for double-precision(float)
TEST(ClassifyFunctionTest, DoubleCheck) {
    EXPECT_EQ(fpclassify(originalD), "normal");
    EXPECT_EQ(fpclassify(zeroD), "zero");
    EXPECT_EQ(fpclassify(neg_zeroD), "zero");
    EXPECT_EQ(fpclassify(pos_infD), "infinite");
    EXPECT_EQ(fpclassify(neg_infD), "infinite");
    EXPECT_EQ(fpclassify(nan_valueD), "nan");
    EXPECT_EQ(fpclassify(subnormalD), "subnormal");
}

// Test for single-precision (float)
TEST(ClassifyFunctionTest, FloatCheck) {
    EXPECT_EQ(fpclassify(original), "normal");
    EXPECT_EQ(fpclassify(zero), "zero");
    EXPECT_EQ(fpclassify(neg_zero), "zero");
    EXPECT_EQ(fpclassify(pos_inf), "infinite");
    EXPECT_EQ(fpclassify(neg_inf), "infinite");
    EXPECT_EQ(fpclassify(nan_value), "nan");
    EXPECT_EQ(fpclassify(subnormal), "subnormal");
}

// Test for double-precision(float)
TEST(AbsFunctionTest, DoubleCheck) {
    EXPECT_EQ(abss(originalD), std::abs(originalD));
    EXPECT_EQ(abss(original_negD), std::abs(originalD));
    EXPECT_EQ(abss(zeroD), std::abs(zeroD));
    EXPECT_EQ(abss(neg_zeroD), std::abs(neg_zeroD));
    EXPECT_EQ(abss(pos_infD), std::abs(pos_infD));
    EXPECT_EQ(abss(neg_infD), std::abs(neg_infD));
    EXPECT_EQ(abss(subnormalD), std::abs(subnormalD));
}

// Test for single-precision (float)
TEST(AbsFunctionTest, FloatCheck) {
    EXPECT_EQ(abss(original), std::abs(original));
    EXPECT_EQ(abss(original_neg), std::abs(original));
    EXPECT_EQ(abss(zero), std::abs(zero));
    EXPECT_EQ(abss(neg_zero),std::abs(neg_zero));
    EXPECT_EQ(abss(pos_inf), std::abs(pos_inf));
    EXPECT_EQ(abss(neg_inf), std::abs(neg_inf));
    EXPECT_EQ(abss(subnormal), std::abs(subnormal));
}

// Test for double-precision(float)
TEST(MinFunctionTest, DoubleCheck) {
    EXPECT_EQ(min(originalD, original_negD), original_negD);
    EXPECT_EQ(min(original_negD, originalD), original_negD);
    EXPECT_EQ(min(originalD, zeroD), zeroD);
    EXPECT_EQ(min(original_negD, zeroD), original_negD);
    EXPECT_EQ(min(zeroD, neg_zeroD), neg_zeroD);
    EXPECT_EQ(min(zeroD, neg_infD), neg_infD);
    EXPECT_EQ(min(zeroD, pos_infD), zeroD);
    EXPECT_EQ(min(zeroD, nan_valueD), zeroD);
    EXPECT_EQ(min(originalD, nan_valueD), originalD);
    EXPECT_EQ(min(subnormalD, nan_valueD), subnormalD);
    EXPECT_EQ(min(neg_infD, nan_valueD), neg_infD);
    EXPECT_EQ(min(neg_infD, pos_infD), neg_infD);
    EXPECT_EQ(min(zeroD,originalD), zeroD);
    EXPECT_EQ(min(zeroD,original_negD), original_negD);
    EXPECT_EQ(min(neg_zeroD, zeroD), neg_zeroD);
    EXPECT_EQ(min(neg_infD, zeroD), neg_infD);
    EXPECT_EQ(min(pos_infD, zeroD), zeroD);
    EXPECT_EQ(min(nan_valueD, zeroD), zeroD);
    EXPECT_EQ(min(nan_valueD, originalD), originalD);
    EXPECT_EQ(min(nan_valueD, subnormalD), subnormalD);
    EXPECT_EQ(min(nan_valueD, neg_infD), neg_infD);
    EXPECT_EQ(min(pos_infD, neg_infD), neg_infD);
}

// Test for single-precision (float)
TEST(MinFunctionTest, FloatCheck) {
    EXPECT_EQ(min(original, original_neg), original_neg);
    EXPECT_EQ(min(original_neg, original), original_neg);
    EXPECT_EQ(min(original, zero), zero);
    EXPECT_EQ(min(original_neg, zero), original_neg);
    EXPECT_EQ(min(zero, neg_zero), neg_zero);
    EXPECT_EQ(min(zero, neg_inf), neg_inf);
    EXPECT_EQ(min(zero, pos_inf), zero);
    EXPECT_EQ(min(zero, nan_value), zero);
    EXPECT_EQ(min(original, nan_value), original);
    EXPECT_EQ(min(subnormal, nan_value), subnormal);
    EXPECT_EQ(min(neg_inf, nan_value), neg_inf);
    EXPECT_EQ(min(neg_inf, pos_inf), neg_inf);
    EXPECT_EQ(min(zero, original), zero);
    EXPECT_EQ(min(zero, original_neg), original_neg);
    EXPECT_EQ(min(neg_zero, zero), neg_zero);
    EXPECT_EQ(min(neg_inf, zero), neg_inf);
    EXPECT_EQ(min(pos_inf, zero), zero);
    EXPECT_EQ(min(nan_value, zero), zero);
    EXPECT_EQ(min(nan_value, original), original);
    EXPECT_EQ(min(nan_value, subnormal), subnormal);
    EXPECT_EQ(min(nan_value, neg_inf), neg_inf);
    EXPECT_EQ(min(pos_inf, neg_inf), neg_inf);
}

// Test for double-precision(float)
TEST(MaxFunctionTest, DoubleCheck) {
    EXPECT_EQ(max(originalD, original_negD), originalD);
    EXPECT_EQ(max(original_negD, originalD), originalD);
    EXPECT_EQ(max(originalD, zeroD), originalD);
    EXPECT_EQ(max(original_negD, zeroD), zeroD);
    EXPECT_EQ(max(zeroD, neg_zeroD), zeroD);
    EXPECT_EQ(max(zeroD, neg_infD), zeroD);
    EXPECT_EQ(max(zeroD, pos_infD), pos_infD);
    EXPECT_EQ(max(zeroD, nan_valueD), zeroD);
    EXPECT_EQ(max(originalD, nan_valueD), originalD);
    EXPECT_EQ(max(subnormalD, nan_valueD), subnormalD);
    EXPECT_EQ(max(neg_infD, nan_valueD), neg_infD);
    EXPECT_EQ(max(neg_infD, pos_infD), pos_infD);
    EXPECT_EQ(max(zeroD, originalD), originalD);
    EXPECT_EQ(max(zeroD, original_negD), zeroD);
    EXPECT_EQ(max(neg_zeroD, zeroD), zeroD);
    EXPECT_EQ(max(neg_infD, zeroD), zeroD);
    EXPECT_EQ(max(pos_infD, zeroD), pos_infD);
    EXPECT_EQ(max(nan_valueD, zeroD), zeroD);
    EXPECT_EQ(max(nan_valueD, originalD), originalD);
    EXPECT_EQ(max(nan_valueD, subnormalD), subnormalD);
    EXPECT_EQ(max(nan_valueD, neg_infD), neg_infD);
    EXPECT_EQ(max(pos_infD, neg_infD), pos_infD);
}

// Test for single-precision (float)
TEST(MaxFunctionTest, FloatCheck) {
    EXPECT_EQ(max(original, original_neg), original);
    EXPECT_EQ(max(original_neg, original), original);
    EXPECT_EQ(max(original, zero), original);
    EXPECT_EQ(max(original_neg, zero), zero);
    EXPECT_EQ(max(zero, neg_zero), zero);
    EXPECT_EQ(max(zero, neg_inf), zero);
    EXPECT_EQ(max(zero, pos_inf), pos_inf);
    EXPECT_EQ(max(zero, nan_value), zero);
    EXPECT_EQ(max(original, nan_value), original);
    EXPECT_EQ(max(subnormal, nan_value), subnormal);
    EXPECT_EQ(max(neg_inf, nan_value), neg_inf);
    EXPECT_EQ(max(neg_inf, pos_inf), pos_inf);
    EXPECT_EQ(max(zero, original), original);
    EXPECT_EQ(max(zero, original_neg), zero);
    EXPECT_EQ(max(neg_zero, zero), zero);
    EXPECT_EQ(max(neg_inf, zero), zero);
    EXPECT_EQ(max(pos_inf, zero), pos_inf);
    EXPECT_EQ(max(nan_value, zero), zero);
    EXPECT_EQ(max(nan_value, original), original);
    EXPECT_EQ(max(nan_value, subnormal), subnormal);
    EXPECT_EQ(max(nan_value, neg_inf), neg_inf);
    EXPECT_EQ(max(pos_inf, neg_inf), pos_inf);
}

// Test for single-precision (float)
TEST(ClumpFunctionTest, FloatCheck) {
    EXPECT_EQ(clump(original, original_neg, original), original);
    EXPECT_EQ(clump(original_neg, original_neg, original), original_neg);
    EXPECT_EQ(clump(original, zero, original), original);
    EXPECT_EQ(clump(original_neg, zero, original), zero);
    EXPECT_EQ(clump(zero, neg_zero, zero), zero);
    EXPECT_EQ(clump(zero, neg_inf, zero), zero);
    EXPECT_EQ(clump(zero, zero, pos_inf), zero);
    EXPECT_EQ(clump(zero, zero, nan_value), zero);
    EXPECT_EQ(clump(original, zero, nan_value), original);
    EXPECT_EQ(clump(subnormal, zero, nan_value), zero);
    EXPECT_EQ(clump(neg_inf, zero, nan_value), zero);
    EXPECT_EQ(clump(neg_inf, neg_inf, pos_inf), neg_inf);
    EXPECT_EQ(clump(zero, zero, original), zero);
    EXPECT_EQ(clump(zero, original_neg, original), zero);
    EXPECT_EQ(clump(neg_zero, neg_zero, zero), neg_zero);
    EXPECT_EQ(clump(neg_inf, neg_inf, zero), neg_inf);
    EXPECT_EQ(clump(pos_inf, zero, pos_inf), pos_inf);
    EXPECT_EQ(clump(pos_inf, neg_inf, pos_inf), pos_inf);
}


// Test for double-precision(float)
TEST(ClampFunctionTest, DoubleCheck) {
    EXPECT_EQ(clump(originalD, original_negD, originalD), originalD);
    EXPECT_EQ(clump(original_negD, original_negD, originalD), original_negD);
    EXPECT_EQ(clump(originalD, zeroD, originalD), originalD);
    EXPECT_EQ(clump(original_negD, zeroD, originalD), zeroD);
    EXPECT_EQ(clump(zeroD, neg_zeroD, zeroD), zeroD);
    EXPECT_EQ(clump(zeroD, neg_infD, zeroD), zeroD);
    EXPECT_EQ(clump(zeroD, zeroD, pos_infD), zeroD);
    EXPECT_EQ(clump(zeroD, zeroD, nan_valueD), zeroD);
    EXPECT_EQ(clump(originalD, zeroD, nan_valueD), originalD);
    EXPECT_EQ(clump(subnormalD, zeroD, nan_valueD), zeroD);
    EXPECT_EQ(clump(neg_infD, zeroD, nan_valueD), zeroD);
    EXPECT_EQ(clump(neg_infD, neg_infD, pos_infD), neg_infD);
    EXPECT_EQ(clump(zeroD, zeroD, originalD), zeroD);
    EXPECT_EQ(clump(zeroD, original_negD, originalD), zeroD);
    EXPECT_EQ(clump(neg_zeroD, neg_zeroD, zeroD), neg_zeroD);
    EXPECT_EQ(clump(neg_infD, neg_infD, zeroD), neg_infD);
    EXPECT_EQ(clump(pos_infD, zeroD, pos_infD), pos_infD);
    EXPECT_EQ(clump(pos_infD, neg_infD, pos_infD), pos_infD);
}


int main(int argc, char **argv) {
    for (int i = 0; i < 712; ++i) {
        subnormalD /= 2.45;
    }

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

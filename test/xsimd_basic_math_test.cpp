/***************************************************************************
* Copyright (c) Johan Mabille, Sylvain Corlay, Wolf Vollprecht and         *
* Martin Renou                                                             *
* Copyright (c) QuantStack                                                 *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#include <fstream>
#include <iostream>

#include "gtest/gtest.h"

#include "xsimd/config/xsimd_instruction_set.hpp"

#ifdef XSIMD_INSTR_SET_AVAILABLE

#include "xsimd/math/xsimd_basic_math.hpp"
#include "xsimd/memory/xsimd_aligned_allocator.hpp"
#include "xsimd/types/xsimd_types_include.hpp"
#include "xsimd_basic_math_test.hpp"

namespace xsimd
{
    template <class T, size_t N, size_t A>
    bool test_basic_math(std::ostream& out, const std::string& name)
    {
        simd_basic_math_tester<T, N, A> tester(name);
        return test_simd_basic_math(out, tester);
    }
}

#if XSIMD_X86_INSTR_SET >= XSIMD_X86_SSE2_VERSION
TEST(xsimd, sse_int32_basic_math)
{
    std::ofstream out("log/sse_int32_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<int32_t, 4, 16>(out, "sse int32_t");
    EXPECT_TRUE(res);
}

TEST(xsimd, sse_float_basic_math)
{
    std::ofstream out("log/sse_float_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<float, 4, 16>(out, "sse float");
    EXPECT_TRUE(res);
}

TEST(xsimd, sse_double_basic_math)
{
    std::ofstream out("log/sse_double_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<double, 2, 16>(out, "sse double");
    EXPECT_TRUE(res);
}
#endif

#if XSIMD_X86_INSTR_SET >= XSIMD_X86_AVX_VERSION
TEST(xsimd, avx_int32_basic_math)
{
    std::ofstream out("log/avx_int32_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<int32_t, 8, 32>(out, "avx int32_t");
    EXPECT_TRUE(res);
}

TEST(xsimd, avx_float_basic_math)
{
    std::ofstream out("log/avx_float_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<float, 8, 32>(out, "avx float");
    EXPECT_TRUE(res);
}

TEST(xsimd, avx_double_basic_math)
{
    std::ofstream out("log/avx_double_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<double, 4, 32>(out, "avx double");
    EXPECT_TRUE(res);
}
#endif

#if XSIMD_X86_INSTR_SET >= XSIMD_X86_AVX512_VERSION
TEST(xsimd, avx512_int32_basic_math)
{
    std::ofstream out("log/avx512_int32_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<int32_t, 16, 64>(out, "avx512 int32_t");
    EXPECT_TRUE(res);
}

TEST(xsimd, avx512_float_basic_math)
{
    std::ofstream out("log/avx512_float_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<float, 16, 64>(out, "avx512 float");
    EXPECT_TRUE(res);
}

TEST(xsimd, avx512_double_basic_math)
{
    std::ofstream out("log/avx512_double_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<double, 8, 64>(out, "avx512 double");
    EXPECT_TRUE(res);
}
#endif

#if XSIMD_ARM_INSTR_SET >= XSIMD_ARM7_NEON_VERSION
TEST(xsimd, neon_int_basic_math)
{
    std::ofstream out("log/neon_int_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<int, 4, 16>(out, "neon int");
    EXPECT_TRUE(res);
}

TEST(xsimd, neon_float_basic_math)
{
    std::ofstream out("log/neon_float_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<float, 4, 16>(out, "neon float");
    EXPECT_TRUE(res);
}
#endif
#if XSIMD_ARM_INSTR_SET >= XSIMD_ARM8_64_NEON_VERSION
TEST(xsimd, neon_double_basic_math)
{
    std::ofstream out("log/neon_double_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<double, 2, 32>(out, "neon double");
    EXPECT_TRUE(res);
}
#endif

#if defined(XSIMD_ENABLE_FALLBACK)
TEST(xsimd, fallback_float_basic_math)
{
    std::ofstream out("log/fallback_float_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<float, 7, 16>(out, "fallback float");
    EXPECT_TRUE(res);
}

TEST(xsimd, fallback_double_basic_math)
{
    std::ofstream out("log/fallback_double_basic_math.log", std::ios_base::out);
    bool res = xsimd::test_basic_math<double, 3, 32>(out, "fallback double");
    EXPECT_TRUE(res);
}
#endif
#endif // XSIMD_INSTR_SET_AVAILABLE

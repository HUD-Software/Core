#include <cmath> // std::nextafter, std::ldexp

GTEST_TEST(u128, default_constructor)
{
    u128 v;
    hud_assert_ne(v, 0);
}

GTEST_TEST(u128, constructor_init)
{
    u128 v {};
    hud_assert_eq(v, 0);
}

GTEST_TEST(u128, constructor_i8)
{
    // Init to 0
    {
        hud::u128 v {i8 {}};
        hud_assert_eq(v, (i8 {}));
    }

    // Init to min value
    {
        hud::u128 v {hud::i8_min};
        hud_assert_eq(v, hud::i8_min);
    }

    // Init to max value
    {
        hud::u128 v {hud::i8_max};
        hud_assert_eq(v, hud::i8_max);
    }
}

GTEST_TEST(u128, constructor_i16)
{
    // Init to 0
    {
        hud::u128 v {i16 {}};
        hud_assert_eq(v, i16 {});
    }

    // Init to min value
    {
        hud::u128 v {hud::i16_min};
        hud_assert_eq(v, hud::i16_min);
    }

    // Init to max value
    {
        hud::u128 v {hud::i16_max};
        hud_assert_eq(v, hud::i16_max);
    }
}

GTEST_TEST(u128, constructor_i32)
{
    // Init to 0
    {
        hud::u128 v {i32 {}};
        hud_assert_eq(v, i32 {});
    }

    // Init to min value
    {
        hud::u128 v {hud::i32_min};
        hud_assert_eq(v, hud::i32_min);
    }

    // Init to max value
    {
        hud::u128 v {hud::i32_max};
        hud_assert_eq(v, hud::i32_max);
    }
}

GTEST_TEST(u128, constructor_i64)
{
    // Init to 0
    {
        hud::u128 v {i64 {}};
        hud_assert_eq(v, i64 {});
    }

    // Init to min value
    {
        hud::u128 v {hud::i64_min};
        hud_assert_eq(v, hud::i64_min);
    }

    // Init to max value
    {
        hud::u128 v {hud::i64_max};
        hud_assert_eq(v, hud::i64_max);
    }
}

GTEST_TEST(u128, constructor_f32)
{
    // Init to 0
    {
        hud::u128 v {f32 {}};
        hud_assert_eq((float)v, f32 {});
    }

    // Init to min positive value
    {
        f32 value = hud::f32_min_positive;
        // Check value is not NaN or infinite
        hud_assert_true(std::isfinite(value));
        // Ensure we are positive
        hud_assert_true(value > -1);

        hud::u128 v {hud::f32_min};

        // Cast to u32 because f32_min is the lowest positive value of an f32
        hud_assert_eq(static_cast<u32>(v), static_cast<u32>(value));
    }

    // Init to max value
    {
        // Compute the greatest value
        f32 value = hud::f32_max;

        hud::u128 v {value};
        // Check value is not NaN or infinite
        hud_assert_true(std::isfinite(value));
        // Ensure we are positive
        hud_assert_true(value > -1);

        hud_assert_eq(static_cast<f32>(v), value);
    }
}

GTEST_TEST(u128, constructor_f64)
{
    // Init to 0
    {
        hud::u128 v {f64 {}};
        hud_assert_eq((float)v, f64 {});
    }

    // Init to min positive value
    {
        f64 value = hud::f64_min_positive;
        // Check value is not NaN or infinite
        hud_assert_true(std::isfinite(value));
        // Ensure we are positive
        hud_assert_true(value > -1);
        // Check value is lower than 2^128
        hud_assert_true(value < std::ldexp(static_cast<f64>(1), 128));

        hud::u128 v {value};
        hud_assert_eq(static_cast<u64>(v), static_cast<u64>(hud::f64_min));
    }

    // Init to big value
    {
        // Compute the greatest value just before 2^128
        f64 value = std::nextafter(std::ldexp(1.0, 128), 0.0);

        // Check value is not NaN or infinite
        hud_assert_true(std::isfinite(value));
        // Ensure we are positive
        hud_assert_true(value > -1);
        // Check value is lower than 2^128
        hud_assert_true(value < std::ldexp(static_cast<f64>(1), 128));

        hud::u128 v {value};
        hud_assert_eq(static_cast<f64>(v), value);
    }
}

GTEST_TEST(u128, constructor_u128)
{
    // Init to 0
    {
        hud::u128 v {hud::u128 {0}};
        hud_assert_eq(v, hud::u128 {0});
    }

    // Init to min value
    {
        hud::u128 v {hud::u128_min};
        hud_assert_eq(v, hud::u128_min);
    }

    // Init to max value
    {
        hud::u128 v {hud::u128_max};
        hud_assert_eq(v, hud::u128_max);
    }
}

GTEST_TEST(u128, constructor_i128)
{
    // Init to 0
    {
        hud::u128 v {hud::i128 {0}};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128 {0}));
    }

    // Init to min value
    {
        hud::u128 v {hud::i128_min};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_min));
    }

    // Init to max value
    {
        hud::u128 v {hud::i128_max};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_max));
    }
}

GTEST_TEST(u128, constructor_high_low)
{

    {
        hud::u128 v {0, 0};
        hud_assert_eq(v.high(), 0);
        hud_assert_eq(v.low(), 0);
    }

    {
        hud::u128 v {hud::u64_max, 0};
        hud_assert_eq(v.high(), hud::u64_max);
        hud_assert_eq(v.low(), 0);
    }

    {
        hud::u128 v {0, hud::u64_max};
        hud_assert_eq(v.high(), 0);
        hud_assert_eq(v.low(), hud::u64_max);
    }
}

#if defined(HD_INTRINSIC_INT128_SUPPORTED)
GTEST_TEST(u128, constructor__int128)
{
    // Init to 0
    {
        hud::u128 v {__int128 {0}};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128 {0}));
    }

    // Init to min value
    {
        hud::u128 v {hud::i128_min};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_min));
    }

    // Init to max value
    {
        hud::u128 v {hud::i128_max};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_max));
    }
}

GTEST_TEST(u128, constructor_unsigned__int128)
{
    // Init to 0
    {
        unsigned __int128 value {0};
        hud::u128 v {value};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128 {0}));
    }

    // Init to min value
    {
        hud::u128 v {hud::i128_min};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_min));
    }

    // Init to max value
    {
        hud::u128 v {hud::i128_max};
        hud_assert_eq(v, static_cast<hud::u128>(hud::i128_max));
    }
}

#endif
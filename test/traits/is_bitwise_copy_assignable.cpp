#include <core/traits/is_bitwise_copy_assignable.h>

namespace hud_test {
    enum comp_enum {};
    enum class comp_enum_2 {};
    enum class comp_enum_3 : u8 {};
    enum class comp_enum_4 : u64 {};

    struct a { };
    struct b : a {};
    struct c { c& operator= (const a&) { return *this; } };
    struct d { d& operator= (const d&) { return *this; } };

}

TEST(traits, is_bitwise_copy_assignable)
{
    // i8
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i8, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, i64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i8, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, u64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i8, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i8, uptr>));

    // u8
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u8, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, i64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u8, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, u64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u8, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u8, uptr>));


    // i16
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, i8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i16, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, u8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i16, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i16, wchar>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, wchar>));
#endif 
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i16, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i16, uptr>));

    // u16
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, i8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u16, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, u8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u16, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u16, wchar>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, wchar>));
#endif 
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u16, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u16, uptr>));


    // i32
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, i16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, u16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, wchar>));
#else
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, wchar>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, char16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, f64>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, uptr>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32, uptr>));
#endif

    // u32
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, i16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, u16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, wchar>));
#else
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, wchar>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, char16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, f64>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u32, uptr>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u32, uptr>));
#endif

    // i64
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, i32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i64, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, u32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i64, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, f64>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i64, uptr>));
#else
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i64, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i64, uptr>));
#endif

    // u64
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, i32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u64, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, u32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u64, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, f64>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<u64, uptr>));
#else
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u64, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<u64, uptr>));
#endif

    // ansichar
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<ansichar, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, i64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<ansichar, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, u64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<ansichar, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<ansichar, uptr>));

    // wchar
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, i8>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, i32>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, i16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, i32>));
#endif    
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, u8>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, u32>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, u16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, u32>));
#endif    
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, ansichar>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, wchar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, char32>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, char16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<wchar, char32>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<wchar, uptr>));

    // char16
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, i8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char16, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, u8>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char16, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char16, wchar>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, wchar>));
#endif
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char16, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char16, uptr>));

    // char32
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, i16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, u16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, ansichar>));
#if defined(HD_COMPILER_MSVC) || defined(HD_COMPILER_CLANG_CL)
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, wchar>));
#else
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, wchar>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, char16>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, f64>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<char32, uptr>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<char32, uptr>));
#endif
    // f32
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, char32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<f32, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f32, uptr>));

    // f64
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, i16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, i64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, u16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, u64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, char16>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, char32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, f32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<f64, f64>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, iptr>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<f64, uptr>));

    // iptr
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, i16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, i64>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, i32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, i64>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, u16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, u64>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, u32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, u64>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, char16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, char32>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, char32>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<iptr, f64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<iptr, uptr>));

    // uptr
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, i8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, i16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, i64>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, i32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, i64>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, u8>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, u16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, u32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, u64>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, u32>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, u64>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, ansichar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, wchar>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, char16>));
#if defined(HD_TARGET_32_BITS)
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, char32>));
#else
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, char32>));
#endif
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, f32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<uptr, f64>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, iptr>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<uptr, uptr>));

   

    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum, hud_test::comp_enum>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum_2, hud_test::comp_enum_2>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum_3, hud_test::comp_enum_3>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum_4, hud_test::comp_enum_4>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum, hud_test::comp_enum_2>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum, hud_test::comp_enum_3>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum, hud_test::comp_enum_4>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::comp_enum_3, hud_test::comp_enum_4>));

    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32&, i32>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32[], i32[]>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<i32[32], i32[32]>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<i32*, i32*>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::a, hud_test::a>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::a, hud_test::b>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::a, hud_test::c>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::a, hud_test::d>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::b, hud_test::a>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::b, hud_test::b>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::b, hud_test::c>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::b, hud_test::d>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::c, hud_test::a>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::c, hud_test::b>));
    ASSERT_TRUE((hud::is_bitwise_copy_assignable_v<hud_test::c, hud_test::c>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::c, hud_test::d>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::d, hud_test::a>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::d, hud_test::b>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::d, hud_test::c>));
    ASSERT_FALSE((hud::is_bitwise_copy_assignable_v<hud_test::d, hud_test::d>));
}
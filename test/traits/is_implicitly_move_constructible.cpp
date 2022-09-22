#include <core/traits/is_implicitly_move_constructible.h>

namespace {
    struct no_explicit_ctor {
        no_explicit_ctor(no_explicit_ctor&&) noexcept {};
    };
    struct explicit_ctor {
        explicit explicit_ctor(explicit_ctor&&) noexcept {};
    };
}

TEST(traits, is_implicitly_move_constructible) {
    ASSERT_FALSE((hud::is_implicitly_move_constructible_v<explicit_ctor>));
    ASSERT_TRUE((hud::is_implicitly_move_constructible_v<no_explicit_ctor>));
    ASSERT_TRUE((hud::is_implicitly_move_constructible_v<i32>));
    ASSERT_TRUE((hud::is_implicitly_move_constructible_v<const i32>));
    ASSERT_TRUE((hud::is_implicitly_move_constructible_v<volatile i32>));
    ASSERT_TRUE((hud::is_implicitly_move_constructible_v<const volatile i32>));
}
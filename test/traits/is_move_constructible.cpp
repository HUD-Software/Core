#include <core/traits/is_move_constructible.h>

namespace hud_test {
    struct a { };
    struct b { b(b&&) = delete; };
    struct c { c(b&&) noexcept { } };
}

TEST(traits, is_move_constructible) {
    ASSERT_TRUE((hud::is_move_constructible_v<i32>));
    ASSERT_TRUE((hud::is_move_constructible_v<hud_test::a>));
    ASSERT_FALSE((hud::is_move_constructible_v<hud_test::b>));
    ASSERT_TRUE((hud::is_move_constructible_v<hud_test::c, hud_test::b>));
    ASSERT_FALSE((hud::is_move_constructible_v<hud_test::b, hud_test::c>));
}
#include <core/traits/has_unique_object_representations.h>

namespace {
    struct empty {};
    struct a {
        i32 a;
    };
    struct b {
        i32 a;
        f32 f;
    };
    struct c {
        i32 a;
        i16 f;
        i16 g;
    };
    struct padded {
        u8 p;
        // Padding of 3 bytes
        u32 a;
    };
    struct  derived : a {};

    struct  derived2 : a {
        virtual void fn() {}
    };
}

TEST(traits, HasUniqueObjectRepresentations) {


    ASSERT_TRUE(hud::has_unique_object_representations_v<i32>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<i32*>);
    ASSERT_FALSE(hud::has_unique_object_representations_v<i32&>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<i32[]>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<i32[][2]>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<i32[2]>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<i32[2][2]>);
    ASSERT_FALSE(hud::has_unique_object_representations_v<hud::void_t<>>);
    ASSERT_FALSE(hud::has_unique_object_representations_v<f32>);
    ASSERT_FALSE(hud::has_unique_object_representations_v<f64>);

    
    ASSERT_FALSE(hud::has_unique_object_representations_v<empty>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<a>);
    ASSERT_FALSE(hud::has_unique_object_representations_v<b>);
    ASSERT_TRUE(hud::has_unique_object_representations_v<c>);

    
    ASSERT_FALSE(hud::has_unique_object_representations_v<padded>);

    
    ASSERT_TRUE(hud::has_unique_object_representations_v<derived>);

    
    ASSERT_FALSE(hud::has_unique_object_representations_v<derived2>);
}
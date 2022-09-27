#include <core/character.h>

static constexpr ansichar digits[] = { '0' , '1' ,'2', '3', '4', '5', '6', '7', '8', '9' };
static constexpr wchar wide_digits[] = { L'0' , L'1' , L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9' };
static constexpr ansichar low_letter[] = { 'a' , 'b' ,'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
static constexpr wchar wide_low_letter[] = { L'a' , L'b' , L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j', L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's', L't', L'u', L'v', L'w', L'x', L'y', L'z' };
static constexpr ansichar higher_letter[] = { 'A' , 'B' ,'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
static constexpr wchar wide_higher_letter[] = { L'A' , L'B' , L'C', L'D', L'E', L'F', L'G', L'H', L'I', L'J', L'K', L'L', L'M', L'N', L'O', L'P', L'Q', L'R', L'S', L'T', L'U', L'V', L'W', L'X', L'Y', L'Z' };
static constexpr ansichar hexa[] = { '0' , '1' ,'2', '3', '4', '5', '6', '7', '8', '9', 'a' , 'b' ,'c', 'd', 'e', 'f', 'A' , 'B' ,'C', 'D', 'E', 'F' };
static constexpr wchar wide_hexa[] = { L'0' , L'1' , L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9', L'a' , L'b' , L'c', L'd', L'e', L'f', L'A' , L'B' , L'C', L'D', L'E', L'F' };
static constexpr ansichar space_and_tab[] = { ' ', '\t' };
static constexpr wchar wide_space_and_tab[] = { L' ', L'\t' };
static constexpr ansichar control[] = { '\x0', '\x1' , '\x2', '\x3', '\x4', '\x5', '\x6', '\x7', '\x8', '\x9', '\xA','\xB', '\xC', '\xD', '\xE', '\xF', '\x7F', '\x10', '\x11', '\x12' , '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1A', '\x1B', '\x1C', '\x1D', '\x1E', '\x1F' };
static constexpr wchar wide_control[] = { L'\x0', L'\x1' , L'\x2', L'\x3', L'\x4', L'\x5', L'\x6', L'\x7', L'\x8', L'\x9', L'\xA', L'\xB', L'\xC', L'\xD', L'\xE', L'\xF', L'\x7F', L'\x10', L'\x11', L'\x12' , L'\x13', L'\x14', L'\x15', L'\x16', L'\x17', L'\x18', L'\x19', L'\x1A', L'\x1B', L'\x1C', L'\x1D', L'\x1E', L'\x1F' };
static constexpr ansichar punc[] = { '!', '\"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';' ,'<', '=', '>', '?', '@', '[', '\\', ']', '^', '_', '`', '{', '|', '}', '~' };
static constexpr ansichar wide_punc[] = { L'!', L'\"', L'#', L'$', L'%', L'&', L'\'', L'(', L')', L'*', L'+', L',', L'-', L'.', L'/', L':', L';' , L'<', L'=', L'>', L'?', L'@', L'[', L'\\', L']', L'^', L'_', L'`', L'{', L'|', L'}', L'~' };


TEST(character, is_pure_ansi)
{


    for (ansichar cur = 0; cur < hud::ansichar_max; cur++) {
        ASSERT_TRUE(hud::character::is_pure_ansi(cur));
    }
    for (wchar cur = 0; cur < hud::wchar_max; cur++) {
        if (cur <= hud::ansichar_max) {
            ASSERT_TRUE(hud::character::is_pure_ansi(cur));
        }
        else {
            ASSERT_FALSE(hud::character::is_pure_ansi(cur));
        }
    }
}

TEST(character, is_null)
{


    ASSERT_TRUE(hud::character::is_null('\0'));
    ASSERT_FALSE(hud::character::is_null(' '));
    ASSERT_TRUE(hud::character::is_null(L'\0'));
    ASSERT_FALSE(hud::character::is_null(L' '));
}

TEST(character, is_alphanumeric) 
{


    for (const auto& alphanumeric : digits) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }
    for (const auto& alphanumeric : wide_digits) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }

    for (const auto& alphanumeric : low_letter) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }
    for (const auto& alphanumeric : wide_low_letter) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }

    for (const auto& alphanumeric : wide_higher_letter) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }
    for (const auto& alphanumeric : higher_letter) {
        ASSERT_TRUE(hud::character::is_alphanumeric(alphanumeric));
    }

    for (const auto& no_alphanumeric : space_and_tab) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }
    for (const auto& no_alphanumeric : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }

    for (const auto& no_alphanumeric : control) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }
    for (const auto& no_alphanumeric : wide_control) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }

    for (const auto& no_alphanumeric : punc) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }
    for (const auto& no_alphanumeric : wide_punc) {
        ASSERT_FALSE(hud::character::is_alphanumeric(no_alphanumeric));
    }
}   

TEST(character, is_alphabetic)
{


    for (const auto& no_alphabetic : digits) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }
    for (const auto& no_alphabetic : wide_digits) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }

    for (const auto& alphabetic : low_letter) {
        ASSERT_TRUE(hud::character::is_alphabetic(alphabetic));
    }
    for (const auto& alphabetic : higher_letter) {
        ASSERT_TRUE(hud::character::is_alphabetic(alphabetic));
    }

    for (const auto& alphabetic : wide_low_letter) {
        ASSERT_TRUE(hud::character::is_alphabetic(alphabetic));
    }
    for (const auto& alphabetic : wide_higher_letter) {
        ASSERT_TRUE(hud::character::is_alphabetic(alphabetic));
    }

    for (const auto& no_alphabetic : space_and_tab) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }
    for (const auto& no_alphabetic : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }

    for (const auto& no_alphabetic : control) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }
    for (const auto& no_alphabetic : wide_control) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }

    for (const auto& no_alphabetic : punc) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }
    for (const auto& no_alphabetic : wide_punc) {
        ASSERT_FALSE(hud::character::is_alphabetic(no_alphabetic));
    }
}


TEST(character, is_lowercase)
{


    for (const auto& no_lowercase : digits) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }
    for (const auto& no_lowercase : wide_digits) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }

    for (const auto& lowercase : low_letter) {
        ASSERT_TRUE(hud::character::is_lowercase(lowercase));
    }
    for (const auto& no_lowercase : higher_letter) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }

    for (const auto& lowercase : wide_low_letter) {
        ASSERT_TRUE(hud::character::is_lowercase(lowercase));
    }
    for (const auto& no_lowercase : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }

    for (const auto& no_lowercase : space_and_tab) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }
    for (const auto& no_lowercase : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }

    for (const auto& no_lowercase : control) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }
    for (const auto& no_lowercase : wide_control) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }

    for (const auto& no_lowercase : punc) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }
    for (const auto& no_lowercase : wide_punc) {
        ASSERT_FALSE(hud::character::is_lowercase(no_lowercase));
    }
}


TEST(character, is_uppercase)
{


    for (const auto& no_uppercase : digits) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& no_uppercase : wide_digits) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }

    for (const auto& no_uppercase : low_letter) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& uppercase : higher_letter) {
        ASSERT_TRUE(hud::character::is_uppercase(uppercase));
    }

    for (const auto& no_uppercase : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& uppercase : wide_higher_letter) {
        ASSERT_TRUE(hud::character::is_uppercase(uppercase));
    }

    for (const auto& no_uppercase : space_and_tab) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& no_uppercase : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }

    for (const auto& no_uppercase : control) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& no_uppercase : wide_control) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }

    for (const auto& no_uppercase : punc) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
    for (const auto& no_uppercase : wide_punc) {
        ASSERT_FALSE(hud::character::is_uppercase(no_uppercase));
    }
}

TEST(character, is_digit)
{


    for (const auto& digit : digits) {
        ASSERT_TRUE(hud::character::is_digit(digit));
    }
    for (const auto& digit : wide_digits) {
        ASSERT_TRUE(hud::character::is_digit(digit));
    }

    for (const auto& no_digit : low_letter) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
    for (const auto& no_digit : higher_letter) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }

    for (const auto& no_digit : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
    for (const auto& no_digit : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }

    for (const auto& no_digit : space_and_tab) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
    for (const auto& no_digit : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }

    for (const auto& no_digit : control) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
    for (const auto& no_digit : wide_control) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }

    for (const auto& no_digit : punc) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
    for (const auto& no_digit : wide_punc) {
        ASSERT_FALSE(hud::character::is_digit(no_digit));
    }
}

TEST(character, is_hexa)
{


    static constexpr ansichar no_hexa[] = { 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    static constexpr wchar wide_no_hexa[] = { L'G', L'H', L'I', L'J', L'K', L'L', L'M', L'N', L'O', L'P', L'Q', L'R', L'S', L'T', L'U', L'V', L'W', L'X', L'Y', L'Z' };

    for (const auto& hexa : hexa) {
        ASSERT_TRUE(hud::character::is_hexa(hexa));
    }
    for (const auto& hexa : wide_hexa) {
        ASSERT_TRUE(hud::character::is_hexa(hexa));
    }

    for (const auto& no_hexa : no_hexa) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }
    for (const auto& no_hexa : wide_no_hexa) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }

    for (const auto& no_hexa : space_and_tab) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }
    for (const auto& no_hexa : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }

    for (const auto& no_hexa : control) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }
    for (const auto& no_hexa : wide_control) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }

    for (const auto& no_hexa : punc) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }
    for (const auto& no_hexa : wide_punc) {
        ASSERT_FALSE(hud::character::is_hexa(no_hexa));
    }
}

TEST(character, is_space_or_tab)
{


    for (const auto& no_space_or_tab : digits) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }
    for (const auto& no_space_or_tab : wide_digits) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }

    for (const auto& no_space_or_tab : low_letter) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }
    for (const auto& no_space_or_tab : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }

    for (const auto& no_space_or_tab : higher_letter) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }
    for (const auto& no_space_or_tab : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }

    for (const auto& space_or_tab : space_and_tab) {
        ASSERT_TRUE(hud::character::is_space_or_tab(space_or_tab));
    }
    for (const auto& space_or_tab : wide_space_and_tab) {
        ASSERT_TRUE(hud::character::is_space_or_tab(space_or_tab));
    }

    for (const auto& no_space_or_tab : control) {
        if (no_space_or_tab == ' ' || no_space_or_tab == '\t') {
            ASSERT_TRUE(hud::character::is_space_or_tab(no_space_or_tab));
        }
        else {
            ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
        }
    }
    for (const auto& no_space_or_tab : wide_control) {
        if (no_space_or_tab == L' ' || no_space_or_tab == L'\t') {
            ASSERT_TRUE(hud::character::is_space_or_tab(no_space_or_tab));
        }
        else {
            ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
        }
    }

    for (const auto& no_space_or_tab : punc) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }
    for (const auto& no_space_or_tab : wide_punc) {
        ASSERT_FALSE(hud::character::is_space_or_tab(no_space_or_tab));
    }

}


TEST(character, is_control)
{


    for (const auto& no_control : digits) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }
    for (const auto& no_control : wide_digits) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }

    for (const auto& no_control : low_letter) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }
    for (const auto& no_control : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }

    for (const auto& no_control : higher_letter) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }
    for (const auto& no_control : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }

    for (const auto& control : control) {
        ASSERT_TRUE(hud::character::is_control(control));
    }
    for (const auto& control : wide_control) {
        ASSERT_TRUE(hud::character::is_control(control));
    }

    for (const auto& no_control : punc) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }
    for (const auto& no_control : wide_punc) {
        ASSERT_FALSE(hud::character::is_control(no_control));
    }
}

TEST(character, is_space)
{


    static constexpr ansichar Space[] = { ' ', '\x20', '\x09', '\xA', '\xB', '\xC', '\xD' };
    static constexpr wchar WideSpace[] = { L' ', L'\x20', L'\x09', L'\xA', L'\xB', L'\xC', L'\xD' };

    for (const auto& no_space : digits) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }
    for (const auto& no_space : wide_digits) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }

    for (const auto& no_space : low_letter) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }
    for (const auto& no_space : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }

    for (const auto& no_space : higher_letter) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }
    for (const auto& no_space : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }

    for (const auto& no_space : control) {
        bool in_both = false;
        for (const auto& space : Space) {
            if (space == no_space) {
                in_both = true;
                break;
            }
        }
        if (in_both) {
            ASSERT_TRUE(hud::character::is_space(no_space));
        }
        else {
            ASSERT_FALSE(hud::character::is_space(no_space));
        }
    }
    for (const auto& no_space : wide_control) {
        bool in_both = false;
        for (const auto& space : WideSpace) {
            if (space == no_space) {
                in_both = true;
                break;
            }
        }
        if (in_both) {
            ASSERT_TRUE(hud::character::is_space(no_space));
        }
        else {
            ASSERT_FALSE(hud::character::is_space(no_space));
        }
    }

    for (const auto& space : Space) {
        ASSERT_TRUE(hud::character::is_space(space));
    }
    for (const auto& space : WideSpace) {
        ASSERT_TRUE(hud::character::is_space(space));
    }
    for (const auto& no_space : punc) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }
    for (const auto& no_space : wide_punc) {
        ASSERT_FALSE(hud::character::is_space(no_space));
    }
}

TEST(character, is_punctuation)
{


    for (const auto& no_punctuation : digits) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }
    for (const auto& no_punctuation : wide_digits) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }

    for (const auto& no_punctuation : low_letter) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }
    for (const auto& no_punctuation : wide_low_letter) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }

    for (const auto& no_punctuation : higher_letter) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }
    for (const auto& no_punctuation : wide_higher_letter) {
        ASSERT_FALSE(hud::character::is_punctuation(no_punctuation));
    }

    for (const auto& no_punctuation : space_and_tab) {
        ASSERT_FALSE(hud::character::is_hexa(no_punctuation));
    }
    for (const auto& no_punctuation : wide_space_and_tab) {
        ASSERT_FALSE(hud::character::is_hexa(no_punctuation));
    }

    for (const auto& no_punctuation : control) {
        ASSERT_FALSE(hud::character::is_hexa(no_punctuation));
    }
    for (const auto& no_punctuation : wide_control) {
        ASSERT_FALSE(hud::character::is_hexa(no_punctuation));
    }

    for (const auto& punctuation : punc) {
        ASSERT_TRUE(hud::character::is_punctuation(punctuation));
    }
    for (const auto& punctuation : wide_punc) {
        ASSERT_TRUE(hud::character::is_punctuation(punctuation));
    }
}

TEST(character, to_lowercase)
{


    for (const auto& no_tolower : digits) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }

    const usize count = sizeof(low_letter) / sizeof(low_letter[0]);
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_lowercase(low_letter[at]) == low_letter[at]);
    }
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_lowercase(higher_letter[at]) == low_letter[at]);
    }

    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_lowercase(wide_low_letter[at]) == wide_low_letter[at]);
    }
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_lowercase(wide_higher_letter[at]) == wide_low_letter[at]);
    }

    for (const auto& no_tolower : control) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_control) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }

    for (const auto& no_tolower : space_and_tab) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_space_and_tab) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }

    for (const auto& no_tolower : punc) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_punc) {
        ASSERT_TRUE(hud::character::to_lowercase(no_tolower) == no_tolower);
    }
}

TEST(character, to_uppercase)
{


    for (const auto& no_tolower : digits) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }

    const usize count = sizeof(low_letter) / sizeof(low_letter[0]);
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_uppercase(low_letter[at]) == higher_letter[at]);
    }
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_uppercase(higher_letter[at]) == higher_letter[at]);
    }

    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_uppercase(wide_low_letter[at]) == wide_higher_letter[at]);
    }
    for (usize at = 0; at < count; at++) {
        ASSERT_TRUE(hud::character::to_uppercase(wide_higher_letter[at]) == wide_higher_letter[at]);
    }

    for (const auto& no_tolower : control) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_control) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }

    for (const auto& no_tolower : space_and_tab) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_space_and_tab) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }

    for (const auto& no_tolower : punc) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }
    for (const auto& no_tolower : wide_punc) {
        ASSERT_TRUE(hud::character::to_uppercase(no_tolower) == no_tolower);
    }
}
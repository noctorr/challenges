#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <array>
#include <ranges>
#include <string>

namespace detail {
    static std::array<const char*, 4> keywords = {
        "cat",
        "grep",
        "ls",
        "mkdir"
    };

    bool P_compare(
        std::string_view str1,
        std::string_view str2
    ) {
        using str_view_sz_t = std::string_view::size_type;

        str_view_sz_t l1 = str1.length();
        str_view_sz_t l2 = str2.length();

        if (
            l1 >= l2
        ) {
            
            for (
                int i = 0;
                i < l1;
                i++
            ) {
                
            }
        } else {

        }
    }

    int arg_size(
        int* argc,
        char*** argv
    ) {
        int result = 0;
        for (
            int i = 0;
            i < *argc;
            i++
        ) {
            if ( std::ranges::any_of(
                keywords,
                [argv, i](
                    const char* const& keyword
                ) {
                    return std::strcmp(
                        *((*argv) + i),
                        keyword
                    ) == std::strlen(keyword);
                }
            ) ) {
                result++;
            } else if (
                
            ) {}
        }
    }
}

int main(
    int argc,
    char** argv
) {
    return EXIT_SUCCESS;
}
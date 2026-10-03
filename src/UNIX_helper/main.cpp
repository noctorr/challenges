#include <iostream>
#include <cstring>
#include <cstdlib>
#include <array>
#include <algorithm>
#include <string>
#include <utility>
#include <span>

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

        str_view_sz_t size = 0;

        for (
            int i = 0;
            i < ((l1 > l2) ? l2 : l1);
            i++
        ) {
            if (
                std::char_traits<char>::eq(
                    str1.at(i),
                    str2.at(i)
                )
            ) {
                size++;
            }
        }

        if (
            size == l1 || size == l2
        ) {
            return true;
        } else {
            return false;
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
            if ( 
                std::ranges::any_of(
                keywords,
                [argv, i](
                    const char* const& keyword
                ) {
                    return std::strcmp(
                        *((*argv) + i),
                        keyword
                    ) == 0;
                }
            ) ) {
                result++;
            } else if (
                detail::P_compare(*((*argv) + i), keywords[i])
            ) {
                result++;
            } else if (
                !(detail::P_compare(*((*argv) + i), "") || detail::P_compare(*((*argv) + i), " "))
            ){
                result++;
            }
        }

        return result;
    }
}

int main(
    int argc,
    char** argv
) {
    int size = detail::arg_size(&argc, &argv);
    std::cout << size << std::endl;
    return EXIT_SUCCESS;
}
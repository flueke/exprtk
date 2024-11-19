/*
 **************************************************************
 *         C++ Mathematical Expression Toolkit Library        *
 *                                                            *
 * Simple Example 01                                          *
 * Author: Arash Partow (1999-2024)                           *
 * URL: https://www.partow.net/programming/exprtk/index.html  *
 *                                                            *
 * Copyright notice:                                          *
 * Free use of the Mathematical Expression Toolkit Library is *
 * permitted under the guidelines and in accordance with the  *
 * most current version of the MIT License.                   *
 * https://www.opensource.org/licenses/MIT                    *
 * SPDX-License-Identifier: MIT                               *
 *                                                            *
 **************************************************************
*/


#include <cstdio>
#include <string>

#include "exprtk.hpp"


template <typename T>
void the_function(const std::string &expression_string)
{
   typedef exprtk::expression<T>   expression_t;
   typedef exprtk::parser<T>       parser_t;

   expression_t expression;

   parser_t parser;
   if (!parser.compile(expression_string,expression))
   {
        printf("the_function() - Error: %s   Expression: %s\n",
            parser.error().c_str(),
            expression_string.c_str());
        return;
   }

    const T y = expression.value();
    printf("%f\n", y);
}

int main()
{
   const std::string expression_string1 =
      "for (var i := 0; i < 3; i += 1) { i; };\n"
      "for (var i := 0; i < 3; i += 1) { i * i; };\n"
      "for (var i := 0; i < 3; i += 1) { i * i * i; };\n";

   const std::string expression_string2 =
      "for (var i := 0; i < 3; i += 1) { i; }\n"
      "for (var i := 0; i < 3; i += 1) { i * i; }\n"
      "for (var i := 0; i < 3; i += 1) { i * i * i; }\n";

    printf("with semicolons:\n");
    the_function<double>(expression_string1);
    printf("without semicolons:\n");
    the_function<double>(expression_string2);
}

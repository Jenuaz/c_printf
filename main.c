#include "ft_printf.h"
#include <locale.h>


/*Flags done:   '+', '-', '*', 'sp', '0'      */
/*Specificators: 'd', 'i'                     */

#define ULONG_MAX  18446744073709551615
int main(void)
{
    printf("%10s\n", "this");
    ft_printf("%10s\n", "this");

    printf("%s\n", "abc");
    ft_printf("%s\n", "abc");

    printf("%-5.2s\n", "");
    ft_printf("%-5.2s\n", "");

    printf("%5.2s\n", "this");
    ft_printf("%5.2s\n", "this");

    printf("%5.2s\n", "this");
    ft_printf("%5.2s\n", "this");

    printf("%15.4s\n", "42");
    ft_printf("%15.4s\n", "42");

    printf("%15.4s\n", "42 is the answer");
    ft_printf("%15.4s\n", "42 is the answer");

    printf("%4.15s\n", "42");
    ft_printf("%4.15s\n", "42");
//
//    printf("@moulitest: %s\n", NULL);
//    ft_printf("@moulitest: %s\n", NULL);
//
//    printf("%.s\n", "this");
//    ft_printf("%.s\n", "this");
//
//    printf("%1.3s\n", "this");
//    ft_printf("%1.3s\n", "this");

//    printf("%.s\n", "this");
//    ft_printf("%.s\n", "this");
//    printf("{%*d}\n", -5, 42);
//    ft_printf("{%*d}\n", -5, 42);
//
//    printf("{%3*d}\n", 0, 0);
//    ft_printf("{%3*d}\n", 0, 0);

//
//    printf("{%.*s}\n", 0, "42");
//    ft_printf("{%.*s}\n", 0, "42");

//
//    printf("%#.o\n", 42);
//    ft_printf("%#.o\n", 42);

//    printf("%lu, %lu\n", 0, ULONG_MAX);
//    ft_printf("%lu, %lu\n", 0, ULONG_MAX);

//    printf("%lo, %lo\n", 0, ULONG_MAX);
//    ft_printf("%lo, %lo\n", 0, ULONG_MAX);


//
//    printf("{% 03d}\n", 0);
//    ft_printf("{% 03d}\n", 0);
// char *string = "string";

//    ft_printf("%s %s", NULL, string);
//    printf("%d", printf("%s", NULL));

//    ft_printf("%c\n", 42);
//    printf("%c\n", 42);
//    ft_printf("%5c\n", 42);
//    printf("%5c\n", 42);
//    ft_printf("%-5c\n", 42);
//    printf("%-5c\n", 42);

//    ft_printf("%c\n", 0);
//    printf("%c\n", 0);
//    ft_printf("%2c\n", 0);
//    printf("%2c\n", 0);
//    ft_printf("%c\n", NULL);
//    printf("%c\n", NULL);
//    ft_printf("% c\n", 0);
//    printf("% c\n", 0);
//    printf("%d\n", ft_printf("%lu", -42));
//    printf("%d\n", printf("%lu", -42));
//
//    ft_printf("%lu\n", -42);
//    printf("%lu\n", -42);
//
//    ft_printf("%+u\n", 4294967295);
//    printf("%+u\n", 4294967295);
//
//    ft_printf("% u\n", 4294967295);
//    printf("% u\n", 4294967295);
//
//    printf("/*---------------------------- NEGATIVE --------------------------------*/\n");
//
//    printf("|f:-*.*, w:20, p:10, 444|%-*.*D\n", 20, 10, -444);
//    ft_printf("                        |%-*.*D\n", 20, 10, -444);
//
//
//    printf("|f:'-', w:10, p:20, 444|%-10.20d\n", -444);                                                // '-'
//    ft_printf("                        %-10.20d\n", -444);
//    printf("/*----------------------------------------------------------------------*/\n");
//
//    printf("|f:'+', w:10, p:20, 444|%+10.20d\n", -444);                                                //  '+'
//    ft_printf("                       |%+10.20d\n", -444);
//    printf("/*----------------------------------------------------------------------*/\n");
//
//    printf("|f:*.*, w:20, p:10, 444|%*.*d\n", 20, 10, -444);                                                                //   '*'
//    ft_printf("                       |%*.*d\n", 20, 10, -444);
//
//
//    printf("|f:-*.*, w:20, p:10, 444|%-*.*d\n", 20, 10, -444);
//    ft_printf("                        |%-*.*d\n", 20, 10, -444);
//
//
//    printf("3% -100.7d\n", 124141);
//    ft_printf("4% -100.7d\n", 124142);
//    printf("|f:-*., w:20, 444|% -*.d\n", 20, 444);
//    ft_printf("                 |% -*.d\n", 20, 444);
//    printf("%0100d\n", 0);
//    ft_printf("%0100d\n", 0);
//    printf("%20d\n", 0);
//    ft_printf("%20d\n", 0);
//
//    printf("1% 10.5d\n", 4242);                                        //
//    ft_printf("2% 10.5d\n", 4242);                                    //-> "     04242"
//    printf("% -100.7d\n", 124141);
//    ft_printf("% -100.7d\n", 124142);
//    ft_printf("\33[1;32m------------------- Check printf -------------------- \n");
//    ft_printf("%15.4d\n", 424242);
//    printf("%15.4d\n", 424242);
//    ft_printf("%+d\n", 0);
//    printf("%+d\n", 0);
//    printf("%zd\n", -0);
//    ft_printf("%zd\n", -0);
// //   ft_printf("%hhd\n", 128);
////    printf("%hhd\n", 128);
//    ft_printf("%hd\n", -32769);
//    printf("%hd\n", -32769);
//    ft_printf("%hd\n", 32768);
//    printf("%hd\n", 32768);
//    ft_printf("%03.2d\n", 0);
//    printf("%03.2d\n", 0);
//    ft_printf("%03.2d\n", 1);
//    printf("%03.2d\n", 1);
//    ft_printf("%03.2d\n", -1);
//    printf("%03.2d\n", -1);
//    ft_printf("%+10.5d\n", 4242);
//    printf("%+10.5d\n", 4242);
//    ft_printf("%4.15d\n", 42);
//    printf("%4.15d\n", 42);
//    ft_printf("%-5d\n", 42);
//    printf("%-5d\n", 42);
//    ft_printf("%05d\n", -42);
//    printf("%05d\n", -42);
//    ft_printf("%0+5d\n", 42);
//    printf("%0+5d\n", 42);
//    ft_printf("%-1.4d|\n", -5);
//    printf("%-1.4d|\n", -5);
//    ft_printf("%+d\n", 0);
//    printf("%+d\n", 0);
//    ft_printf("%5d\n", -42);
//    printf("%5d\n", -42);
//    ft_printf("%.d %.0d|\n", 0, 0);     // -> "@moulitest:  "
//    printf("%.d %.d|\n", 0, 0);
//    ft_printf("%5.d %5.0d|\n", 0, 0);    //-> "@moulitest:            "
//    printf("%5.d %5.0d|\n", 0, 0);
//    ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
//    printf("@moulitest: %5.o %5.0o|\n", 0, 0);
//    ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);
//    printf("@moulitest: %5.x %5.0x|\n", 0, 0);
//    ft_printf("%5.d|\n", 0, 0);
//    printf("%5.d|\n", 0, 0);
//    ft_printf("@moulitest: %.d %.0d\n", 42, 43);
//    printf("@moulitest: %.d %.0d\n", 42, 43);
//
//
//    printf("\33[1;32m------------------- Check printf -------------------- \n");
//    ft_printf("%+lld\n", 4242424242424242424);
//    printf("%+lld\n", 4242424242424242424);
//    printf("\33[1;32m----------------------- MY -------------------------- \n");
//    ft_printf("%d\n", 1);        // -> "1"
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//       printf("%d\n", 1);
//    printf("\33[1;32m----------------------- MY -------------------------- \n");
//
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//
//    printf("\33[1;32m----------------------- MY -------------------------- \n");
//
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
////  -> "1 is one"
//    printf("\33[1;32m----------------------- MY -------------------------- \n");
////  -> "4242"
// ft_printf("%d\n", 4242);
//    printf("%d\n", 4242);
// ft_printf("%d\n", 4242);
//    printf("%d\n", 4242);
// ft_printf("%d is one\n", 1);
//    printf("%d is one\n", 1);
// ft_printf("%d\n", -4242);                      // -> "-4242"
//    printf("%d\n", -4242);
//    ft_printf("%d\n", 2147483647);                 // -> "2147483647"
//    printf("%d\n", 2147483647);
//    ft_printf("%d\n", 2147483648);                 // -> "-2147483648"
//    printf("%d\n", 2147483648);
//    ft_printf("%d\n", -2147483648);                // -> "-2147483648"
//    printf("%d\n", -2147483648);
//    ft_printf("%d\n", -2147483649);                // -> "2147483647"
//    printf("%d\n", -2147483649);
//    ft_printf("% d\n", 42);                        // -> " 42"
//    printf("% d\n", 42);                        // -> " 42"
//    ft_printf("% d\n", -42);                       // -> "-42"
//    printf("% d\n", -42);
//    ft_printf("%+d\n", 42);                        // -> "+42"
//    printf("%+d\n", 42);
//    ft_printf("%+d\n", -42);                       // -> "-42"
//    printf("%+d\n", -42);
//    ft_printf("%+d\n", 0);                         // -> "+0"
//    printf("%+d\n", 0);
//
//
//    ft_printf("% +d\n", 42);                       // -> "+42"
//    printf("% +d\n", 42);
//    ft_printf("%d\n", -1);                         // -> "-1"
//    printf("%d\n", -1);
//    ft_printf("% +d\n", -42);                      // -> "-42"
//    printf("% +d\n", -42);
//    ft_printf("%+ d\n", 42);                       // -> "+42"
//    printf("%+ d\n", 42);
//    ft_printf("%+ d\n", -42);                      // -> "-42"
//    printf("%+ d\n", -42);
//    ft_printf("%  +d\n", 42);                      // -> "+42"
//    printf("%  +d\n", 42);
//    ft_printf("%  +d\n", -42);                     // -> "-42"
//    printf("%  +d\n", -42);
//    ft_printf("%+  d\n", 42);                      // -> "+42"
//    printf("%+  d\n", 42);
//    ft_printf("%+  d\n", -42);                     // -> "-42"
//    printf("%+  d\n", -42);
//    ft_printf("% ++d\n", 42);                      // -> "+42"
//    printf("% ++d\n", 42);
//    ft_printf("% ++d\n", -42);                     // -> "-42"
//    printf("% ++d\n", -42);
//    ft_printf("%++ d\n", 42);                      // -> "+42"
//    printf("%++ d\n", 42);
//    ft_printf("%++ d\n", -42);                     // -> "-42"
//    printf("%++ d\n", -42);
//    ft_printf("%0d\n", -42);                                //-> "-42"
//    printf("%0d\n", -42);
//
//    ft_printf("%0+5d\n", -42);
//    printf("%0+5d\n", -42);
//
//    ft_printf("%0d\n", -42);
//    printf("%0d\n", -42);
//
//    ft_printf("%00d\n", -42);
//    printf("%00d\n", -42);
//
//    ft_printf("%hhd\n", 128);
//    printf("%hhd\n", 128);
//
//    ft_printf("%hd\n", 32767);
//    printf("%hd\n", 32767);
//
//    ft_printf("%0+5d\n", 42);
//    printf("%0+5d\n", 42);
//
//    ft_printf("%00d\n", -42);                      // -> "-42"
//    printf("%00d\n", -42);
//    ft_printf("%5d\n", 42);                       //  -> "   42"
//    printf("%5d\n", 42);                       //  -> "   42"
//    ft_printf("%05d\n", 42);                      //  -> "00042"
//    printf("%05d\n", 42);                      //  -> "00042"
//    ft_printf("%0+5d\n", 42);                      // -> "+0042"
//    printf("%0+5d\n", 42);                            // -> "+0042"
//    130.      ft_printf("%5d", -42);                        -> "  -42"
//    131.      ft_printf("%05d", -42);                       -> "-0042"
//    132.      ft_printf("%0+5d", -42);                      -> "-0042"
//    133.      ft_printf("%-5d", 42);                        -> "42   "
//    134.      ft_printf("%-05d", 42);                       -> "42   "
//    135.      ft_printf("%-5d", -42);                       -> "-42  "
//    136.      ft_printf("%-05d", -42);                      -> "-42  "
//    137.      ft_printf("%hd", 32767);                      -> "32767"
//    138.      ft_printf("%hd", −32768);                   -> "0"
//    139.      ft_printf("%hd", 32768);                      -> "-32768"
//    140.      ft_printf("%hd", −32769);                   -> "0"
//    141.      ft_printf("%hhd", 127);                       -> "127"
//    142. FAIL ft_printf("%hhd", 128);                       -> "-128"
//    143.      ft_printf("%hhd", -128);                      -> "-128"
//    144. FAIL ft_printf("%hhd", -129);                      -> "127"
//    145.      ft_printf("%ld", 2147483647);                 -> "2147483647"
//    146.      ft_printf("%ld", -2147483648);                -> "-2147483648"
//    147.      ft_printf("%ld", 2147483648);                 -> "2147483648"
//    148.      ft_printf("%ld", -2147483649);                -> "-2147483649"
//    149.      ft_printf("%lld", 9223372036854775807);       -> "9223372036854775807"
//    150.      ft_printf("%lld", -9223372036854775808);      -> "-9223372036854775808"
//    151.      ft_printf("%jd", 9223372036854775807);        -> "9223372036854775807"
//    152.      ft_printf("%jd", -9223372036854775808);       -> "-9223372036854775808"
//    153.      ft_printf("%zd", 4294967295);                 -> "4294967295"
//    154.      ft_printf("%zd", 4294967296);                 -> "4294967296"
//    155.      ft_printf("%zd", -0);                         -> "0"
//    156.      ft_printf("%zd", -1);                         -> "-1"
//    157.      ft_printf("%d", 1);                           -> "1"
//          ft_printf("%d %d\n", 1, -2);                          // -> "1 -2"
//             printf("%d %d\n", 1, -2);
//          ft_printf("%d %d %d\n", 1, -2, 33);                    // -> "1 -2 33"
//             printf("%d %d %d\n", 1, -2, 33);
//          ft_printf("%d %d %d %d\n", 1, -2, 33, 42);            // -> "1 -2 33 42"
//             printf("%d %d %d %d\n", 1, -2, 33, 42);
//         ft_printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);   // -> "1 -2 33 42 gg!"
//            printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);
//    printf("1%4.15d\n", 42);                                                    //
//    ft_printf("2%4.15d\n", 42);                                                 //       -> "000000000000042"
//    printf("1%.2d\n", 4242);                                                   //
//    ft_printf("2%.2d\n", 4242);                                               // -> "4242"
//    printf("1%.10d\n", 4242);                                                //
//    ft_printf("2%.10d\n", 4242);                                            //      -> "0000004242"
//    printf("1%10.5d\n", 4242);                                             //
//    ft_printf("2%10.5d\n", 4242);                                         //   -> "     04242"
//    printf("%-10.5d\n", 4241);                                          //
//    ft_printf("%-10.5d\n", 4242);                                      //   -> "04242     "
//    printf("1% 10.5d\n", 4242);                                        //
//    ft_printf("2% 10.5d\n", 4242);                                    //-> "     04242"
//    printf("1%+10.5d\n", 4242);                                      //
//    ft_printf("2%+10.5d\n", 4242);                                  //-> "    +04242"
//    printf("1%-+10.5d\n", 4242);                                   //
//    ft_printf("2%-+10.5d\n", 4242);                               // -> "+04242    "
//    printf("1%03.2d\n", 0);                                      //
//    ft_printf("2%03.2d\n", 0);                                  //-> " 00"
//    printf("1%03.2d\n", 1);                                    //
//    ft_printf("2%03.2d\n", 1);                                // -> " 01"
//    printf("1%03.2d\n", -1);                                 //
//    ft_printf("2%03.2d\n", -1);                             //  -> "-01"
//    printf("1@moulitest: %.10d\n", -42);                   //
//    ft_printf("2@moulitest: %.10d\n", -42);               //-> "@moulitest: -0000000042"
//    printf("1@moulitest: %.10d\n", -42);                 //
//    ft_printf("2@moulitest: %.10d\n", -42);             //-> "@moulitest: -0000000042"
//    printf("1@moulitest: %.d %.0d\n", 42, 43);         //
//    ft_printf("2@moulitest: %.d %.0d\n", 42, 43);     // -> "@moulitest: 42 43"
//    printf("1@moulitest: %.d %.0d\n", 0, 0);         //
//    ft_printf("2@moulitest: %.d %.0d\n", 0, 0);     //  -> "@moulitest:  "
//    printf("1@moulitest: %5.d %5.0d\n", 0, 0);     //
//   ft_printf("2@moulitest: %5.d %5.0d\n", 0, 0);  // -> "@moulitest:            "
//
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//    printf("\n");
//    printf("%d\n", printf("%100.7d\n", 124141));
//    printf("%d\n",(ft_printf("%100.7d\n", 124142)));
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//
//    printf("%d\n", printf("%d   \n", 124141));
//    printf("%d\n", ft_printf("%d   \n", 124141));
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//    printf("%d\n", printf("%+100.7d\n", 124141));
//    printf("%d\n",(ft_printf("%+100.7d\n", 124142)));
//    printf("\33[0;31m--------------------- DEFAULT ----------------------- \n");
//
//    printf("%d\n",(printf("%d hello %d and %s\n", 124141, 10, "Shit")));
//    printf("%d\n",(ft_printf("%d hello %d and %s\n", 124141, 10, "Shit")));
//
//
//    printf("%d\n",(ft_printf("test\n")));
//
//
//
//    printf("1%-100.7d\n", 124141);
//    ft_printf("2%-100.7d\n", 124142);
//
//    printf("5%+-100.7d\n", 124141);
//    ft_printf("6%+-100.7d\n", 124142);
//    printf("7%+-100.7d\n", -124141);
//    ft_printf("8%+-100.7d\n", -124142);
//    printf("\n");
//
//
//    printf("%.20d\n", 37732);
//    ft_printf("%.20d\n", 37732);
//    printf("%20d\n", 37732);
//    ft_printf("%20d\n", 37732);
//    printf("%100.20d\n", 37732);
//    ft_printf("%100.20d\n", 37732);
//    printf("%0100d\n", 37732);
//    ft_printf("%0100d\n", 37732);
//    printf("\n");
////
//    printf("%.20d\n", 0);
//    ft_printf("%.20d\n", 0);
//    printf("%20d\n", 0);
//    ft_printf("%20d\n", 0);
//    printf("%100.20d\n", 0);
//    ft_printf("%100.20d\n", 0);
//    printf("%0100d\n", 0);
//    ft_printf("%0100d\n", 0);
//    printf("\n");
//
//
//
//
//    ft_printf("%20.15d\n", 54321);
//    printf("%20.15d\n", 54321);
//    ft_printf("%-10d\n", 3);
//    printf("%-10d\n", 3);
//    ft_printf("% d\n", 3);
//    printf("% d\n", 3);
//    ft_printf("%+d\n", 3);
//    printf("%+d\n", 3);
//    ft_printf("%010d\n", 1);
//    printf("%010d\n", 1);
//    ft_printf("%hhd\n", 0);
//    printf("%hhd\n", 0);
//    ft_printf("%jd\n", 9223372036854775807);
//    printf("%jd\n", 9223372036854775807);
//    ft_printf("%zd\n", 4294967295);
//    printf("%zd\n", 4294967295);
//    ft_printf("%\n");
//    printf("\n");


//    printf("/*--------------------------- POSITIVE ---------------------------------*/\n");
//    printf("|f:'-', w:10, p:20, 444|%-10.20d\n", 444);                                                // '-'
//    ft_printf("                       |%-10.20d\n", 444);
//    printf("/*----------------------------------------------------------------------*/\n");
//
//    printf("|f:'+', w:10, p:20, 444|%+10.20d\n", 444);                                                //  '+'
//    ft_printf("                       |%+10.20d\n", 444);
//    printf("/*----------------------------------------------------------------------*/\n");
//
//    printf("|f:*.*, w:20, p:10, 444|%*.*d\n", 20, 10, 444);                                           //   '*'
//    ft_printf("                       |%*.*d\n", 20, 10, 444);
//
//
//    printf("|f:-*.*, w:20, p:10, 444|%-*.*d\n", 20, 10, 444);
//    ft_printf("                        |%-*.*d\n", 20, 10, 444);
//
//
//    printf("|f:-.*, w:20, 444|%-.*d\n", 20, 444);
//    ft_printf("                 |%-.*d\n", 20,  444);
//
//    printf("|f:.*, w:20, 444|%.*d\n", 20, 444);
//    ft_printf("                |%.*d\n", 20,  444);
//
//
//    printf("|f:*., w:20, 444|%*.d\n", 20, 444);
//    ft_printf("                |%*.d\n", 20, 444);
//
//    printf("|f:*.*, w:10, p:20, 444|%*.*d\n", 10, 20, 444);
//    ft_printf("                       |%*.*d\n", 10, 20, 444);
//
//    printf("|w:20, p:10, 444|%20.10d\n", 444);
//    ft_printf("                |%20.10d\n", 444);
//
//    printf("|w: , p: '.', 0| |%.d\n", 0);
//    ft_printf("                 |%.d\n", 0);
//
//    ft_printf("%.d|\n", 0);
//    printf("%.d|\n", 0);

//
//    printf("|w:20, p:10, 444");
//    ft_printf("%20.10d", 444);
//    printf("        |original|");
//    printf("%20.10d\n", 444);
//
//    printf("|w:10, p:20, 444");
//    ft_printf("%10.20d", 444);
//    printf("        |original|");
//    printf("%10.20d\n", 444);
//
//
//    printf("|f: 'sp', 444");                    // 'sp'
//    ft_printf("% d", 444);
//    printf("                           |original|");
//    printf("% d\n", 444);
//
//    printf("|f:'sp,+' w:10, p:20, 444");
//    ft_printf("% 10.20d", 444);
//    printf("        |original|");
//    printf("% 10.20d\n", 444);
//
//    printf("|f:'sp,-' w:10, p:20, 444");
//    ft_printf("% -10.20d", 444);
//    printf("        |original|");
//    printf("% -10.20d\n", 444);
//
//
//    printf("|f:'0' w:10, 444");      //   'zero'
//    ft_printf("%+-010d", 444);
//    printf("                            |original|");
//    printf("%+-010d\n", 444);
//
//
//    printf("|w:10, p:10, 444");
//    ft_printf("%10.10d", 444);
//    printf("                 |original|");
//    printf("%10.10d\n", 444);
//
//    printf("|w:0, p:10, 444");
//    ft_printf("%.10d", 444);
//    printf("                  |original|");
//    printf("%.10d\n", 444);
//
//    printf("|w:10, p:0, 444");
//    ft_printf("%.10d", 444);
//    printf("                  |original|");
//    printf("%.10d\n", 444);
//
//    printf("|f:'-', w:10, p:0, 444");
//    ft_printf("%-.10d", 444);
//    printf("                    |original|");
//    printf("%-.10d\n", 444);
//
//
//
//
//


//
//
//    printf("/*----------------------------------------------------------------------*/\n");
//
//    printf("/*------------------------------- CHAR && UNICODE ----------------------*/\n");
//
//    setlocale(LC_ALL, "en_US.UTF-8");
//
//    printf("/*------------ connected support unicode character ---------------------*/\n");
//
//    printf("| 444 |%c\n", 444);
//    ft_printf("      |%c\n", 444);
//
//    printf("|f: w:10, 'H'|%10c\n", 'H');
//    ft_printf("             |%10c\n", 'H');
//
//
//    printf("|'H'|%c\n", 'H');
//    ft_printf("    |%c\n", 'H');
//
//    printf("|f: w:10, p:10 |%10.10c\n", 'H');
//    ft_printf("               |%10.10c\n", 'H');
//
//
//    printf("%-+010.2lc\n", L'ઓ');
//    ft_printf("%-+010.2C\n", L'ઓ');
//
//    int	or, mr;
//
//    ft_printf("MINE>\t[%+010.2c]\n", 'r');
//    or = printf("ORIG>\t[%+010.2c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//    ft_printf("MINE>\t[%c]\n", '"');
//    or = printf("ORIG>\t[%c]\n", '"');
//    //ft_print_result(mr, or, __LINE__);
//
//     ft_printf("MINE>\t[%+10c]\n", 'r');
//    or = printf("ORIG>\t[%+10c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//    ft_printf("MINE>\t[%-10c]\n", 'r');
//    or = printf("ORIG>\t[%-10c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//    ft_printf("MINE>\t[%010c]\n", 'r');
//    or = printf("ORIG>\t[%010c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//     ft_printf("MINE>\t[%+-10c]\n", 'r');
//    or = printf("ORIG>\t[%+-10c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//     ft_printf("MINE>\t[%0+10c]\n", 'r');
//    or = printf("ORIG>\t[%0+10c]\n", 'r');
//    //ft_print_result(mr, or, __LINE__);
//
//    printf("/*------------------------------- STRING ---------------------------------*/\n");
//

//    printf("%d\n",(printf("%+-010000.1000S  %S\n", L"㫴", L"㫴")));
//    printf("%d\n",(ft_printf("%+-010000.1000S  %S\n", L"㫴", L"㫴")));

//    printf("%d\n",(printf("%10s is a string", "this")));
//    printf("%d\n",(ft_printf("%10s is a string", "this")));

//    printf("%-12S\n", L"㫴");
//    printf("%-12S", L"㫴\n");
//    printf("%-12S\n", L"㫴");
//    printf("%-12S", L"㫴\n");
//    printf("%-12S", L"㫴\n");
//
//    ft_printf("%-12S\n", L"㫴");
//    ft_printf("%-12S", L"㫴\n");
//    ft_printf("%-12S\n", L"㫴");
//    ft_printf("%-12S", L"㫴\n");
//    ft_printf("%-12S\n", L"㫴\n");
//
//    ft_printf("%s", "abc");

//    ft_printf("%-+10.5d\n", 4242);                  //-> "+04242    "
//    printf("%-+10.5d\n", 4242);
//
//    printf("%d\n", ft_printf("% d\n", 42));
//    printf("%d\n",printf("% d\n", 42));
//
//    ft_printf("% d\n", -42);
//    printf("% d\n", -42);
//
//
//    ft_printf("% +d\n", 42);
//    printf("% +d\n", 42);
//
//    ft_printf("%jd\n", -9223372036854775808);
//    printf("%jd\n", -9223372036854775808);
//    ft_printf("% 10.5d\n", 4242);
//    printf("% 10.5d\n", 4242);
//    printf("% 10.5d\n", 4242);                  // -> "     04242"
//    ft_printf("%d\n", -8);
//    printf("%d\n", -8);
//

//    ft_printf("%-10.5d\n", 4242);
//    printf("%-10.5d\n", 4242);
//
//    ft_printf("%jd\n", -9223372036854775808);      // -> "-9223372036854775808"
//    printf("%jd\n", -9223372036854775808);
//
//
//    printf("%d\n", ft_printf("%d\n", -1));
//    printf("%d\n", printf("%d\n", -1));
//
//
//
//

    return (1);
}


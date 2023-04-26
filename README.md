# 0x11. C - printf


This is a TEAM Project done during **Full Stack Software Engineering studies** at **ALX School**. It aims to learn about What are macros and how to use them, What are the most common predefined macros & How to include guard in your header files in **C language**.

## Technologies
* C files are compiled using `gcc 4.8.4`
* C files are written according to the C90 standard
* Tested on Ubuntu 14.04 LTS
* Team Member: Lawrence Maduabuchi & Abdullahi Ngui.
* Date: April 21st 2023




## Files
All of the following files are programs written in C:

| Filename | Description |
| -------- | ----------- |
| ` binary_fill.c` | Printf function.|
| ` ev_print_func.c` | Prints a char.|
| ` fill_hex_array.c` | Prints an unsigned number|
| ` fill_oct_array.c` | Prints the value of a pointer variable|
| ` get_print_func.c` | Write a function calculate active flags.|
| ` handle_buff.c ` | Calculates the precision for printing |
| ` long_oct_array.c` | Calculates the size to cast the argument |
| ` print_add.c` | Calculates the width for printing |
| ` print_bnr.c` | Prints an argument based on its type |
| ` main.h` | source file for all executable prototypes for program|
| ` print_buf.c` | A function that evaluates if a char is printable|
| ` print_chr.c` | A function that explicitly prints a string |


## Tasks
All of the following files are programs written in C:

| Task | Question |
| -------- | ----------- |
| ` 0. I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life
| Write a function that produces output according to a format.| Prototype: int _printf(const char *format, ...); Returns: the number of characters printed (excluding the null byte used to end output to strings)
| ` 1. Education is when you read the fine print. Experience is what you get if you don't| Handle the following conversion specifiers: d , i.| You don’t have to handle the flag characters
| ` 2. With a face like mine, I do better in print
| Handle the following custom conversion specifiers: b|the unsigned int argument is converted to binary
| ` 3. What one has not experienced, one will never understand in print| Handle the following conversion specifiers: u, o, x, X|You don’t have to handle field width
| ` 4. Nothing in fine print is ever good news
| Use a local buffer of 1024 chars in order to call write as little as possible. |
| ` 5. My weakness is wearing too much leopard print| Handle the following custom conversion specifier: s – prints the string| Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)| ` 6. How is the world ruled and led to war? Diplomats lie to journalists and believe these lies when they see them in print| Handle the following conversion specifier: p|You don’t have to handle precision
| ` 7. The big print gives and the small print takes away
| Handle the following flag characters for non-custom conversion specifiers: +, space, #|
| ` 8. Sarcasm is lost in print
| Handle the following length modifiers for non-custom conversion specifiers: I, h|Conversion specifiers to handle: d, i, u, o, x, X
| ` 9. Print some money and give it to us for the rain forests
| Handle the field width for non-custom conversion specifiers.|
| ` 10. The negative is the equivalent of the composer's score, and the print the performance
| Handle the precision for non-custom conversion specifiers.|
| ` 11. It's depressing when you're still around and your albums are out of print
| Handle the 0 flag character for non-custom conversion specifiers.|

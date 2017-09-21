/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * John Stibbards 105071781
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  /*
  The hex number 0x55 marks each even numbered bit as 1
  however this must be extended to the remaining 24 bits,
  shifting left and using or accomplishes this
  */
  int x = 0x55;
  int word = x | x << 8;
  word = word | word << 16;
  word = word | word << 24;
  return word;
}
/* 
 * minusOne - return a value of -1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
  /*
  minus one is represented by a full set of 1s, or 0xffffffff
  this can also be accomplished by returning the compliment of 0x00
  */
  int x = 0x00;
  return ~x; 
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
  /*
  the first mask shows us the first bit, aka the least significant bit
  using the bang operation makes the number so it can be added to the complimment of 0x00
  this will give us the output of 1 or 0
  */
  int mask;
  int mask2;
  mask = 0x01;
  x = !(x & mask);
  mask2 = 0x0; 
  x = x + ~mask2;
  return x;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /*
  the operation of (1 << n) - 1 is used to round towards 0 for negative numbers
  this function achieves this by adding a string of 1s to the number
  1 power less than we will be dividing by &ing this with a mask of the sign
  of the number makes sure this is only applied to negatives
  */
  int mask;
  mask = (1 << n) + ~(0x00); 
  mask = mask & (x >> 31);
  x = (x + mask) >> n;
  return x;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /*
  the value of n << 3 is equivalent to n*8 which converts the byte number to the number of bits that must be shifted
  the number is then right shifted so the desired byte is now the least significant byte
  we then mask extraneous values in other byte locations for the answer
  */
	int mask = 0xff;
  x = x >> (n << 3);
  x = x & mask;
  return x;
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
  /*
  the hex value aa marks odd numbered bits as 1,
  the shift and or operations extend this feature to all 4 bytes
  the and operation then sets it so that only odd numbered bits can be numbered
  if any odd numbered bits are 1, the two bang operations will set the output to 1
  */
   int mask = 0xaa;
   int mask2 = mask | mask << 8;
   mask2 = mask2 | mask2 << 16;
   x = !(x & mask2);
   return !x;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
  /*
  using a right shift by 31 operation on the given value results in two possibilities
  if the number was negative we will have a string of 1s, or a string of 0s if it was positive
  masking the number 0x01 on this will result in 1 if negative or 0 if positive
  */
  int mask;
    x = x >> 31;
    mask = 0x01;
    x = x & mask;
    return x; 
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*
  using two numbers, one of which overflows when added to the upper bound of ASCII codes
  and one which overflows when added only to number less than the lower bound,
  adding both of these to the input number should yield one that overflows and one that does not
  if the provided number is in the ACII digit range
  */
  int upperBound;
  int lowerBound;
  int checkUpperBound;
  int checkLowerBound;
  upperBound = ~0x39 + 1;
  lowerBound = ~0x30 + ~0x00;
  checkUpperBound = !!(upperBound + x);
  checkLowerBound = !!(lowerBound + x);

  return !!((!checkLowerBound) & checkUpperBound);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int fitsBits(int x, int n) {
  /*
  shifting the number right by 31 acquires the sign of the number
  shifting the number right by the bit number minus one acquires the most significant bit
  when these are xor'ed the resulting number will be 0 if the number fit in the given number of bits
  */
    int mask;
    mask = x >> 31;
    x = x >> (n + ~0x00);
    x = x ^ mask;
    return !(x);
    }
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  /*
  in order for a subtraction operation to overflow, the provided numbers (x and y)
  must have different signs, the result of one plus the twos compliment of the other 
  must also have a different sign from the given number x
  using a 31 bit shift to take only the sign of the number and comparing using xor
  the function returns if both of these requirements were true
  */
    int signX;
    int signY;
    int sameSign;
    int newVal;
    signX = x >> 31;
    signY = y >> 31;
    sameSign = signX ^ signY;
    newVal = x + (~y + 1);
    newVal = newVal >> 31;
    signX = signX ^ newVal;
    return !(signX & sameSign);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
  the compliment of the double bang of x plus 1 will be a string of 1s for numbers and a string of 0s for 0
  this allows us to use an or statement and anding the two possible outputs with x and ~x
  such that y is the result if the original x was a number and z if it was 0
  */
    x = ~(!!x) + 1;
    x = (x & y) | (~x & z);
    return x; 
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* 
  for this problem, the first step was to take the compliment of the number if it was negative
  in twos compliment the compliment of a negative number requires the same number of bits to be represented
  using an xor with the original number and the sign protects positive number inputs
  the next step is to set every bit right of the most significant bit to 1
  this allows us to divide and conquor approach to add together the amount of 1s in the number
  */
    int mask1;
    int mask2;
    int mask4;
    int mask8;
    int mask16;
    int shiftNum;

    x = (x >> 31) ^ x;

    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);

    mask1 = 0x55;
    mask1 = mask1 | (mask1 << 8);
    mask1 = mask1 | (mask1 << 16);
    mask2 = 0x33;
    mask2 = mask2 | (mask2 << 8);
    mask2 = mask2 | (mask2 << 16);
    mask4 = 0x0f;
    mask4 = mask4 | (mask4 << 8);
    mask4 = mask4 | (mask4 << 16);
    mask8 = 0xff;
    mask8 = mask8 | (mask8 << 16);
    mask16 = 0xff;
    mask16 = mask16 | (mask16 << 8);

    shiftNum = x >> 1;
    x = (x & mask1) + (shiftNum & mask1);
    shiftNum = x >> 2;
    x = (x & mask2) + (shiftNum & mask2);
    shiftNum = x >> 4;
    x = (x & mask4) + (shiftNum & mask4);
    shiftNum = x >> 8;
    x = (x & mask8) + (shiftNum & mask8);
    shiftNum = x >> 16;
    x = (x & mask16) + (shiftNum & mask16);

    x = x + 1;
    return x;
}
/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
  /*
  the operation of oring x with the compliment of x plus one ensures if we have
  a nonzero, the sign (most significant bit) will always be 1, and always 0 if the
  original number was zero we can then take the sign with a 31 bit right shift and
  mask off everything but the least significant pit to return a simple 1 or 0
  */
  int mask;
  x = x | (~x + 1);
  x = x >> 31;
  mask = 0x01;
  x = x & mask;
  return x;
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /*
  the absolute value of a positive number is itself
  the absolute value of a negative number in twos compliment is the compliment of the number +1
  using the sign as a mask and using the compliment allows us to use conditional logic
  to use only either the original number or its twos compliment, based on if it
  was originally positive or negative
  */
  int signX;
  signX = x >> 31;
  x = (~signX & x) | (signX & (~x + 1));
  return x;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  /*
  a property of numbers that are evenly divisble by powers of two is that they will always
  be a 1 followed by a string of 0s. therefore, if you and the number with the number minus one
  if it was originally a power of two the string of 0s well become all 1s, and the and function will result in 
  a string of only 0s. We also add caviats to make sure negative numbers and 0s cannot return true
  */
  int mask;
  int newVal;
  mask = x >> 31;
  newVal = x & (~mask);
  newVal = x & (x + ~0x00);
  return !(newVal | mask | !x);
}

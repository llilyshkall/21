
# S21 DECIMAL

This project implements the s21_decimal.h library in the C programming language for ``School 21`` in Moscow.

The project implements full coverage of library functions code with unit-tests using the Check library. The gcov_report target (a part of Makefile) generates a gcov report in the form of an html page: <a href="/gcov_report/gcov_report.html">GCOVR report</a>.

## The crew

* *Roma* a.k.a **pumpkin** a.k.a <a href="https://github.com/kireevroi">coriemis</a>
* *Ilysha* a.k.a <a href="https://github.com/llilyshkall">chatayap</a>
* *Polina* a.k.a **polza** a.k.a <a href="https://github.com/cormacsi">cormacsi</a>
* *Andrey* a.k.a **4erepaxa** a.k.a <a href="https://github.com/4epenaxa">jhinelia</a>

### The decimal type
The Decimal value type represents decimal numbers ranging from positive 79,228,162,514,264,337,593,543,950,335 to negative 79,228,162,514,264,337,593,543,950,335. The default value of a Decimal is 0.

The binary representation of a Decimal value consists of a 1-bit sign, a 96-bit integer number, and a scaling factor used to divide the 96-bit integer and specify what portion of it is a decimal fraction. The scaling factor is implicitly the number 10, raised to an exponent ranging from 0 to 28.


Decimal number can be implemented as a four-element array of 32-bit signed integers (`int bits[4];`).

`bits[0]`, `bits[1]`, and `bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer number accordingly.

`bits[3]` contains the scale factor and sign, and consists of following parts:
- Bits 0 to 15, the lower word, are unused and must be zero.
- Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the power of 10 to divide the integer number.
- Bits 24 to 30 are unused and must be zero.
- Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative.


```c
typedef struct 
{
    int bits[4];
} s21_decimal;
```

![Parrot](https://media.tenor.com/3_mXIoBPNhoAAAAi/party-parrot.gif)

### By 69 TEAM

<br>
<a href="https://kireevroman.com/donate">$ DONATE TO OUR TEAM</a>


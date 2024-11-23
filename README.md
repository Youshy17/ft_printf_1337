if (str[i] == '%')
{
	conversions : c s p d i u x X %
	precesions : - 0 . # (space) +
}

// - 0 . # space +


- left alignment :
	applies for c s p d i u x X %
	Left-aligns the output within the specified field width.

0 Zero padding :
	applies to d i u x X %
	Pads the output with zeros instead of spaces.

. Precision :
	applies for d i u x X
	Sets the minimum number of digits. Pads with leading zeros if necessary.
	applies for s
	Limits the maximum number of characters to display from the string.


# Alternative form :
	applies for x X
	Adds a prefix:
	0x for lowercase hexadecimal (x).
    0X for uppercase hexadecimal (X).

+ Force sign :
	applies for d i
	Forces the sign to always appear (+ or -).

  Space :
	applies for d i
	Adds a leading space for positive numbers (if + is not used).
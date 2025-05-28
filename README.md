This repository provides a complete set of functions for computing statistical and signal features from numerical arrays. These functions are implemented in C and have been mathematically validated.

Features
--------------------

The following statistical features are available:

1. Maximum Value
2. Minimum Value
3. Mean (Average)
4. Standard Deviation
5. Skewness
6. Kurtosis
7. Root Mean Square (RMS) across three arrays
8. Zero Crossing Count
9. Signal Energy
10. Peak-to-Peak Value
11. Peak-to-RMS Ratio
12. Root Sum of Squares (RSSQ)

Each feature is implemented in C and compared against validated mathematical definitions.

Sample Arrays Used for Validation
------------------------------

The following arrays were used to test and validate all functions:

Main input array:
  x[] = {3, -2, 7, 5, -1, 0, 4, -3}

Arrays used for RMS calculation:
  a[] = {3, -2, 7, 5, -1, 0, 4, -3}
  b[] = {1, 0, -4, 6, 2, -1, 5, -2}
  c[] = {-2, 3, 2, -5, 0, 4, 1, -1}

----------------------

A PDF document is included in the repository that contains all the mathematical formulas for the implemented features.

Please refer to "Mathematical_Formulas_for_C_Functions.pdf" for a complete breakdown of each formula.

Files Included
--------------
- C and header files for the statistical features functions.
- Mathematical_Formulas_for_C_Functions.pdf: PDF with formula definitions.
- README.txt: Project description and usage guide (this file).

Contributions
-------------

Pull requests and new feature suggestions to be added are welcome.

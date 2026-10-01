# The15Game
Rule:

     Align exponents first, then add the coefficients.

Steps:

    Compare the powers of 10 (exponents) for both numbers
    Shift the smaller number’s coefficient to match the larger exponent
    Add the coefficients
    Keep the exponent the same

Please follow best practices and develop and thoroughly test a C++ class named CookieNotation that has the following functional characteristics:


Member Variables

    Coefficient stores the significant part of the number
    Exponent stores the power of ten for the number


Member Functions 

    Default constructor which initializes the object to represent zero
    Parameterized constructor which takes a coefficient and an exponent as parameters
    Develop only one constructor that can do both default and parameterized functionality
    Copy constructor
    Copy assignment operator
    getCoefficient() and getExponent() functions
    setCoefficient() and setExponent() functions
    + operator to add two CookieNotation objects together
    << operator to print the number cleanly
    Any helper functions needed to align exponents for addition or anything else


Make sure you break up the CookieNotation class into its header and implementation files.  Set up a second implementation file that tests the CookieNotation class functionality you just developed.  Demonstrate proper and correct usage of all above functionality.

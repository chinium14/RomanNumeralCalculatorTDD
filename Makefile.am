AUTOMAKE_OPTIONS = subdir-objects
TESTS = RomanCheck
#RomanNumeralCalculatordir = /Users/Shuai/Documents/RomanNumeralCalculatorTDD/lib
#RomanNumeralCalculator_LTLIBRARIES= libRomanNumeralCalculator.la
#libRomanNumeralCalculator_la_SOURCES = \
 #       src/roman.h
check_PROGRAMS = RomanCheck
RomanCheck_SOURCES = \
	test/test_main.c \
        src/roman.h src/roman.c
RomanCheck_CFLAGS = @CHECK_CFLAGS@
RomanCheck_LDADD = @CHECK_LIBS@

#bin_PROGRAMS = RomanNumeralCalculator
#RomanNumeralCalculator_SOURCES = \
#	test/test_main.c \
#        src/roman.h
ACLOCAL_AMFLAGS = -I m4

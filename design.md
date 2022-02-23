# Design

At the top level are 6 programs: test-system, check-dependencies, grade-distro,
grade-apps, csv2pivot, and view-report. This will describe what each one does.


test-system
-----------
This drives the whole test. This is the program that you should run to
get results. It will run all the other programs for you.


check-dependencies
------------------
This program will let you know if you have installed all of the components
that the test suite will need to collect info about the Linux distribution.


grade-distro
------------
This program will do distribution level mitigation checks. It checks for kernel
features such as sysctls, testing aslr bits, compiler safety features, and if
there is a seccomp library.

It does this by calling bin/check-distro. This program in turn calls 
bin/distro-features/check-baseline and bin/distro-features/score-baseline.i The
first program descends into bin/distro-features and calls programs in each of
the subdirectories. Each of the programs check the availability of different
safety features of the operating system. At the end of testing, it creates a
distro-rollup csv, distro-base-score.txt, and distro-raw-report.txt in the
data/distro directory.


grade-apps
----------
The grade-apps program will check the currently installed applications for
security properties and risks. It does this by calling bin/check-apps. The
check-apps program creates various lists and the iterates over each package
and checking each file. At the moment, it only cares about ELF files. For each
file it enters the bin/app-grading directory and runs a series of tests on the
file. These all get concatenated into a file in data/distro that is for each
package.

After inspecting all packages, it creates a app-rollup csv file in the
data/distro directory.


csv2pivot
---------
This program takes the csv data collected up by grade-apps and turns it into
a html based pivottable.


view-report
-----------
This program finds the pivottable and displays it in firefox.


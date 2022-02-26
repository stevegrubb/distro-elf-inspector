# distro-elf-inspector
This project provides a set of utilities to scan an rpm based Linux distribution to collect artifacts in the ELF files. This information is collected up in a pivottable for easy inspection. It also creates a CSV file which custom reports can be programmed for.

BUILDING
--------
Nothing to build. Run it directly from the repo directory.

USAGE
-----
```
1) edit ./conf and set distribution (and arch if different)
2) run ./test-system (install dependencies if missing)
3) ./view-report
4) cat data/$release/distro-raw-report.txt
```

Note: if you build and install the [tasker](https://github.com/stevegrubb/tasker) program, scanning the system can be parallelized.

USING THE PIVOTTABLE
--------------------
The pivottable is interactive. There are a colums of boxes on the left when the html page opens. You can drag the boxes to the empty gray box just to right to get the contents to display. You can place another box below that one to get it's output grouped by the box above it. For example, drag the package box to the gray area, then drag the files box to the gray area. Now you should see files grouped by packages.

The boxes are also a drop down selector. Click on the down arrow to get the contents to open up. You can check or uncheck categories to modify your results. For example, if you open the PIE dropdown, uncheck everything but "no", then click apply. Now you should see the files that do not have PIE or PIC flags given to the compiler at build time. Once you click apply, notice that the label of the box changes to itallics text. This is how you know which boxes have been modified to not include all categories. To restore it, open the drop down and check all boxes and click apply.

The pivottable works best when you have a minimal system with 600 or 700 packages. It is possible to scan and look at systems with a large number of packages installed. But the drop downs will start saying too many to display in some cases. For large systems, you may want to create queries using R or python's pandas module to use the app-rollup.csv file directly.

FIELDS
------
**FILE** - The full path of the ELF file.

**PACKAGE** - The name of the package that owns the file.

**SOURCE_RPM** - The name of the source package that file was compiled from.

**CLASS** - The classification of the file. It is one of: daemon, exec, library, media-app, network-local, setcap, setgid, setuid

**MIME_TYPE** - The mime type of the file. Being that this is an ELF scanner, all types are an ELF mime type. It is one of : application/x-bad-elf, application/x-executable, application/x-object, application/x-sharedlib

**EXECSTACK** - This is looking for a plain STACK or GNU_HEAP in the program headers.

**PIE** - This is yes, no, DSO, or n/q based on if the program is compiled with the -fpie flag. Shared objects are typically compiled with a -fPIC flag. If so it is labeled as DSO. There are object files and static applications shipped in the distribution. These get the n/a label.

**RELRO** - This is either full, no, or partial. RELRO means RELocations are ReadOnly.

**STACK_PROTECTOR** - This is either missing or ok.

**FORTIFY_SOURCE** - This is either missing or ok.

**CET** - This is either missing or ok. CET is Control-flow Enforcement Technology. This is the -fcf-protection flag to gcc.

**STACK_CLASH** - This is either missing or ok. This is the -fstack-clash-protection flag to gcc.

**RWX_SEGMENT** - This is either bad or ok. Bad meaning that there is a segment of memory marked with all access flags.

**UNEXPECTED_INTERP** - This looks at the elf interpreter in the program headers and compares that to a known list of interpreters to see which one is used to link the runtime libraries. The values are bad-interp or ok.

**HAS_RPATH** - This looks to see if the program/library has either an rpath or runpath field. The values are none or rpath.

**LINES_OF_CODE** - This is a count of lines of assembler in the text segment. It stands in as a rough order of magnitude indicator.

**LINK_FAN_IN** - This is a count of how many libraries are linked to the application or library. This may point to complexity.

**EXTERN_FUNCS** - This is a count of how many external functions the file uses. This may point to complexity.

**FILE_WRITABLE** - This is a check of whether the file is group or world writable. The values are writable or ok.

**CHGRPS_ISSUE** - This looks to see if supplemental groups are updated in addition to changing the group id. The values are: n/a, no, yes.

**USES_DEPRECATED_FUNCS** - This looks to see if it uses glibc functions documented in man pages to be deprecated. The functions looked for include: bcopy, bcmp, gets, getwd, mktemp, tmpnam, rindex, index, getpass, getpw, valloc, rand, and vfork. The output is a count of how many it found. 0 means it's clean.

**USES_CERT_UNSAFE_FUNCS** - This looks to see if it uses functions recommended by CERT MSC24-C as unsafe to use. The functions looked for include: access, faccessat, system, popen, rand, gets, sprintf, strcpy, scanf, getchar, atof, atoi, atol, atoll, rewind, setbuf, and ctime. The output is a count of how many it found. 0 means it's clean.

**USES_UNSAFE_STRING_FUNCS** - This looks to see if it uses unsafe string functions. The functions looked for include: strcpy, strcat, sprintf, and vsprintf. The output is a count of how many it found. 0 means it's clean.

**USES_PARSING_FUNCS** - This looks to see if it uses functions known to be used in parsers. The functions looked for include: strtok, strtok_r, scanf, sscanf, and fscanf. The output is a count of how many it found. 0 means it's clean.

**USES_SHELL_EXECUTION** - This looks to see if it uses execution functions that uses a shell environment. The functions looked for include: system and popen. The output is a count of how many it found. 0 means it's clean.

**USES_IPV4_ONLY_FUNCS** - This looks to see if it uses functions known to be IPv4 only. This spots legacy networking applications. The functions looked for include: gethostbyname, gethostbyname2, getservbyname, gethostbyaddr, getservbyport, inet_addr, inet_aton, inet_nsap_add, inet_ntoa, inet_nsap_ntoa, inet_makeaddr, inet_netof, inet_network, inet_neta, inet_net_ntop, inet_net_pton, rcmd, rexec, and rresvport. The output is a count of how many it found. 0 means it's clean.

**PROG_LANGUAGE** - This tries to detect the language the program was written in by looking for functions uniq to a specific programming language. The langauges it current detects are: C, C++, OCaml, GHC, Fortran, go, and rust.

**USES_SECCOMP** - This looks to see if it uses any seccomp functions. The values are no and yes.

**USES_CAPABILITIES** - This looks to see if functions associated with manipulating posix capabilities are used. The values are no and yes.

**CHANGES_UID** - This looks to see if functions associated with changing the uid are used. The values are no and yes.

**USES_CHROOT** - This looks to see if the chroot system call is used. The values are no and yes.

**USES_DLOPEN** - This looks to see if the dlopen function is used. The values are no and yes.

SCREENSHOT
----------

### Pivot Table

 ![pivot table](https://github.com/stevegrubb/distro-elf-inspector/blob/1d89add7d7cc29e9f8ec54f33d45ca95a6d50d34/pivottable-screenshot.png?raw=true)

SCRIPTING
---------
When the data is large, it's easier to write some scripts in R or Python + Pandas to look for interesting insights. Suppose you wanted to review a table of PIE vs RELRO to see if the distribution is compiled right. (You want full RELRO when anything is PIE.) You could run this script in R:

```
df <- read.csv(file = "app-rollup.csv", header = TRUE)
xt <- xtabs(~ PIE + RELRO, data=df)
print(xt[c(3,1,4),c(2,3,1)])

     RELRO
PIE     no partial full
  no   129     170    9
  DSO  319     614 8620
  yes    0      23 4209
```


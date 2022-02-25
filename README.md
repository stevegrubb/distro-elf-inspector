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

USING THE PIVOTTABLE
--------------------
TBD

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

**CET** - This is either missing or ok.

**STACK_CLASH** - This is either missing or ok.

**RWX_SEGMENT** - This is either bad or ok. Bad meaning that there is a segment of memory marked with all access flags.

**UNEXPECTED_INTERP** - This looks at the elf interpreter in the program headers and compares that to a known list of interpreters to see which one is used to link the runtime libraries. The values are bad-interp or ok.

**HAS_RPATH** - This looks to see if the program/library has either an rpath or runpath field. The values are none or rpath.

**LINES_OF_CODE** - This is a count of lines of assembler in the text segmnent.

**LINK_FAN_IN** - This is a count of how many libraries are linked to the application or library.

**EXTERN_FUNCS** - This is a count of how many external functions the file links to.

**FILE_WRITABLE** - This is a check or whether the file is group or world writable. The values are writable or ok.

**CHGRPS_ISSUE** - 

**USES_DEPRECATED_FUNCS** - 

**USES_CERT_UNSAFE_FUNCS** - 

**USES_UNSAFE_STRING_FUNCS** - 

**USES_PARSING_FUNCS** - 

**USES_SHELL_EXECUTION** - 

**USES_IPV4_ONLY_FUNCS** - 

**PROG_LANGUAGE** - 

**USES_SECCOMP** - 

**USES_CAPABILITIES** - 

**CHANGES_UID** - 

**USES_CHROOT** - 

**USES_DLOPEN** - 


# distro-elf-inspector
This project provides a set of utilities to scan an rpm based Linux distribution installed on a system to collect various information about the ELF files. This information is collected up in a pivottable for ease of use.


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

FIELDS
------
**FILE**
**PACKAGE**
**SOURCE_RPM**
**CLASS**
**MIME_TYPE**
**EXECSTACK**
**PIE,RELRO**
**STACK_PROTECTOR**
**FORTIFY_SOURCE**
**CET**
**STACK_CLASH**
**RWX_SEGMENT**
**UNEXPECTED_INTERP**
**HAS_RPATH**
**LINES_OF_CODE**
**LINK_FAN_IN**
**EXTERN_FUNCS**
**FILE_WRITABLE**
**CHGRPS_ISSUE**
**USES_DEPRECATED_FUNCS**
**USES_CERT_UNSAFE_FUNCS**
**USES_UNSAFE_STRING_FUNCS**
**USES_PARSING_FUNCS**
**USES_SHELL_EXECUTION**
**USES_IPV4_ONLY_FUNCS**
**PROG_LANGUAGE**
**USES_SECCOMP**
**USES_CAPABILITIES**
**CHANGES_UID**
**USES_CHROOT**
**USES_DLOPEN**


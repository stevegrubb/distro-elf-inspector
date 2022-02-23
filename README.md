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


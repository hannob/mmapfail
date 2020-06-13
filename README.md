# mmapfail
Bash script to detect bad checks of mmap() return value

# what?

The mmap() POSIX function returns MAP_FAILED or -1 when an error occurs.
A common mistake is to check the return value for 0 instead. This script
tries to heuristically find such bugs in an automated way.

# findings

* efivar: https://github.com/rhboot/efivar/pull/152
* GNOME/gvfs: https://gitlab.gnome.org/GNOME/gvfs/-/issues/477
* Geeqie: https://github.com/BestImageViewer/geeqie/pull/771
* ZoneDetect: https://github.com/BertoldVdb/ZoneDetect/pull/26
* GDB: https://sourceware.org/bugzilla/show_bug.cgi?id=26016
* GNOME/gdk-pixbuf: https://gitlab.gnome.org/GNOME/gdk-pixbuf/-/issues/158
* KDE/kwayland: https://bugs.kde.org/show_bug.cgi?id=421868
* Mesa: https://gitlab.freedesktop.org/mesa/mesa/-/merge_requests/5150
* QEMU: https://bugs.launchpad.net/qemu/+bug/1879998
* GNOME/Tracker: https://gitlab.gnome.org/GNOME/tracker-miners/-/merge_requests/201

Article (in German):
* [Golem.de: mmap - Codeanalyse mit sechs Zeilen Bash](https://www.golem.de/news/mmap-codeanalyse-mit-sechs-zeilen-bash-2006-148878.html)

# Cppcheck

Cppcheck is capable of detecting bad checks of mmap() return values as well, 
but it must be prepared for it first by compiling from source code with HAVE_RULES=yes. 
This option enables an optional "rules"-feature for command line version of Cppcheck. 
Installation instructions for this feature are available 
[here](https://github.com/danmar/cppcheck/blob/master/build-pcre.txt).

Then Cppcheck can be called with a rule-file to detected bad checks of mmap:
```
$ cppcheck --enable=all --rule-file=cppcheck/mmap.xml --template=cppcheck1 test/
Checking test/bad 2.c ...
[test/bad 2.c:14]: (warning) mmap returns 'MAP_FAILED (=-1)' in case of an error. Checking against '0' is wrong.
1/3 files checked 33% done
Checking test/bad.c ...
[test/bad.c:14]: (warning) mmap returns 'MAP_FAILED (=-1)' in case of an error. Checking against '0' is wrong.
2/3 files checked 66% done
Checking test/good.c ...
3/3 files checked 100% done
: (information) Cppcheck cannot find all the include files (use --check-config for details)
```

- Findings:
  Skiboot: https://github.com/open-power/skiboot/pull/255

 
An articles about writing rules is available: [1](https://sourceforge.net/projects/cppcheck/files/Articles/writing-rules-1.pdf/download), [2](https://sourceforge.net/projects/cppcheck/files/Articles/writing-rules-2.pdf/download)


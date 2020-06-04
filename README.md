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

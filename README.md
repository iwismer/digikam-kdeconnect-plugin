# DigiKam KDE Connect Plugin

This is a simple plugin that allows sharing photos to other devices through KDE Connect.

This was based on the demo plugins found here: <https://github.com/cgilles/digikam-plugins-demo>

# Motivation

I often find I want to send individual photos to my phone for posting to social
media, or to send to a friend. This was a bit of a convoluded task before, as I
had to right click the image, open it in the file manager, then right click it
in the file manager and send it via KDE connect.

# Known issues

- This will probably horribly break if you don't have KDE connect installed
- Not at all tested on anything except Linux

# Building
## Dependencies:

- CMake           >= 3.1.0      (https://cmake.org/)
- Qt              >= 5.6.0      (https://www.qt.io/)
- DigikamCore     >= 7.0.0      (https://www.digikam.org)
- KDE Connect     (Runtime dependency only)

Notes:

- plugins do not depend on KF5 framework.

## Compilation:

```
# ./bootstrap.sh
# cd build
# make
```

## Install:

```
# cd build
# sudo make install/fast
```

## Uninstall:

```
# cd build
# sudo make uninstall
```

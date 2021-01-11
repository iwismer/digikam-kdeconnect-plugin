# DigiKam KDE Connect Plugin

This is a simple plugin that allows sharing photos to other devices through KDE Connect.

This was based on the demo plugins found here: <https://github.com/cgilles/digikam-plugins-demo>

# Building
## Dependencies:

- CMake           >= 3.1.0      (https://cmake.org/)            All plugin types
- Qt              >= 5.6.0      (https://www.qt.io/)            All plugin types
- DigikamCore     >= 7.0.0      (https://www.digikam.org)       Generic, Editor, and RawImport plugins
- DigikamDatabase >= 7.0.0      (https://www.digikam.org)       BQM plugin only
- DigikamGui      >= 7.0.0      (https://www.digikam.org)       BQM plugin only

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


Debian
====================
This directory contains files used to package polarisnetworkd/polarisnetwork-qt
for Debian-based Linux systems. If you compile polarisnetworkd/polarisnetwork-qt yourself, there are some useful files here.

## polarisnetwork: URI support ##


polarisnetwork-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install polarisnetwork-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your polarisnetwork-qt binary to `/usr/bin`
and the `../../share/pixmaps/polarisnetwork128.png` to `/usr/share/pixmaps`

polarisnetwork-qt.protocol (KDE)


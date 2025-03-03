#!/bin/bash
# save as update-deps.sh

# Copy your application files
# cp ../build-CodeWizard-Desktop-Release/CodeWizard codewizard/usr/local/bin/
# cp codewizard.desktop codewizard/usr/share/applications/
# cp codewizard.png codewizard/usr/share/icons/hicolor/256x256/apps/

# Generate dependencies
# DEPS=$(dpkg-shlibdeps -O codewizard/usr/local/bin/CodeWizard 2>/dev/null | sed 's/shlibs:Depends=//')

# Update control file with dependencies
# sed -i "/^Description:/i Depends: ${DEPS}" codewizard/DEBIAN/control

# Build the package
dpkg-deb --build codewizard

#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/ecocoin.ico

convert ../../src/qt/res/icons/ecocoin-16.png ../../src/qt/res/icons/ecocoin-32.png ../../src/qt/res/icons/ecocoin-48.png ${ICON_DST}

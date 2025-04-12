#!/bin/bash

BASEDIR="$(cd "$(dirname "$0")" && pwd)"

rm -rf $BASEDIR/builder/glue-lwip/arduino/*
rm -rf $BASEDIR/builder/lwip2-src
rm -rf $BASEDIR/builder/makefiles/Makefile.patches
rm -rf $BASEDIR/builder/patches

cp -rf $BASEDIR/patch/. $BASEDIR/builder/

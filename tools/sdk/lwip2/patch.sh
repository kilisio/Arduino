#!/bin/bash

BASEDIR="$(cd "$(dirname "$0")" && pwd)"

cp -rf $BASEDIR/patch/makefiles/. $BASEDIR/builder/makefiles/
cp -rf $BASEDIR/patch/glue-lwip/. $BASEDIR/builder/glue-lwip/
cp -rf $BASEDIR/patch/lwip2-src/src/include/lwippools.h $BASEDIR/builder/lwip2-src/src/include/

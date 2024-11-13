#!/bin/bash

BASEDIR="$(cd "$(dirname "$0")" && pwd)"

rm -rf $BASEDIR/builder/glue-lwip/arduino/*

cp -rf $BASEDIR/patch/. $BASEDIR/builder/

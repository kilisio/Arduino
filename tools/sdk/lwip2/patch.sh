#!/bin/bash

BASEDIR="$(cd "$(dirname "$0")" && pwd)"

cp -rf $BASEDIR/patch/builder/. $BASEDIR/builder/

```make install```: download, compile, install lwip2

```make latestmaster```: download latest lwip2, compile, install

```make latestupstream```: download latest lwip2 and latest upstream lwIP, compile, install

```make download```: download lwIP-2 builder

```make clean```: clean builder only

glue and lwIP debug options are in builder/glue/gluedebug.h

MSS values are in builder/Makefile.arduino

MSS values in boards.txt are only informative

If first build go to root of project and initialize required submodules
```sh
    git submodule update --init
    cd tools
    python3 get.py
```

Build lwip2
```sh
    rm -rf ./builder/
    make install
    make clean
    ./patch.sh
    make install
```


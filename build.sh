#!/bin/sh

SRC_DIR="src"
JAVA_SRC="java/src_java"
C_FLAGS="-Wall"

build() {
    build_c
    build_java
}

build_c() {
    if [ ! -d "build" ]; 
    then
        mkdir build
        mkdir build/obj
    fi
    find "$SRC_DIR" -print0 | while IFS= read -r -d '' file
    do 
        if [ ! -d "$file" ];
        then
            filename=$(basename -- "$file")
            extension="${filename##*.}"  

            if [ "$extension" = "c" ] && [ "$filename" != "main.c" ];
            then
                gcc "$C_FLAGS" -c -o "" "$file"
                mv "${file%.*}.o" build/obj
            fi
        fi 
    done

    gcc "$C_FLAGS" -o main src/main.c $(find build -type f | xargs echo)
    mv main build
}

build_java() {
    if [ ! -d "java/target" ];
    then
        mkdir java/target
    fi

    find "$JAVA_SRC" -print0 | while IFS= read -r -d '' file
    do 
        if [ ! -d "$file" ];
        then
            filename=$(basename -- "$file")
            extension="${filename##*.}"  

            if [ "$extension" = "java" ];
            then
                javac "$file"
                mv "${file%.*}.class" java/target
            fi
        fi 
    done 

}

run() {
    ./build/main
}

if [ "$1" = "clean" ];
then
    rm -rf build
    rm -rf java/target
    exit 0
fi

if [ "$1" = "build" ];
then
    if [ "$2" = "run" ]; then
        build
        run
    else
        build
    fi
fi


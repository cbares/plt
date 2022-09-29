cmake_minimum_required (VERSION 3.0)

include(ExternalProject)


ExternalProject_Add(libxml2
    GIT_REPOSITORY https://gitlab.gnome.org/GNOME/libxml2.git
    GIT_TAG "v2.10.2"
    PREFIX "${PROJECT_SOURCE_DIR}/extern/libxml2"
    SOURCE_DIR "${PROJECT_SOURCE_DIR}/extern/libxml2-src"
    BINARY_DIR "${PROJECT_SOURCE_DIR}/lib"
    CMAKE_ARGS 
        -D CMAKE_BUILD_TYPE=Release
        -D LIBXML2_WITH_ICONV=OFF
        -D LIBXML2_WITH_LZMA=OFF
        -D LIBXML2_WITH_PYTHON=OFF
        -D LIBXML2_WITH_ZLIB=OFF
    INSTALL_COMMAND ""
)


set(DIA2CODE_SRC_FILE "main.cpp;DiaGram.cpp;GenerateCodeJava.cpp;scan_tree.cpp;GenerateCodePhp.cpp;string2.cpp;umlAttribute.cpp;umlClass.cpp;GenerateCode.cpp;umlClassNode.cpp;GenerateCodeCpp.cpp;umlOperation.cpp;GenerateCodeCSharp.cpp;umlPackage.cpp;parse_diagram.cpp")

foreach(file IN LISTS DIA2CODE_SRC_FILE)
    list(APPEND DIA2CODE_FILES ${PROJECT_SOURCE_DIR}/extern/dia2code-src/src/${file} )
endforeach()


ExternalProject_Add(dia2code
GIT_REPOSITORY https://git.code.sf.net/p/dia2code/git
    GIT_TAG "1.0.0"
    PREFIX "${PROJECT_SOURCE_DIR}/extern/dia2code"
    SOURCE_DIR "${PROJECT_SOURCE_DIR}/extern/dia2code-src"
    BINARY_DIR "${PROJECT_SOURCE_DIR}/bin"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND gcc -xc++
        -I${PROJECT_SOURCE_DIR}/extern/libxml2-src/include
        -I${PROJECT_SOURCE_DIR}/lib/
        -I${PROJECT_SOURCE_DIR}/extern/dia2code-src/src/
        -I${PROJECT_SOURCE_DIR}/extern/dia2code-src/
        -L${PROJECT_SOURCE_DIR}/lib/
        ${DIA2CODE_FILES} -O2 -o ${PROJECT_SOURCE_DIR}/bin/dia2code -lxml2 -lstdc++
    INSTALL_COMMAND ""
    DEPENDS libxml2
)

ExternalProject_Add(jsoncpp
GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
    GIT_TAG "1.9.5"
    PREFIX "${PROJECT_SOURCE_DIR}/extern/jsoncpp"
    SOURCE_DIR "${PROJECT_SOURCE_DIR}/extern/jsoncpp-src"
    BINARY_DIR "${PROJECT_SOURCE_DIR}/extern/jsoncpp-build"
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=release 
        -DBUILD_STATIC_LIBS=ON 
        -DBUILD_SHARED_LIBS=OFF 
        -DARCHIVE_INSTALL_DIR=. 
        -G "Unix Makefiles" ${PROJECT_SOURCE_DIR}/extern/jsoncpp-src
    INSTALL_COMMAND ""
)
win32{
    CONFIG += PLATFORM_WIN
    win32-msvc{
        CONFIG += COMPILER_MSVC
        contains(QT_ARCH, x86_64){
            win32:QMAKE_TARGET.arch = x86_64
        }else{
            win32:QMAKE_TARGET.arch = x86
        }
    }


win32-g++{
    CONFIG += COMPILER_GCC
    contains(QT_ARCH, x86_64){
        win32:QMAKE_TARGET.arch = x86_64
    }else{
        win32:QMAKE_TARGET.arch = x86
    }
}

}

linux{
    CONFIG += PLATFORM_LINUX
    linux-g++{
        CONFIG += COMPILER_GCC
        contains(QT_ARCH, x86_64){
            linux:QMAKE_TARGET.arch = x86_64
        }else{
            linux:QMAKE_TARGET.arch = x86
        }
    }


    linux-clang{
        CONFIG += COMPILER_CLANG
        contains(QT_ARCH, x86_64){
            linux:QMAKE_TARGET.arch = x86_64
        }else{
            linux:QMAKE_TARGET.arch = x86
        }
    }

}

macx{
    CONFIG += PLATFORM_OSX
    macx-clang{
        CONFIG += COMPILER_CLANG
        contains(QT_ARCH, x86_64){
            clang:QMAKE_TARGET.arch = x86_64
        }else{
            clang:QMAKE_TARGET.arch = x86
        }
    }

}

contains(QMAKE_TARGET.arch, x86_64){
    CONFIG += PROCESSOR_x86_64
}else{
    CONFIG += PROCESSOR_x86
}


CONFIG(debug, release|debug){
    CONFIG += BUILD_DEBUG
}else{
    CONFIG += BUILD_RELEASE
}

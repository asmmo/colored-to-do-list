platform_path = platform_path
compiler_path = compiler_path
processor_path = processor_path
build_path = build_path

PLATFORM_WIN{
    platform_path = win
}

PLATFORM_LINUX{
    platform_path = linux
}

PLATFORM_MAC{
    platform_path = mac
}



COMPILER_GCC{
    compiler_path = gcc
}

COMPILER_MSVC{
    compiler_path = msvc
}

COMPILER_CLANG{
    compiler_path = clang
}



PROCESSOR_x86_64{
    processor_path = x64
}

PROCESSOR_x86{
    processor_path = x86
}




Build_DEBUG {
    build_path = debug
} else{
    build_path = release
}

dest_path = $$platform_path/$$compiler_path/$$processor_path/$$build_path

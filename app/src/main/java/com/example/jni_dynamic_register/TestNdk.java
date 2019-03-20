package com.example.jni_dynamic_register;

public class TestNdk {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String getString();
    public static native void diff(String path, String pattern_Path, int file_num);
}


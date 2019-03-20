package com.example.jni_dynamic_register;

public class TestNdk {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String getString();
}


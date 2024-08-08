load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")


cc_library(
    name = "hello_greet",
    srcs = [
        "hello_greet.cpp",
    ],
    hdrs = [
        "hello_greet.h",
    ],
)

cc_binary(
    name = "hello_world",
    srcs = [
        "helloworld.cpp",
    ],
    deps = [
        ":hello_greet",
        "//lib:hello_time",
    ],
    linkopts = [
    ],
    tags = ["no-cache"],
)

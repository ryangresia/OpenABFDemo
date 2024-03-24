load("@rules_cc//cc:defs.bzl", "cc_library")
filegroup(
    name = "include",
    srcs = glob(["include/eigen3/Eigen/**/*", "include/eigen3/Eigen/*"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "eigen",
    hdrs = [":include"],
    strip_include_prefix = "include/eigen3",
    visibility = ["//visibility:public"],
)

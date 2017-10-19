package(default_visibility = ["//visibility:public"])

cc_binary(
  name = "liband_cpp.so",
  srcs = [
    "jni.cc",
  ],
  linkopts = [
    "-llog",
  ],
  linkshared = True,
  linkstatic = True,
)

cc_library(
  name = "native_deps",
  srcs = [
    ":liband_cpp.so",
  ],
)

# https://github.com/bazelbuild/bazel/issues/348
# aar not supported yet.
android_library(
  name = "and_lib",
  srcs = glob([
    "java/**/*.java",
  ]),
  custom_package = "",
  manifest = "AndroidManifest.xml",
  deps = [
    ":native_deps",
    "@android_sdk//com.android.support:support-annotations-25.3.1",
  ],
)

android_binary(
  name = "and_bin",
  srcs = glob([
    "java/**/*.java",
  ]),
  custom_package = "",
  manifest = "AndroidManifest.xml",
  deps = [
    ":native_deps",
    "@android_sdk//com.android.support:support-annotations-25.3.1",
  ],
)

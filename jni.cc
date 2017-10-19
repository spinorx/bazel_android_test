#include <jni.h>
#include <memory>
#include <cstring>
#include <string>

const char* hello = "Hello JNI";

// testing for https://stackoverflow.com/questions/22774009/android-ndk-stdto-string-support
using std::to_string;

extern "C" JNIEXPORT jstring JNICALL
Java_JniTest_hello(JNIEnv *env, jclass clazz) {
  int len = std::strlen(hello);
  jchar *str1;
  str1 = reinterpret_cast<jchar *>(malloc(len * sizeof(jchar)));

  for (int i = 0; i < len; i++) {
    str1[i] = (unsigned char)hello[i];
  }
  jstring result = env->NewString(str1, len);
  free(str1);
  return result;
}

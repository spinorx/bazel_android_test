import android.support.annotation.Keep;

@Keep
public class JniTest {
  static {
    System.loadLibrary("and_cpp");
  }

  public static native String hello();
}

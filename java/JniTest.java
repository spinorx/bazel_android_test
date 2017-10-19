import android.support.annotation.Keep;

@Keep
public class VircorXClient {
  static {
    System.loadLibrary("and_cpp");
  }

  public static native String hello();
}

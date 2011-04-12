package nobleworks.libmpg;

public class MP3Decoder
{
    static
    {
        System.loadLibrary("mpg");
    }

    public static native int[] getSupportedRates();
}
